#include "main.h"
void bluepos_finals_grab3rdmogo()
{
    // new bot blue - finals 6 ring
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0, 0, 146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(false);

// score ring
#pragma region ScoreAlliance
    // comment out if alliance scores alliance
    chassis.moveDistance(5.5, 1000);
    arm.move(100);
    // while (arm_control.get_position() < 13000)
    //     pros::delay(10);
    // arm.brake();
    pros::delay(700);
    // arm.move(100);
    // pros::delay(500);
    arm.brake();
#pragma endregion ScoreAlliance
    // get mogo
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
    chassis.turnToHeading(-135, 1000);
    set_intake_speed(127, false);
    chassis.moveDistance(40, 1000, {.minSpeed = 80});
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
    getring();
    chassis.turnToHeading(45, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    pros::delay(300);
    swiper.set_value(false);
    chassis.moveDistance(10, 1000, {.forwards = false}, false);
    // set_intake_speed(-127);
    mogo.set_value(false);
    // pros::delay(200);
    chassis.turnToPoint(-44.5, 18, 1000, {.minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(-44.5, 18, 2000, {.minSpeed = 30, .earlyExitRange = 3});
    // set_intake_speed(127);
    chassis.waitUntil(12);
    mogo.set_value(false);
    chassis.turnToHeading(-184, 1000, {}, false);
    // turntomogo();
    chassis.moveDistance(11, 1000, {.forwards = false}, false);
    if (mogo_seated())
    {
        mogo.set_value(true);
        set_intake_speed(127);
    }
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
// void bluepos_finals_grab3rdmogo()
// {
//     // setup
//     chassis.setPose(0, 0, -146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

//     // score ring
//     //  chassis.moveDistance(7,1000);
//     //  arm.move(127);
//     //  pros::delay(700);
//     //  arm.brake();

//     // get mogo
//     chassis.moveToPoint(16.5, 29, 4000, {.forwards = false, .maxSpeed = 80});
//     pros::delay(500);
//     arm_mutex.lock();
//     arm_move = false;
//     arm_mutex.unlock();

//     target_mutex.lock();
//     global_target = 100;
//     target_mutex.unlock();
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
//     chassis.swingToPoint(30, 41, DriveSide::RIGHT, 2000, {.maxSpeed = 80, .minSpeed = 5, .earlyExitRange = 10});
//     chassis.turnToPoint(30, 41, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.moveToPoint(30, 41, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.turnToPoint(48, 41, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.moveToPoint(48, 41, 1000, {.minSpeed = 20, .earlyExitRange = 3});

//     chassis.moveToPoint(14, 28, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
//     chassis.turnToPoint(36, 26, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     fast_move(36, 26, 2000, true);

//     chassis.turnToPoint(48, -10, 1000, {.minSpeed = 20, .earlyExitRange = 3});
//     chassis.moveDistance(40, 2000, {.minSpeed = 5, .earlyExitRange = 3});
//     chassis.moveDistance(40, 700);
//     chassis.moveDistance(10, 1000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3});

//     // 28 -1
//     //  target_mutex.lock();
//     //  global_target=20000;
//     //  target_mutex.unlock();
//     chassis.turnToPoint(-20, 15, 1000, {.minSpeed = 5, .earlyExitRange = 3});
//     chassis.moveToPoint(-20, 15, 2000, {.minSpeed = 5, .earlyExitRange = 3});
//     pros::Task skills_task2{[=]
//                             {
//                                 while (top_distance.get_distance() > 100)
//                                     pros::delay(10);
//                                 pros::delay(500);
//                                 set_intake_speed(0);
//                             }};
//     // chassis.moveToPoint(16,10,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false);
//     // arm_mutex.lock();
//     // arm_move=true;
//     // arm_mutex.unlock();
//     // arm.move(0);
//     // chassis.moveToPoint(4,35,2000);

//     chassis.moveToPoint(-60, -6, 2000);
// }

// //blue finals
// void blue3(){
//     // setup
//     chassis.setPose(0,0,-146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     deploy.set_value(true);
//     claw.set_value(true);
//     pros::delay(200);

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

//     //get 2 rings
//     set_intake_speed(127);
//     chassis.swingToPoint(30,42,DriveSide::RIGHT,2000,{.maxSpeed=80, .minSpeed=5, .earlyExitRange = 10});
//     chassis.turnToPoint(30,42,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(30,42,1000,{});
//     chassis.turnToPoint(46,42,1000,{.minSpeed=50,.earlyExitRange=3});
//     chassis.moveToPoint(46,42,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToHeading(95,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(18,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(15,2000);

//     chassis.turnToHeading(80,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(30,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(37,25,1000,{.minSpeed=20,.earlyExitRange=3});
//     fast_move(37,25,2000,true);

//     //with bar code
//     chassis.turnToPoint(-20,8,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(-20,8,2000,{.minSpeed=5,.earlyExitRange=35});
//     chassis.moveToPoint(-20,8,2000,{.maxSpeed=30,.minSpeed=5,.earlyExitRange=25});
//     chassis.cancelMotion();
//     left.brake();
//     right.brake();
//     pros::delay(500);
//     fast_move(-20,8,2000,true);

//     //no bar code
//     // chassis.turnToPoint(-25,-2,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveToPoint(-25,-2,2000,{.minSpeed=127,.earlyExitRange = 45});
//     // chassis.moveToPoint(-25,-2,4000,{.maxSpeed = 40,.minSpeed=5,.earlyExitRange=3},false);

//     chassis.moveToPoint(-71,8,2000);
//     chassis.turnToHeading(-155,1000);
//     chassis.moveDistance(20,1000);
//     swiper.set_value(true);
//     set_intake_speed(0);
//     // chassis.turnToHeading(135,1000);
//     // swiper.set_value(true);
//     // chassis.moveDistance(10,1000);
//     chassis.turnToHeading(25,1000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     left.brake();
//     right.brake();
//     pros::delay(100);
//     chassis.turnToHeading(25,1000,{.minSpeed=5,.earlyExitRange=3});
//     mogo.set_value(false);
//     swiper.set_value(false);
//     set_intake_speed(-127);
//     chassis.moveDistance(20,1000,{.forwards=false,.maxSpeed=60},false);
//     set_intake_speed(0);
//     chassis.moveDistance(10,1000);
// }

// void blue3(){
//     //  setup
//     chassis.setPose(0,0,-146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     claw.set_value(true);
//     pros::delay(200);
//     deploy.set_value(true);

//     // get mogo
//     chassis.moveToPoint(15, 31,4000,{.forwards = false,.maxSpeed=60});
//     intake.move(-127);
//     pros::delay(300);
//     intake.move(0);
//     deploy.set_value(false);
//     pto.set_value(false);

//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     left.move(127);
//     right.move(127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);

//     //get 2 rings
//     chassis.swingToPoint(30,43,DriveSide::RIGHT,2000,{.maxSpeed=80});
//     intake.move(127);
//     chassis.moveToPoint(30,43,2000);
//     chassis.turnToHeading(93,1000);
//     chassis.moveDistance(15,2000);
//     // chassis.moveDistance(15,2000);

//     // intake.move(0);
//     chassis.turnToHeading(70,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(30,11,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     // intake.move(127);
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     chassis.moveToPoint(30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     pros::delay(500);
//     chassis.cancelMotion();
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
//     pros::delay(500);
//     chassis.moveToPoint(30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(0);

//     //28 -1
//     // intake.move(0);
//     chassis.turnToPoint(-32,-1,2000,{.minSpeed=5,.earlyExitRange=3});
//     // intake.move(127);
//     chassis.moveToPoint(-32,-1,2000,{.minSpeed=127,.earlyExitRange = 40});
//     chassis.moveToPoint(-32,-1,4000,{.maxSpeed = 40},false);
//     // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)) pros::delay(10);
//     // chassis.cancelMotion();
//     // intake.move(0);

//     chassis.moveToPoint(-55,-1,2000);
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

// void blue3(){
//     //  setup
//     chassis.setPose(0,0,-146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     deploy.set_value(true);
//     claw.set_value(true);
//     pros::delay(200);

//     // get mogo
//     chassis.moveToPoint(15, 31,4000,{.forwards = false,.maxSpeed=60});
//     intake.move(-127);
//     pros::delay(300);
//     intake.move(0);
//     deploy.set_value(false);
//     pto.set_value(false);

//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     left.move(127);
//     right.move(127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);

//     //get 2 rings
//     chassis.swingToPoint(30,44,DriveSide::RIGHT,2000,{.maxSpeed=80});
//     intake.move(127);
//     chassis.moveToPoint(30,44,2000);
//     chassis.turnToHeading(95,1000);
//     chassis.moveDistance(15,2000);
//     // chassis.moveDistance(15,2000);

//     // intake.move(0);
//     chassis.turnToPoint(30,11,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     // intake.move(127);
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     chassis.moveToPoint(30,11,2000);
//     // intake.move(0);

//     //28 -1
//     // intake.move(0);
//     chassis.turnToPoint(-28,-1,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     // intake.move(127);
//     chassis.moveToPoint(-28,-1,2000,{.minSpeed=127,.earlyExitRange = 40});
//     chassis.moveToPoint(-28,-1,4000,{.maxSpeed = 40},false);
//     // while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)) pros::delay(10);
//     // chassis.cancelMotion();
//     // intake.move(0);

//     chassis.moveToPoint(-55,-1,2000);

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

// void blue3(){
//     //  setup
//     chassis.setPose(0,0,-146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

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

//     // chassis.moveToPoint(7,-1,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToPoint(7,38,2000,{.minSpeed=5,.earlyExitRange=3});
//     // // intake.move(0);
//     // set_intake_speed(0);
//     // chassis.moveToPoint(7,38,2000);
//     chassis.moveToPoint(-55,-1,2000);

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