#include "main.h"

//new bot red + 4 ring 3 goal
void red4(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,-146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(7,1000);
    arm.move(127);
    pros::delay(700);
    arm.brake();

    chassis.moveToPoint(16, 32,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_mutex.lock();
    arm_move=false;
    arm_mutex.unlock();

    target_mutex.lock();
    global_target=100;
    target_mutex.unlock();
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();


    // -18 11
    //get 2 ring red
    // chassis.turnToPoint(-18,11,2000,{},false);
    // set_intake_speed(127);
    // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

    set_intake_speed(127);
    // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
    // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(-10,12,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.turnToPoint(39,28,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=5});
    

    chassis.turnToPoint(39,28,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
    // mogo.set_value(false);
    // set_intake_speed(127);
    chassis.moveToPoint(39,28,2000);
    // fast_move(38,30,2000,false);
    chassis.moveDistance(10,1000,{.forwards=false},false);
    mogo.set_value(true);
    set_intake_speed(-127);
    chassis.moveDistance(10,1000);
    
    
    chassis.turnToPoint(42,45.5,1000,{.forwards=false},false);
    chassis.moveToPoint(42,45.5,4000,{.forwards = false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
    fast_move(38,-4,2000,true);
    chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
    // fast_move(38,0,2000,true);

    chassis.turnToPoint(46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
    left.brake();
    right.brake();
    set_intake_speed(127);
    chassis.moveDistance(40,1000);
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

    chassis.moveToPoint(5,41,3000,{.forwards=false});
    chassis.waitUntil(20);
    set_intake_speed(0);
    target_mutex.lock();
    global_target=6000;
    target_mutex.unlock();
    while(chassis.isInMotion()) pros::delay(10);
    arm_mutex.lock();
    arm_move=true;
    arm_mutex.unlock();
    arm.move(0);

    // target_mutex.lock();
    // global_target=20000;
    // target_mutex.unlock();
    // chassis.moveToPoint(10,8,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    // chassis.turnToPoint(10,40,1000,{.minSpeed=5,.earlyExitRange=3});
    // arm_mutex.lock();
    // arm_move=true;
    // arm_mutex.unlock();
    // arm.move(0);
    // chassis.moveToPoint(10,40,1000);
}


// // 3 goal - side
// void red4(){
//     // setup
//     chassis.setPose(0,0,146);
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
//     chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=60});
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
//     chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80, .minSpeed=5, .earlyExitRange = 10});
//     chassis.turnToPoint(-30,44,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(-30,44,1000);
//     chassis.turnToPoint(-48,44,1000,{.minSpeed=50,.earlyExitRange=3});
//     chassis.moveToPoint(-48,44,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToHeading(267,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(18,1000);
//     // chassis.moveDistance(15,2000);

//     chassis.turnToHeading(280,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(30,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(-37,30,1000,{.minSpeed=20,.earlyExitRange=3});

//     // chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     // chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
//     // pros::delay(500);
//     // chassis.cancelMotion();
//     // left.
//     // pros::delay(500);
//     // chassis.moveToPoint(-30,11,4000,{.minSpeed=5,.earlyExitRange=3});
//     fast_move(-37,30,2000,true);



//     //28 -1
//     chassis.turnToPoint(20,12,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveToPoint(16,16,2000);
//     fast_move(20,12,2000,true);
//     mogo.set_value(false);
//     // chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40});
//     while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     set_intake_speed(0);


//     chassis.turnToPoint(38,29, 1000,{.forwards=false});
//     chassis.moveToPoint(38,29,2000,{.forwards=false,.maxSpeed=60});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     chassis.cancelMotion();

//     chassis.turnToPoint(65,29,2000,{.minSpeed=5,.earlyExitRange=3});
//     set_intake_speed(127);
//     chassis.moveToPoint(65,29,2000,{},false);
//     pros::delay(500);

//     chassis.moveToPoint(26,35,2000,{.forwards=false},false);
//     set_intake_speed(0);

// }