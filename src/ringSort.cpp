#include "main.h"

pros::Task *sort_task = nullptr;
pros::Mutex intake_control;
int sorting = 0;
int intake_speed = 0;

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826, -1625, -703, -1164, 5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, -3785, -3395, -3590, 5827, 7261, 6544, 6.000, 0);
pros::vision_signature_s_t MOGO_SIG =
    pros::Vision::signature_from_utility(3, -2897, -2351, -2624, -7927, -7259, -7593, 2.5, 0);
void setup()
{
  vision.set_signature(1, &RED_SIG);
  vision.set_signature(2, &BLUE_SIG);
  vision.set_signature(3, &MOGO_SIG);
  intake.set_encoder_units_all(pros::E_MOTOR_ENCODER_ROTATIONS);
  vision.get_object_count();
  pros::delay(100);
  // sort_thrower.set_value(true);
}

/*
 *return 1 if ready to be tossed
 *return 2 if already tossed 2.37
 *return 0 if none
 */
int ring_tossed(double start)
{
  double dif = fabs(intake.get_position()) - fabs(start);
  // printf("%f\n",dif);
  if (dif >= 2.35)
    return 2;
  else if (dif > 0)
    return 1;
  else
    return 0;
}

void sort(int color_type)
{
  if (sort_task == nullptr)
  {
    sort_task = new pros::Task{[=]
                               {
                                 ring_color.set_integration_time(3);
                                 ring_color.set_led_pwm(100);
                                 intake.set_brake_mode_all(MOTOR_BRAKE_HOLD);

                                 bool color = false;

                                 while (true)
                                 {
                                   // printf("R:%f G:%f B:%f\ distance:%d \n",ring_color.get_rgb().red,ring_color.get_rgb().green,ring_color.get_rgb().blue,ring_color.get_proximity());
                                   // printf("%f\n",ring_color.get_rgb().red-ring_color.get_rgb().blue);
                                   // if(ring_color.get_rgb().red-ring_color.get_rgb().blue > 100 ) color = true;
                                   if (color_type == 1)
                                     if (ring_color.get_hue() > 335 || ring_color.get_hue() < 350)
                                       color = true;
                                   if (color_type == 2)
                                     if (ring_color.get_hue() > 200 && ring_color.get_hue() < 230)
                                       color = true;
                                   if (top_distance.get_distance() < 30 && color)
                                   {
                                     intakemutex.lock();
                                     int prev_intake_speed = intake_speed;
                                     // pros::delay(10);
                                     set_intake_speed(60);
                                     double start = intakerotation.get_position();
                                     arm_move = false;
                                     global_target = 2500;
                                     while (abs(intakerotation.get_position() - abs(start)) <= 60000)
                                       pros::delay(3);
                                     global_target = 100;
                                     intakemutex.unlock();
                                     //  sorting = 1;
                                     //  //  pros::delay(5);
                                     //  sorting = 2;
                                     //  // intake.brake();
                                     //  pros::delay(500);
                                     //  sorting = 0;
                                     //  pros::delay(100);
                                     color = false;
                                     // set_intake_speed(prev_intake_speed);
                                   }
                                   pros::delay(5);
                                 }
                               }};
  }
}
void getring()
{
  pros::Task getringtask{[=]
                         {
                           while (top_distance.get_distance() > 30)
                           {
                             set_intake_speed(90);
                             pros::delay(5);
                           }
                           set_intake_speed(-60);
                           pros::delay(150);
                           set_intake_speed(0);
                         }};
}
void turntomogo()
{

  lemlib::PID mogo_pid(
      0.5, // proportional gain (kP)
      0,   // integral gain (kI)
      3    // derivative gain(kD)
  );
  int error = 0;
  float speed;
  int count = 0;
  while (count <= 40)
  {
    pros::vision_object_s_t rtn = vision.get_by_sig(0, 3);
    error = rtn.y_middle_coord - 70;
    // if(abs(error)<100) error = 0;
    speed = mogo_pid.update(error);
    left.move(speed);
    right.move(-speed);
    if (abs(error) < 10)
      count++;
    pros::delay(10);
  }
  left.brake();
  right.brake();
}
bool mogo_seated()
{
  return mogo_distance.get_distance() < 25;
}

pros::Mutex intake_mutex;
bool antijam = true;
pros::Task *intake_task = nullptr;

void init_intake()
{
  if (intake_task == nullptr)
  {
    intake_task = new pros::Task{[=]
                                 {
                                   int count = 0;
                                   int prev_speed = 0;
                                   while (!pros::Task::notify_take(true, 10))
                                   {
                                     int speed = intake_speed;
                                     bool antijam_temp = antijam;
                                     if (sorting == 0)
                                       intake.move(speed);
                                     else if (sorting == 1)
                                     {
                                       intake.move(0);
                                     }
                                     else if (sorting == 2)
                                       intake.move(-100);
                                     if (speed != prev_speed)
                                       pros::delay(100);
                                     prev_speed = speed;

                                     if (speed > 0 && intake.get_efficiency() < 1 && antijam_temp)
                                     {
                                       count += 1;
                                     }
                                     if (count > 10 && antijam_temp)
                                     {
                                       intake.move(-127);
                                       pros::delay(500);
                                       intake.move(0);
                                       prev_speed = 0;
                                       count = 0;
                                     }
                                   }
                                 }};
  }
}

void set_intake_speed(int speed, bool jam)
{
  // pros::Task intake_task2{[=]
  //                         {
  // intake_mutex.lock();
  intake_speed = speed;
  antijam = jam;
  // intake_mutex.unlock();
  // }};
  // intake_task2.remove();
  // delete &intake_task2;
}

void fast_move(float x, float y, int timeout, bool async = true)
{
  chassis.moveToPoint(x, y, timeout, {.minSpeed = 5, .earlyExitRange = 10});
  chassis.moveToPoint(x, y, timeout, {.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 3}, async);
}

// void init_driver_intake(){
//     pros::Task driver_intake{[=]{
//       while(true){
//         if(master.get_digital(DIGITAL_R1)){
//           intake_control.lock();
//           intake.move(127);
//           intake_control.unlock();
//           // set_intake_speed(127);
//         }
//         else if(master.get_digital(DIGITAL_R2)){
//           intake_control.lock();
//           intake.move(-127);
//           intake_control.unlock();
//           // set_intake_speed(-127);
//         }
//         else{
//           sort_task->notify();
//           intake_control.lock();
//           intake.move(0);
//           intake_control.unlock();
//           // set_intake_speed(0);
//         }
//       }
//     }};
// }

pros::Mutex arm_mutex;
pros::Mutex target_mutex;
int global_target = 0;
bool arm_move = true;

// void arm_to_pos(){
// 	  pros::Task arm_task_0{[=]{
// 		int target;
// 		int pos = arm_control.get_position();
// 		int error = target - pos;
// 		int speed;
// 		bool prevsgn = error>0;
//         while(true){

// 			target_mutex.lock();
// 			target = global_target;
// 			target_mutex.unlock();
// 			pos = arm_control.get_position();
// 			error = target - pos;
// 			speed = error *.03;
// 			if(speed>127) speed = 127;
// 			if(speed<-127) speed = -127;
// 			arm_mutex.lock();
// 			if(!arm_move) arm.move(speed);
// 			arm_mutex.unlock();

// 			// if(prevsgn != (error>0)) break;
// 			prevsgn = (error>=0);
// 			pros::delay(10);
// 		}
// 		arm.brake();

//     }};
// }

void arm_to_pos()
{
  pros::Task arm_task_0{[=]
                        {
                          lemlib::PID arm_pid(.0314, 0, .2);
                          arm_pid.reset();
                          arm.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
                          int target;
                          int pos = arm_control.get_position();
                          int error = target - pos;
                          int prev_error = error;
                          float speed;
                          int count = 0;
                          int prev_target;
                          bool inside = false;
                          while (true)
                          {

                            target = global_target;
                            pos = arm_control.get_position();
                            error = target - pos;
                            if (prev_target != target || arm_move)
                            {
                              count = 0;
                              prev_error = error;
                              inside = false;
                            }
                            prev_target = target;
                            // if(abs(error)<100) error = 0;
                            speed = arm_pid.update(error);
                            if (speed > 127)
                              speed = 127;
                            if (speed < -127)
                              speed = -127;
                            if (count < 50)
                            {
                              if (!arm_move)
                                arm.move(speed);
                              // if(abs(error)<300)
                              if (error * prev_error < 0)
                                inside = true;
                              if (inside)
                                count++;
                            }
                            else
                            {
                              if (!arm_move)
                                arm.brake();
                              inside = false;
                            }
                            prev_error = error;
                            pros::delay(10);
                          }
                        }};
}
// old arm to pos
//  void arm_to_pos()
//  {
//    pros::Task arm_task_0{[=]
//                          {
//                            lemlib::PID arm_pid(.05, 0, .4);
//                            arm_pid.reset();
//                            arm.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
//                            int target;
//                            int pos = arm_control.get_position();
//                            int error = target - pos;
//                            float speed;
//                            int count = 0;
//                            int prev_target;
//                            while (true)
//                            {

//                             // target_mutex.lock();
//                             target = global_target;
//                             // target_mutex.unlock();
//                             if (prev_target != target)
//                             {
//                               count = 0;
//                             }
//                             prev_target = target;
//                             pos = arm_control.get_position();
//                             error = target - pos;
//                             // if(abs(error)<100) error = 0;
//                             speed = arm_pid.update(error);
//                             if (speed > 127)
//                               speed = 127;
//                             if (speed < -127)
//                               speed = -127;
//                             if (count < 50)
//                             {
//                               // arm_mutex.lock();
//                               if (!arm_move)
//                                 arm.move(speed);
//                               // arm_mutex.unlock();
//                               if (abs(error) < 300)
//                                 count++;
//                             }
//                             else
//                             {
//                               // arm_mutex.lock();
//                               if (!arm_move)
//                                 arm.brake();
//                               // arm_mutex.unlock();
//                             }
//                             pros::delay(10);
//                           }
//                         }};
// }