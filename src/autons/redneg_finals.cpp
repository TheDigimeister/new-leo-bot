#include "main.h"

// red + goldrush
void redneg_finals()
{
    // setup
    chassis.setPose(0, 0, 146);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

    // score ring
    chassis.moveDistance(6.5, 1000);
    arm.move(100);
    pros::delay(800);
    arm.brake();

    // get mogo
    chassis.moveToPoint(-17, 33, 4000, {.forwards = false, .maxSpeed = 80});
    pros::delay(500);
    arm_move = false;
    global_target = 100;
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);

    // get 2 rings
    set_intake_speed(127);
    chassis.turnToPoint(-34, 41, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(-34, 41, 1000, {.minSpeed = 20, .earlyExitRange = 3});
    chassis.turnToPoint(-48, 42.5, 1000, {.minSpeed = 20, .earlyExitRange = 3});
    chassis.moveToPoint(-48, 42.5, 1000, {.minSpeed = 20, .earlyExitRange = 3}, false);
    chassis.moveToPoint(-12, 33.5, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
    set_intake_speed(80);
    chassis.turnToPoint(-36, 28, 1000, {.minSpeed = 20, .earlyExitRange = 3}, false);
    set_intake_speed(127);
    fast_move(-36, 28, 2000, true);

    set_intake_speed(127, false);
    chassis.turnToPoint(-52, -10, 1000);
    chassis.moveToPoint(-52, -10, 1000);
    chassis.moveDistance(40, 700, {.minSpeed = 50});
    chassis.moveDistance(20, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 32, .earlyExitRange = 3}, false);
    chassis.moveDistance(14, 1000);
    chassis.moveDistance(7, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 5, .earlyExitRange = 3}, false);

    // for teamwork

    // // touch bar
    // set_intake_speed(0);
    // chassis.turnToPoint(10, 13, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    // chassis.moveToPoint(10, 13, 2000, {.minSpeed = 5, .earlyExitRange = 3});
    // set_intake_speed(127);
    // pros::Task skills_task2{[=]
    //                         {
    //                             while (top_distance.get_distance() > 50)
    //                                 pros::delay(10);
    //                             pros::delay(500);
    //                             set_intake_speed(0);
    //                         }};
    // // touch bar
    // chassis.turnToHeading(-10, 500, {.maxSpeed = 60});
    // chassis.moveDistance(8, 1000);

    // For finals go to positive corner 2/17/25

    set_intake_speed(0);
    chassis.turnToPoint(10, 13, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(10, 13, 2000, {.minSpeed = 80, .earlyExitRange = 3});
    set_intake_speed(127);
    chassis.moveToPoint(72, -6, 2000, {.minSpeed = 100, .earlyExitRange = 3});
    swiper.set_value(true);
    pros::delay(800);
    set_intake_speed(0);
    chassis.turnToHeading(-55, 2000, {.minSpeed = 100}, false);
    chassis.moveDistance(13, 1000, {.forwards = false, .minSpeed = 65, .earlyExitRange = 2}, false);
    mogo.set_value(false);
    chassis.moveDistance(13, 1000, {.minSpeed = 65, .earlyExitRange = 2}, false);
    chassis.turnToHeading(180, 1000);
}
