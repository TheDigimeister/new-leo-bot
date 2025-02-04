#include "main.h"

// red finals code + for new bot
void red5(){
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
    

    chassis.turnToPoint(39,28,1000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
    // mogo.set_value(false);
    // set_intake_speed(127);
    chassis.moveToPoint(39,28,2000,{.minSpeed=5, .earlyExitRange=3});
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
    chassis.turnToPoint(38,-4,1000,{.minSpeed=5, .earlyExitRange=3},false);
    chassis.moveToPoint(38,-4,2000,{.minSpeed=5, .earlyExitRange=3});
    chassis.waitUntil(8);
    set_intake_speed(-127);
    chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
    // fast_move(38,0,2000,true);
    

    chassis.turnToPoint(46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
    left.brake();
    right.brake();
    set_intake_speed(127);
    chassis.moveDistance(40,1000);
    // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

    chassis.moveDistance(15,1000,{.forwards=false, .minSpeed=5, .earlyExitRange=3},false);
    pros::delay(1000);
    set_intake_speed(0);
    swiper.set_value(true);
    chassis.moveDistance(10,1000,{.minSpeed=5, .earlyExitRange=3});
    chassis.turnToHeading(55,1000,{.minSpeed=5, .earlyExitRange=3},false);
    swiper.set_value(false);
    chassis.turnToPoint(42,35,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(42,35,2000,{.minSpeed=5, .earlyExitRange=3});
    
    chassis.waitUntil(10);
    mogo.set_value(true);
    chassis.turnToHeading(180,1000);
    
    // chassis.moveToPoint(5,41,3000,{.forwards=false});
    // chassis.waitUntil(20);
    // set_intake_speed(0);
    // target_mutex.lock();
    // global_target=6000;
    // target_mutex.unlock();
    // while(chassis.isInMotion()) pros::delay(10);
    // arm_mutex.lock();
    // arm_move=true;
    // arm_mutex.unlock();
    // arm.move(0);

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


// //4 ring 3 goal +
// void red5(){
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     chassis.setPose(0,0,-146);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(true);

//     //score ring
//     chassis.moveDistance(7,1000);
//     arm.move(127);
//     pros::delay(700);
//     arm.brake();

//     chassis.moveToPoint(16, 32,4000,{.forwards = false,.maxSpeed=80});
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
//     chassis.moveToPoint(-10,12,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(39,28,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
//     chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=5});
    

//     chassis.turnToPoint(39,28,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
//     // mogo.set_value(false);
//     // set_intake_speed(127);
//     chassis.moveToPoint(39,28,2000);
//     // fast_move(38,30,2000,false);
//     chassis.moveDistance(10,1000,{.forwards=false},false);
//     mogo.set_value(true);
//     set_intake_speed(-127);
//     chassis.moveDistance(10,1000);
    
    
//     chassis.turnToPoint(42,45.5,1000,{.forwards=false},false);
//     chassis.moveToPoint(42,45.5,4000,{.forwards = false,.maxSpeed=70});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();

//     // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
//     fast_move(38,-4,2000,true);
//     chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
//     // fast_move(38,0,2000,true);

//     chassis.turnToPoint(46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
//     left.brake();
//     right.brake();
//     set_intake_speed(127);
//     chassis.moveDistance(40,1000);
//     // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

//     chassis.moveToPoint(5,41,3000,{.forwards=false});
//     chassis.waitUntil(20);
//     set_intake_speed(0);
//     target_mutex.lock();
//     global_target=6000;
//     target_mutex.unlock();
//     while(chassis.isInMotion()) pros::delay(10);
//     arm_mutex.lock();
//     arm_move=true;
//     arm_mutex.unlock();
//     arm.move(0);

//     // target_mutex.lock();
//     // global_target=20000;
//     // target_mutex.unlock();
//     // chassis.moveToPoint(10,8,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToPoint(10,40,1000,{.minSpeed=5,.earlyExitRange=3});
//     // arm_mutex.lock();
//     // arm_move=true;
//     // arm_mutex.unlock();
//     // arm.move(0);
//     // chassis.moveToPoint(10,40,1000);
// }