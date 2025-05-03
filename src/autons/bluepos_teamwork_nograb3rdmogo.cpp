#include "main.h"

// new bot blue + finals
void bluepos_teamwork_nograb3rdmogo()
{
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0, 0, 146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

    // score ring
    chassis.moveDistance(5.5, 1000);
    arm.move(100);
    // while (arm_control.get_position() < 13000)
    //     pros::delay(10);
    // arm.brake();
    pros::delay(700);
    // arm.move(100);
    // pros::delay(500);
    arm.brake();

    chassis.moveToPoint(-16, 32, 4000, {.forwards = false, .maxSpeed = 80});
    pros::delay(500);
    arm_move = false;

    global_target = 100;
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    chassis.cancelMotion();

    // -18 11
    // get 2 ring red
    // chassis.turnToPoint(-18,11,2000,{},false);
    // set_intake_speed(127);
    // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

    set_intake_speed(127);
    // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
    // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(10, 12, 2000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    set_intake_speed(0);
    // chassis.turnToPoint(39,28,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    // chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});

    chassis.turnToPoint(-40, 28, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 5, .earlyExitRange = 3}, false);
    set_intake_speed(127);
    // mogo.set_value(false);
    // set_intake_speed(127);
    chassis.moveToPoint(-40, 28, 2000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    // chassis.waitUntil(20);
    // pros::Task red_pos_task{[=]
    //     {
    //         while(distance.get_distance()>100) pros::delay(10);
    //         set_intake_speed(0);
    //     }};
    // // fast_move(38,30,2000,false);
    // chassis.moveDistance(10,1000,{.forwards=false},false);
    // mogo.set_value(true);

    // chassis.moveDistance(10,1000);

    // chassis.turnToPoint(42,45.5,1000,{.forwards=false},false);
    // chassis.moveToPoint(42,45.5,4000,{.forwards = false,.maxSpeed=70});
    // while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    // pros::delay(50);
    // mogo.set_value(false);
    // chassis.cancelMotion();

    // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
    // chassis.turnToPoint(38,-4,1000,{.minSpeed=5, .earlyExitRange=3},false);
    // chassis.moveToPoint(38,-4,2000,{.minSpeed=5, .earlyExitRange=3});
    // chassis.waitUntil(8);
    // set_intake_speed(-127);
    // chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
    // fast_move(38,0,2000,true);
    set_intake_speed(0);
    chassis.turnToPoint(-49, -2, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    chassis.moveToPoint(-49, -2, 2000, {.minSpeed = 5, .earlyExitRange = 3});
    set_intake_speed(127);
    // chassis.swingToHeading(135,lemlib::DriveSide::LEFT,1000,{.minSpeed=20,.earlyExitRange=10});
    chassis.turnToHeading(-153, 1000);
    set_intake_speed(127, false);
    chassis.moveDistance(40, 1000, {.minSpeed = 65});
    chassis.moveDistance(20, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 32, .earlyExitRange = 3}, false);
    // intake_lift.set_value(true);
    // chassis.moveDistance(8,1000,{.maxSpeed = 60});
    // chassis.moveDistance(15,1000,{.forwards=false,.maxSpeed=60,.minSpeed=5,.earlyExitRange=3});
    // intake_lift.set_value(false);
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

    // chassis.moveDistance(10, 1000);
    // chassis.moveDistance(10, 1000, {.forwards = false});
    swiper.set_value(true);
    chassis.turnToHeading(-130, 1000);
    chassis.moveDistance(16, 1000);
    chassis.turnToHeading(45, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    pros::delay(300);
    swiper.set_value(false);
    chassis.moveDistance(10, 1000, {.forwards = false}, false);
    // set_intake_speed(-127);
    mogo.set_value(false);
    chassis.moveDistance(10, 1000, {.minSpeed = 90, .earlyExitRange = 3});
    chassis.turnToPoint(-8.15, 41, 1000, {.minSpeed = 20});
    global_target = 20000;
    chassis.moveToPoint(2, 46, 1000, {.minSpeed = 100});
    chassis.moveDistance(11, 1000, {.minSpeed = 50});
    // pros::delay(200);
    // swiper.set_value(true);
    // chassis.moveDistance(16,1000);
    // chassis.turnToHeading(55,1000,{.minSpeed=5, .earlyExitRange=3},false);
    // set_intake_speed(0);
    // swiper.set_value(false);
    // chassis.turnToPoint(42,25,1000,{.minSpeed=5,.earlyExitRange=3});
    // chassis.moveToPoint(42,25,2000,{.minSpeed=5, .earlyExitRange=3});
    // chassis.waitUntil(10);
    // mogo.set_value(false);
    // chassis.turnToHeading(180,1000);
}

// void blue5(){
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     chassis.setPose(0,0,149);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

//     //score ring
//     chassis.moveDistance(6,1000);
//     arm.move(127);
//     pros::delay(700);
//     arm.brake();

//     chassis.moveToPoint(-16, 32,4000,{.forwards = false,.maxSpeed=80});
//     pros::delay(500);
//     arm_mutex.lock();
//     arm_move=false;
//     arm_mutex.unlock();

//     target_mutex.lock();
//     global_target=100;
//     target_mutex.unlock();
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     chassis.cancelMotion();

//     // -18 11
//     //get 2 ring red
//     // chassis.turnToPoint(-18,11,2000,{},false);
//     // set_intake_speed(127);
//     // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

//     set_intake_speed(127);
//     // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
//     // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
//     chassis.moveToPoint(12,12,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(-42,30,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
//     chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=5});

//     chassis.turnToPoint(-38,30,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
//     // mogo.set_value(false);
//     // set_intake_speed(127);
//     chassis.moveToPoint(-38,30,2000);
//     // chassis.moveDistance(10,1000,{.forwards=false},false);
//     // mogo.set_value(true);
//     // set_intake_speed(-127);
//     // chassis.moveDistance(10,1000);

//     // chassis.turnToPoint(-44,44,2000,{.forwards=false},false);
//     // chassis.moveToPoint(-44,44,4000,{.forwards = false,.maxSpeed=70});
//     // while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     // pros::delay(50);
//     // mogo.set_value(false);
//     // chassis.cancelMotion();

//     chassis.turnToPoint(-39,-4,1000,{.minSpeed=5, .earlyExitRange=3},false);
//     chassis.moveToPoint(-39,-4,2000,{.minSpeed=5, .earlyExitRange=3});
//     chassis.waitUntil(8);
//     set_intake_speed(-127);
//     chassis.moveDistance(9,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});

//     chassis.turnToPoint(-46,-5,1000,{},false);
//     set_intake_speed(127);
//     chassis.moveDistance(40,1000);
//     // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

//     chassis.moveDistance(15,1000,{.forwards=false, .minSpeed=5, .earlyExitRange=3},false);
//     pros::delay(1000);
//     set_intake_speed(0);
//     swiper.set_value(true);
//     chassis.moveDistance(10,1000,{.minSpeed=5, .earlyExitRange=3});
//     chassis.turnToHeading(-235,1000,{.minSpeed=5, .earlyExitRange=3},false);
//     swiper.set_value(false);
//     chassis.turnToPoint(-40,28,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(-40,28,2000,{.minSpeed=5, .earlyExitRange=3});

//     chassis.waitUntil(8);
//     mogo.set_value(false);
//     chassis.turnToHeading(180,1000);

//     // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
//     // chassis.turnToPoint(-53,-4,2000,{.minSpeed=5,.earlyExitRange=3});
//     // set_intake_speed(127);
//     // swiper.set_value(true);
//     // chassis.moveToPoint(-53,-4,2000);
//     // chassis.turnToHeading(145,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     // left.move(127);
//     // right.move(-127);
//     // pros::delay(50);
//     // left.move(0);
//     // right.move(0);
//     // set_intake_speed(127);
//     // swiper.set_value(false);
//     // chassis.moveDistance(15,1000);
//     // while(!(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     // chassis.cancelMotion();
//     // chassis.moveToPoint(0,38,4000,{},false);
//     // set_intake_speed(0);
//     // // // chassis.turnToHeading(0,1000);
//     // // // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
//     // // // chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
// }

// //4 ring 3 goal +
// void blue5(){
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     chassis.setPose(0,0,146);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(true);

//     //score ring
//     chassis.moveDistance(7,1000);
//     arm.move(127);
//     pros::delay(700);
//     arm.brake();

//     chassis.moveToPoint(-15, 31,4000,{.forwards = false,.maxSpeed=80});
//     pros::delay(500);
//     arm_mutex.lock();
//     arm_move=false;
//     arm_mutex.unlock();

//     target_mutex.lock();
//     global_target=100;
//     target_mutex.unlock();
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();

//     // -18 11
//     //get 2 ring red
//     // chassis.turnToPoint(-18,11,2000,{},false);
//     // set_intake_speed(127);
//     // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

//     set_intake_speed(127);
//     // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
//     // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
//     chassis.moveToPoint(12,12,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(-42,30,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
//     chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=5});

//     chassis.turnToPoint(-42,30,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
//     // mogo.set_value(false);
//     // set_intake_speed(127);
//     chassis.moveToPoint(-42,30,2000);
//     chassis.moveDistance(10,1000,{.forwards=false},false);
//     mogo.set_value(true);
//     set_intake_speed(-127);
//     chassis.moveDistance(10,1000);

//     chassis.turnToPoint(-44,44,2000,{.forwards=false},false);
//     chassis.moveToPoint(-44,44,4000,{.forwards = false,.maxSpeed=70});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();

//     fast_move(-38,-4,2000,true);
//     chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
//     // fast_move(38,0,2000,true);

//     chassis.turnToPoint(-46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
//     left.brake();
//     right.brake();
//     set_intake_speed(127);
//     chassis.moveDistance(40,1000);
//     // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

//     chassis.moveToPoint(-5,41,3000,{.forwards=false});
//     chassis.waitUntil(25);
//     set_intake_speed(0);
//     target_mutex.lock();
//     global_target=6000;
//     target_mutex.unlock();
//     while(chassis.isInMotion()) pros::delay(10);
//     arm_mutex.lock();
//     arm_move=true;
//     arm_mutex.unlock();
//     arm.move(0);

//     // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
//     // chassis.turnToPoint(-53,-4,2000,{.minSpeed=5,.earlyExitRange=3});
//     // set_intake_speed(127);
//     // swiper.set_value(true);
//     // chassis.moveToPoint(-53,-4,2000);
//     // chassis.turnToHeading(145,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     // left.move(127);
//     // right.move(-127);
//     // pros::delay(50);
//     // left.move(0);
//     // right.move(0);
//     // set_intake_speed(127);
//     // swiper.set_value(false);
//     // chassis.moveDistance(15,1000);
//     // while(!(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     // chassis.cancelMotion();
//     // chassis.moveToPoint(0,38,4000,{},false);
//     // set_intake_speed(0);
//     // // // chassis.turnToHeading(0,1000);
//     // // // chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
//     // // // chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
// }