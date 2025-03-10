#include "main.h"

// red + goldrush
void redpos_goldrush()
{
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(21.9475, 0.0854, 12.49);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

    // score ring
    chassis.moveToPoint(35, 40, 3000, {.minSpeed = 120, .earlyExitRange = 1.5});
    // getring();
    pros::delay(503);
    arm.move(127);
    // while (fabs(arm_control.get_position() - 21450) > 1500)
    //     pros::delay(10);
    arm_move = false;
    global_target = 22800;
    pros::delay(150);
    swiper.set_value(true);
    pros::delay(150);
    global_target = 28000;
    chassis.moveToPoint(16, 32, 4000, {.forwards = false, .maxSpeed = 80});
    pros::delay(300);
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

    chassis.turnToPoint(40, 28, 1000, {.earlyExitRange = 3}, false);
    set_intake_speed(127);
    chassis.moveToPoint(40, 28, 2000, {.minSpeed = 5, .earlyExitRange = 3}, false);
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
    chassis.turnToPoint(49, -2, 1000, {.minSpeed = 5, .earlyExitRange = 3}, false);
    chassis.moveToPoint(49, -2, 2000, {.minSpeed = 5, .earlyExitRange = 3});
    set_intake_speed(127);
    // chassis.swingToHeading(135,lemlib::DriveSide::LEFT,1000,{.minSpeed=20,.earlyExitRange=10});
    chassis.turnToHeading(135, 1000);
    set_intake_speed(127, false);
    chassis.moveDistance(40, 1000, {.minSpeed = 50});
    chassis.moveDistance(25, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 32, .earlyExitRange = 3}, false);
    // intake_lift.set_value(true);
    // chassis.moveDistance(8,1000,{.maxSpeed = 60});
    // chassis.moveDistance(15,1000,{.forwards=false,.maxSpeed=60,.minSpeed=5,.earlyExitRange=3});
    // intake_lift.set_value(false);
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

    // chassis.moveDistance(10, 1000);
    // chassis.moveDistance(10, 1000, {.forwards = false});
    swiper.set_value(true);
    chassis.turnToHeading(130, 1000);
    chassis.moveDistance(21, 1000);
    set_intake_speed(127);
    chassis.turnToHeading(0, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    pros::delay(450);
    set_intake_speed(0);
    chassis.moveDistance(15, 1000, {}, false);
    // set_intake_speed(-127);
    mogo.set_value(false);
    // touch ladder
    chassis.turnToPoint(8.15, 41, 1000, {.minSpeed = 20});
    global_target = 20000;
    chassis.moveToPoint(-2, 46, 1000, {.minSpeed = 100});
    chassis.moveDistance(6, 1000, {.minSpeed = 50});
}
