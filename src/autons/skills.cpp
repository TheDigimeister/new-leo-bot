#include "main.h"

void skills()
{
    // set up
    chassis.setPose(-12.5, 5, 133.14);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);

    // score preload
    arm.move(127);
    pros::delay(700);
    arm.brake();

    // get mogo 1
    chassis.moveDistance(20, 1000, {.forwards = false, .maxSpeed = 80});
    arm.move(-50);
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(100);

    // mogo 1 move arm back to start position
    //  arm_mutex.lock();
    arm_move = false;
    // arm_mutex.unlock();
    // target_mutex.lock();
    global_target = 100;
    // target_mutex.unlock();

    // mogo 1 get ring 1
    chassis.turnToPoint(-26, 40, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    set_intake_speed(127);
    fast_move(-26, 40, 2000, false);

    // mogo 1 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(-43, 60, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    fast_move(-43, 60, 1000, true);
    // mogo 1 move arm to load ring
    //  arm_mutex.lock();
    arm_move = false;
    // arm_mutex.unlock();
    // target_mutex.lock();
    global_target = 2600;
    // target_mutex.unlock();
    // mogo 1 get ring 2 move to ring
    set_intake_speed(127, false);
    fast_move(-52.5, 95, 1000, true);

    // mogo 1 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task1{[=]
                            {
                                int count = 0;
                                while (top_distance.get_distance() > 50)
                                {
                                    pros::delay(10);
                                }
                                pros::delay(600);
                                set_intake_speed(-10);
                                arm_move = true;
                                pros::delay(100);
                                set_intake_speed(127, false);
                                pros::delay(150);
                                set_intake_speed(0);
                                arm.move(127);
                                pros::delay(150);
                                arm_move = false;
                                // target_mutex.lock();
                                global_target = 7000;
                            }};

    // mogo 1 move to stake
    chassis.moveToPoint(-47, 65, 2000, {.forwards = false}, false);
    chassis.turnToHeading(-88.6, 1000);
    chassis.moveDistance(50, 2000, {.maxSpeed = 60});
    set_intake_speed(127);
    chassis.waitUntil(15);
    // target_mutex.lock();
    global_target = 18000;
    // target_mutex.unlock();
    int count = 0;
    while (arm_control.get_position() < 11000 && chassis.isInMotion())
        pros::delay(10);
    while (chassis.isInMotion())
    {
        if (count > 30)
        {
            chassis.cancelMotion();
            break;
        }
        count += 1;
        pros::delay(10);
    }

    // mogo 1 back away from stake and move arm back to start pos
    // chassis.moveDistance(5, 1000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1});
    // chassis.moveDistance(5, 1000, {.minSpeed = 30, .earlyExitRange = 1});
    chassis.moveDistance(15, 1000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3}, false);
    // target_mutex.lock();
    // arm.move(127);
    // pros::delay(500);
    // arm.move(0);
    global_target = 15000;
    // target_mutex.unlock();

    // mogo 1 get 3 rings in a line
    chassis.turnToPoint(-47.5, 5, 1000, {.minSpeed = 3, .earlyExitRange = 5});
    set_intake_speed(127);
    chassis.moveToPoint(-47.5, 5, 2000, {.minSpeed = 60, .earlyExitRange = 20});
    chassis.moveToPoint(-47.5, 5, 2000, {.maxSpeed = 40}, false);

    // mogo 1 get last ring and set up to drop off mogo
    // chassis.moveToPose(-62, 23, 15, 2000, {.lead = .5}, false);
    chassis.moveToPoint(-62, 23, 2000, {.minSpeed = 10}, false);
    chassis.turnToHeading(7, 1000);
    // mogo 1 score mogo
    chassis.moveDistance(16, 1000, {.forwards = false}, false);
    set_intake_speed(-127);
    mogo.set_value(false);
    global_target = 50;
    pros::delay(200);
    set_intake_speed(0);
    // mogo 1 move away from corner
    chassis.moveDistance(9, 1000, {.minSpeed = 5, .earlyExitRange = 3});

    // get new mogo 2
    chassis.turnToPoint(33, 17, 1000, {.forwards = false});
    chassis.moveToPoint(33, 17, 4000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 40});
    pros::Task getridofring{[=]
                            {
                                arm_move = true;
                                arm.move(127);
                                pros::delay(700);
                                arm.move(-127);
                                pros::delay(700);
                                arm.move(0);
                                arm_move = false;
                                global_target = 50;
                            }};
    chassis.moveToPoint(33, 17, 3000, {.forwards = false, .maxSpeed = 70});
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    pros::delay(200);
    mogo.set_value(true);
    chassis.cancelMotion();

    // mogo 2 get 1st ring
    chassis.turnToPoint(27, 40, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    set_intake_speed(127);
    fast_move(27, 40, 2000, false);

    // mogo 2 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(45, 64, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    fast_move(40, 64, 1000, true);
    // mogo 2 move arm to load ring
    //  arm_mutex.lock();
    arm_move = false;
    // arm_mutex.unlock();
    // target_mutex.lock();
    global_target = 2600;
    // target_mutex.unlock();
    // mogo 2 get ring 2 move to ring
    set_intake_speed(127, false);
    fast_move(45, 95, 1000, true);

    // mogo 2 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task2{[=]
                            {
                                int count = 0;
                                while (top_distance.get_distance() > 50)
                                {
                                    pros::delay(10);
                                }
                                pros::delay(600);
                                set_intake_speed(-10);
                                arm_move = true;
                                pros::delay(100);
                                set_intake_speed(127, false);
                                pros::delay(150);
                                set_intake_speed(0);
                                arm.move(127);
                                pros::delay(150);
                                arm_move = false;
                                // target_mutex.lock();
                                global_target = 7000;
                            }};

    // mogo 2 move to stake
    chassis.moveToPoint(43, 72, 2000, {.forwards = false}, false);
    chassis.turnToHeading(91.3, 1000);
    chassis.moveDistance(60, 2000, {.maxSpeed = 60});
    set_intake_speed(127);
    chassis.waitUntil(14);
    // target_mutex.lock();
    global_target = 18000;
    // target_mutex.unlock();
    count = 0;
    while (arm_control.get_position() < 11000 && chassis.isInMotion())
        pros::delay(10);
    while (chassis.isInMotion())
    {
        if (count > 30)
        {
            chassis.cancelMotion();
            break;
        }
        count += 1;
        pros::delay(10);
    }
    // chassis.moveDistance(5, 1000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1});
    // chassis.moveDistance(5, 1000, {.minSpeed = 30, .earlyExitRange = 1});
    // mogo 2 back away from stake and move arm back to start pos
    chassis.moveDistance(15, 1000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3}, false);
    // target_mutex.lock();
    global_target = 15000;
    // target_mutex.unlock();

    // mogo 2 get 3 rings in a line
    set_intake_speed(127);
    chassis.turnToPoint(48, 7, 1000, {.minSpeed = 3, .earlyExitRange = 5});
    chassis.moveToPoint(48, 7, 2000, {.minSpeed = 40, .earlyExitRange = 30});
    chassis.moveToPoint(48, 7, 2000, {.maxSpeed = 40}, false);

    // mogo 2 get last ring and set up to drop off mogo
    // chassis.moveToPose(62, 25, -15, 3000, {.lead = .5}, false);
    chassis.moveToPoint(62, 25, 3000, {.minSpeed = 10}, false);
    // mogo 2 score mogo
    chassis.turnToHeading(-14, 1000);
    chassis.moveDistance(18, 1000, {.forwards = false}, false);
    set_intake_speed(-127);
    mogo.set_value(false);
    global_target = 50;
    pros::delay(200);
    set_intake_speed(0);
    // mogo 2 move away from corner
    chassis.moveDistance(5, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    // target_mutex.lock();
    global_target = 100;
    // target_mutex.unlock();

    // mogo 3 go through center and get ring 1 & 2
    chassis.turnToPoint(-25, 85, 1000);
    set_intake_speed(80);
    chassis.moveToPoint(-25, 85, 5000);
    while (top_distance.get_distance() > 50 && chassis.isInMotion())
        pros::delay(10);
    set_intake_speed(0);
    // while(chassis.getPose().y<85 &&chassis.isInMotion()) pros::delay(10);
    chassis.moveToPoint(-33, 93.5, 2000, {.minSpeed = 50, .earlyExitRange = 2});
    // put ring in arm
    //  target_mutex.lock();
    global_target = 2600;
    pros::delay(200);
    // target_mutex.unlock();
    set_intake_speed(127, false);
    while (top_distance.get_distance() > 50)
        pros::delay(10);
    pros::delay(500);
    // target_mutex.lock();
    global_target = 15000;
    // target_mutex.unlock();
    set_intake_speed(-60);
    while (arm_control.get_position() < 3600)
        pros::delay(10);
    // mogo 3 intake 2nd ring
    chassis.turnToHeading(-25, 1000);
    chassis.moveDistance(8.7, 1000);
    set_intake_speed(127);
    pros::Task skills_task3{[=]
                            {
                                while (true)
                                {
                                    if (pros::Task::notify_take(true, 10))
                                        break;
                                    if (distance.get_distance() < 100 || top_distance.get_distance() < 100)
                                    {
                                        set_intake_speed(-60);
                                        pros::delay(150);
                                        set_intake_speed(0);
                                        break;
                                    }
                                }
                            }};

    // get mogo 3
    chassis.turnToPoint(-2.5, 118, 1000, {.forwards = false});
    chassis.moveToPoint(-2.5, 118, 4000, {.forwards = false, .minSpeed = 5});
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    mogo.set_value(true);
    left.brake();
    right.brake();
    skills_task3.notify();
    // chassis.moveDistance(10, 1000);
    // mogo 3 face alliance stake
    chassis.moveDistance(5, 1000);
    chassis.turnToHeading(2.5, 2000, {}, false);
    set_intake_speed(127);
    // mogo 3 score on alliance stake
    chassis.moveDistance(50, 1000, {.maxSpeed = 70});
    chassis.moveDistance(6.5, 1000, {.forwards = false});
    chassis.waitUntil(5);
    arm_move = true;
    arm.move(127);
    set_intake_speed(-50);
    set_intake_speed(127);

    // mogo 3 get 2nd ring that dropped in front of alliance stake
    chassis.moveDistance(12, 1000, {.forwards = false, .minSpeed = 60, .earlyExitRange = 3}, false);
    arm_move = false;
    global_target = 6001;
    // get another ring
    // chassis.turnToPoint(-45, 114, 1000);
    // chassis.moveToPoint(-45, 114, 3000, {.minSpeed = 80});
    // set_intake_speed(127);
    // chassis.moveToPoint(2, 107, 3000, {.forwards = false, .minSpeed = 80});
    // set_intake_speed(127);
    // mogo 3 get ring on far side
    // mogo 3 move to 4th ring
    chassis.turnToPoint(23, 95, 1000, {.minSpeed = 3, .earlyExitRange = 5});
    // fast_move(8,107,2000,true);
    fast_move(23, 95, 2000, true);

    // mogo 3 get 5th ring
    chassis.turnToPoint(44, 127, 1000, {.minSpeed = 3, .earlyExitRange = 5});
    fast_move(44, 118, 2000, true);
    // mogo 3 get 6th ring
    chassis.turnToHeading(0, 1000, {.minSpeed = 5});
    chassis.moveDistance(9, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    pros::delay(150);
    chassis.moveDistance(9, 1000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(56.3, 95, 3000, {.forwards = false});
    chassis.turnToHeading(5.58, 1000);
    set_intake_speed(127, false);
    chassis.moveDistance(12, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    // mogo 3 swipe corner
    // chassis.turnToHeading(20, 1000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 5, .earlyExitRange = 3}, false);
    swiper.set_value(true);
    pros::Task skills_task4{[=]
                            {
                                while (true)
                                {
                                    if (pros::Task::notify_take(true, 10))
                                        break;
                                    if (top_distance.get_distance() < 50)
                                    {
                                        set_intake_speed(127);
                                        pros::delay(600);
                                        set_intake_speed(0);
                                        break;
                                    }
                                }
                            }};
    // pros::delay(500);
    // set_intake_speed(0);
    chassis.moveDistance(22, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.turnToHeading(210, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE});
    left.move(127);
    right.move(-127);
    pros::delay(100);
    // mogo 3 score mogo
    chassis.moveDistance(15, 500, {.forwards = false});
    mogo.set_value(false);
    chassis.moveDistance(13, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    skills_task4.notify();
    set_intake_speed(127);
    swiper.set_value(false);

    // push mogo 4
    fast_move(-26, 126, 2000, true);
    set_intake_speed(-127);
    chassis.turnToHeading(285, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.moveDistance(43, 1500, {.minSpeed = 127}, false);
    set_intake_speed(60);
    chassis.moveDistance(10, 1000, {.forwards = false}, false);

    // hang
    chassis.turnToPoint(-26, 91, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
    chassis.moveToPoint(-26, 91, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3});
    // target_mutex.lock();
    global_target = 22000;
    // target_mutex.unlock();
    set_intake_speed(0);
    chassis.turnToHeading(313, 1000, {.minSpeed = 20, .earlyExitRange = 3});
    chassis.moveDistance(50, 1700, {.forwards = false, .maxSpeed = 100, .minSpeed = 65}, false);
    left.move(127);
    right.move(127);
    arm.move(-127);
    pros::delay(100);
    left.move(0);
    right.move(0);
    pros::delay(500);
    arm.move(0);
    global_target = 0;
    // left.move(127);
    // right.move(127);
    // pros::delay(150);
    // left.move(0);
    // right.move(0);
    return;
    // -9 127 285
}

// void skills(){
//     init_intake();
//     pros::delay(1000);
//     set_intake_speed(127);
//     pros::delay(2000);
//     set_intake_speed(0);
//     pros::delay(2000);
//     set_intake_speed(127);
// }