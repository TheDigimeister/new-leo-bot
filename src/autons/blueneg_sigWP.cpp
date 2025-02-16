#include "main.h"

// new bot blue - teamwork
void blueneg_sigWP()
{
    // setup
    chassis.setPose(0, 0, -146);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

    // score ring
    chassis.moveDistance(6.5, 1000);
    arm.move(80);
    pros::delay(800);
    arm.brake();

    // get mogo
    chassis.moveToPoint(17, 33, 4000, {.forwards = false, .maxSpeed = 80});
    pros::delay(500);
    arm_move = false;
    global_target = 100;
    while (!mogo_seated() && chassis.isInMotion())
        pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);

    // get 2 rings
    set_intake_speed(127);
    chassis.turnToPoint(34, 47.5, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(34, 44, 1000, {.minSpeed = 20, .earlyExitRange = 3});
    chassis.turnToPoint(48, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3});
    chassis.moveToPoint(48, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3}, false);
    chassis.moveToPoint(14, 37, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
    set_intake_speed(80);
    chassis.turnToPoint(30, 29, 1000, {.minSpeed = 50, .earlyExitRange = 3}, false);
    set_intake_speed(127);
    fast_move(36, 28, 2000, true);
    // get middle ring
    chassis.turnToPoint(-40.5, 8.5, 2000, {.minSpeed = 50}, false);
    chassis.moveToPoint(-40.5, 8.5, 2000, {.minSpeed = 100});
    set_intake_speed(100);
    // for signature
    pros::delay(600);
    mogo.set_value(false);
    set_intake_speed(110);
    getring();
    // antijamn_intake(0);
    chassis.turnToPoint(-38.5, 23.2, 2000, {.forwards = false, .minSpeed = 70});
    chassis.moveToPoint(-38.5, 23.2, 4000, {.forwards = false, .minSpeed = 90});
    while (!mogo_seated())
        pros::delay(10);
    pros::delay(50);
    mogo.set_value(true);
    // antijamn_intake(110);
    chassis.turnToPoint(-52, 37, 2000, {.minSpeed = 70}, false);
    set_intake_speed(127);
    chassis.moveToPoint(-52, 37, 4000, {.minSpeed = 85});
    chassis.moveToPoint(-15, 42, 4000, {.forwards = false, .minSpeed = 50}, false);
    set_intake_speed(0);
    // set_intake_speed(127, false);
    // chassis.turnToPoint(52, -10, 1000);
    // chassis.moveToPoint(52, -10, 1000);
    // chassis.moveDistance(40, 700, {.minSpeed = 80});
    // chassis.moveDistance(20, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 32, .earlyExitRange = 3}, false);
    // chassis.moveDistance(12, 1000);
    // chassis.moveDistance(7, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 5, .earlyExitRange = 3}, false);

    // // touch bar
    // set_intake_speed(0);
    // chassis.turnToPoint(-10, 13, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    // chassis.moveToPoint(-10, 13, 2000, {.minSpeed = 5, .earlyExitRange = 3});
    // set_intake_speed(127);
    // pros::Task skills_task2{[=]
    //                         {
    //                             while (top_distance.get_distance() > 50)
    //                                 pros::delay(10);
    //                             pros::delay(500);
    //                             set_intake_speed(0);
    //                         }};
    // // touch bar
    // chassis.turnToHeading(10, 500, {.maxSpeed = 60});
    // chassis.moveDistance(8, 1000);
}
// void blue1()
// {
//     // setup
//     chassis.setPose(0, 0, -149);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

//     // score ring
//     chassis.moveDistance(6, 1000);
//     arm.move(127);
//     pros::delay(700);
//     arm.brake();

//     // get mogo
//     chassis.moveToPoint(15, 29, 4000, {.forwards = false, .maxSpeed = 80});
//     pros::delay(500);
//     arm_move = false;
//     global_target = 100;
//     while (!mogo_seated() && chassis.isInMotion())
//         pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     // pros::delay(50);
//     chassis.cancelMotion();
//     left.brake();
//     right.brake();
//     pros::delay(100);

//     // get 2 rings
//     set_intake_speed(127);
//     chassis.swingToPoint(30, 45, DriveSide::RIGHT, 2000, {.maxSpeed = 80, .minSpeed = 5, .earlyExitRange = 10});
//     chassis.turnToPoint(30, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.moveToPoint(30, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.turnToPoint(45, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.moveToPoint(45, 45, 1000, {.minSpeed = 20, .earlyExitRange = 3});

//     chassis.moveToPoint(14, 30, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
//     chassis.turnToPoint(32, 30, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     fast_move(32, 30, 2000, false);

//     chassis.turnToPoint(56, -10, 1000);
//     chassis.moveDistance(36, 2000, {.minSpeed = 5, .earlyExitRange = 3});
//     chassis.moveDistance(40, 700);
//     chassis.moveDistance(10, 1000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3});

//     // 28 -1
//     chassis.turnToPoint(-16, 15, 1000, {.minSpeed = 5, .earlyExitRange = 3});
//     chassis.moveToPoint(-16, 15, 2000, {.minSpeed = 5, .earlyExitRange = 3});
//     global_target = 21000;
//     chassis.moveToPoint(15, 10, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3}, false);
//     arm_move = true;
//     arm.move(0);
//     chassis.moveToPoint(3, 41, 2000);

//     // chassis.moveToPoint(-60,-6,2000);
// }

// old blue 1 dont use
//  void blue1(){
//      //  setup
//      chassis.setPose(0,0,-146);
//      intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//      left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//      right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//      mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     deploy.set_value(true);
//     pros::delay(200);
//     claw.set_value(true);

//     // get mogo
//     chassis.moveToPoint(16, 31,4000,{.forwards = false,.maxSpeed=60});
//     pto.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     // pros::delay(50);
//     chassis.cancelMotion();
//     left.brake();
//     right.brake();
//     deploy.set_value(false);
//     pros::delay(100);

//      //get 2 rings
//     set_intake_speed(127);
//     chassis.swingToPoint(30,43,DriveSide::RIGHT,2000,{.maxSpeed=90, .minSpeed=5, .earlyExitRange = 10});
//     chassis.turnToPoint(30,43,1000);
//     // intake.move(127);
//     chassis.moveToPoint(30,43,2000);
//     chassis.turnToHeading(95,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(18,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(15,2000);

//     // intake.move(0);
//     chassis.turnToHeading(70,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(35,20,2000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(127);
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     fast_move(35,20,2000,true);
//     // intake.move(0);

//     //28 -1
//     // intake.move(0);
//     chassis.turnToPoint(-32,-1,2000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(127);
//     chassis.moveToPoint(-32,-1,2000,{.minSpeed=127,.earlyExitRange = 45});
//     chassis.moveToPoint(-32,-1,4000,{.maxSpeed = 40,.minSpeed=5,.earlyExitRange=3});
//     // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)) pros::delay(10);
//     // chassis.cancelMotion();
//     // intake.move(0);

//     chassis.moveToPoint(7,-1,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(7,38,2000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(0);
//     set_intake_speed(0);
//     chassis.moveToPoint(7,38,2000);

//     // // /22.5 30
//     // intake.move(0);
//     // chassis.turnToPoint(-25,35,2000,{},false);
//     // intake.move(127);
//     // chassis.moveToPoint(-25,35,2000);

//     // // -54 -6
//     // chassis.turnToPoint(-44,-5,4000);
//     // chassis.moveDistance(44,1000);
//     // chassis.moveDistance(20,2000,{.forwards=false});

//     // //26 1.5
//     // chassis.moveToPoint(35,6,4000,{.minSpeed=127,.earlyExitRange = 40});
//     // chassis.moveToPoint(35,6,4000,{.maxSpeed = 40},false);
//     // intake.move(0);
//     // // while(!(vision.get_by_sig(0,1).width < 100 && ringdistancesensor.get_distance()<75)) pros::delay(100);
//     // // chassis.cancelMotion();

//     // // chassis.moveToPoint(72,-10,4000,{.forwards = false},false);
//     // // intake.move(0);
//     // // mobo.set_value(false);
//     // // chassis.moveDistance(10,1500);

//     // swiper.set_value(true);
//     // chassis.turnToPoint(69,-8,2000);
//     // chassis.moveToPoint(69,-8,2000);
//     // chassis.turnToHeading(-45,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     // chassis.moveDistance(20,1000,{.forwards=false},false);
//     // mogo.set_value(false);
//     // pros::delay(200);
//     // chassis.moveDistance(10,1000)
// }
