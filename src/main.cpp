#include "main.h"

/*
true: display odometry data and will run the test auton
false: display competition screen to choose different autons
*/
bool testing = false;
bool swiperstate = false; //
bool swiperon = false;
bool swiperoff = false;
int auton_status = 0;
int test_auton = SKILLS;
bool mobostate = false;
bool moboon = false;
bool mobooff = false;
bool enableAutoClamp = true; // name changed to enableAutoClamp by Sean (05.03.2025)
bool autoclamped = false;
pros::Mutex intakemutex;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void intakeOn(int speed, double duration)
{
	pros::Task intakeon_task([=]()
							 {
	intakemutex.lock();
	set_intake_speed(speed);
	pros::delay(duration);
	set_intake_speed(0);
	intakemutex.unlock(); });
}
void initialize()
{
	pros::lcd::initialize();
	pros::delay(100);
	// chassis = init_drive();
	// chassis.setPose(0,0,0);
	// chassis.setPose(0,0,-12);
	arm_to_pos();
	arm_control.set_position(0);
	mogo.set_value(false);
	init_intake();
	setup();
	// sort(BLUECOLOR);
	// sort_thrower.set_value(true);
	intakerotation.set_position(0);
	set_intake_speed(0);
	chassis.calibrate();
	pros::delay(100);
	chassis.setPose(0, 0, 0);
	if (testing)
	{
		// if (test_auton < 0)
		// 	sort(REDCOLOR);
		// else
		// 	sort(BLUECOLOR);
		pros::Task screen_task([&]()
							   {
			while (true) {
				// print robot location to the brain screen
				pros::lcd::print(1,"X: %f", chassis.getPose().x); // x
				pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
				pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
				pros::lcd::print(4, "angle: %d", arm_control.get_position()); // heading
				pros::lcd::print(5, "MogoDistance: %d",mogo_distance.get_distance()); 
				pros::lcd::print(6, "IntakeDistance: %d",top_distance.get_distance()); 
				// delay to save resources
				pros::delay(30);
			} });
	}
	else
	{
		chooser(auton_status);
		// if (auton_status < 0)
		// 	sort(REDCOLOR);
		// else
		// 	sort(BLUECOLOR);
		pros::lcd::set_text(1, "AUTON CHOSEN, GOOD LUCK!");
		pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, ".--.");
	}
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
	// if(!testing){
	// 	chooser(auton_status);
	// 	pros::lcd::set_text(1, "auton chosen");
	// }
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
	if (testing)
	{
		run_auton(test_auton);
		// pros::delay(5000);
		// if (test_auton > 0)
		// 	reset_position(146);
		// else
		// 	reset_position(-146);
	}
	else
		run_auton(auton_status);
}

bool intake_on = true;
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	// intake_task->remove();

	arm.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
	left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
	right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);

	bool mogo_flag = false;
	bool mogo_pressed = true;
	bool swiper_flag = false;
	bool swiper_pressed = true;
	bool uppressed = true;
	bool b_pressed = true;
	bool y_pressed = true;

	bool arm_pressed = true;
	int leftY, rightX = 0;
	// if (intake_task != nullptr) {
	// 	intake_task->notify();
	// }
	// init_driver_intake();
#pragma region arcade
	// Arcade control scheme

	pros::Task drive_task([&]()
						  {
			while (true) {
				leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		left.move(leftY + rightX * (37 * pow(0.05, 0.012 * fabs(leftY)) + 90) / 127);
		right.move(-leftY + rightX * fabs((37 * pow(0.05, 0.012 * fabs(leftY)) + 90) / 127));
				// delay to save resources
				pros::delay(20);
			} });
#pragma endregion arcade

	while (true)
	{
		if (master.get_digital(DIGITAL_L1))
		{
			if (!arm_pressed)
			{
				// intake.move(-60);
				set_intake_speed(-50);
				arm.move(127);
				pros::delay(100);
				// intake.move(0);
				set_intake_speed(0);
				arm_pressed = true;
			}
			// arm_mutex.lock();
			arm_move = true;
			// arm_mutex.unlock();
			arm.move(127);
			// target_mutex.lock();
			global_target = 0;
			// global_target=5000;
			// target_mutex.unlock();
		}
		else if (master.get_digital(DIGITAL_L2))
		{
			// arm_mutex.lock();
			arm_move = true;
			// arm_mutex.unlock();
			arm.move(-127);

			// target_mutex.lock();
			global_target = 0;
			// global_target=5000;
			// target_mutex.unlock();
		}
		else if (master.get_digital(DIGITAL_L1) != 1 && arm_pressed)
		{
			arm_pressed = false;
		}
		else if (master.get_digital(DIGITAL_DOWN))
		{
			arm_move = false;
			global_target = 20000;
		}
		else
		{
			// arm_mutex.lock();
			if (arm_move)
			{
				arm.brake();
				global_target = 0;
			}
			// arm_mutex.unlock();
		}

#pragma region intake r1
		if (master.get_digital(DIGITAL_R1) && intake_on)
		{
			// intake.move(127);
			intakemutex.lock();
			set_intake_speed(127, false);
			intakemutex.unlock();
		}
		else if (master.get_digital(DIGITAL_R2) && intake_on)
		{
			// intake.move(-127);
			intakemutex.lock();
			set_intake_speed(-127, false);
			intakemutex.unlock();
		}
		else if (intake_on)
		{
			// intake.move(0);
			intakemutex.lock();
			set_intake_speed(0, false);
			intakemutex.unlock();
		}
#pragma endregion intake

#pragma region SWIPER

		// Swiper control//
		if (master.get_digital(DIGITAL_X) && swiperstate == false)
		{
			swiper.set_value(true);
			swiperon = true;
		}
		else if (master.get_digital(DIGITAL_X) != 1 && swiperon == true)
		{
			swiperstate = true;
			swiperon = false;
		}
		if (master.get_digital(DIGITAL_X) && swiperstate == true)
		{
			swiper.set_value(false);
			swiperoff = true;
		}
		else if (master.get_digital(DIGITAL_X) != 1 && swiperoff == true)
		{
			swiperstate = false;
			swiperoff = false;
		}
#pragma endregion SWIPER

// #pragma region MOGOCLAMP
// // Original MOGOCLAMP code by Leo (05.03.2025)
// 		if (master.get_digital(DIGITAL_A) && mobostate == false)
// 		{
// 			mogo.set_value(true);
// 			moboon = true;
// 		}
// 		else if (master.get_digital(DIGITAL_A) != 1 && moboon == true)
// 		{
// 			mobostate = true;
// 			moboon = false;
// 		}
// 		if (mogo_seated() && mobostate == false && disableautoclamp == false)
// 		{
// 			mogo.set_value(true);
// 			pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, ".");
// 			mobostate = true;
// 			autoclamped = true;
// 		}
// 		if (master.get_digital(DIGITAL_A) && mobostate == true)
// 		{
// 			mogo.set_value(false);
// 			intakeOn(-127, 70);
// 			if (autoclamped == true)
// 			{
// 				disableautoclamp = true;
// 				autoclamped = false;
// 			}
// 			mobooff = true;
// 		}
// 		else if (master.get_digital(DIGITAL_A) != 1 && mobooff == true)
// 		{
// 			mobostate = false;
// 			mobooff = false;
// 		}
// 		if (disableautoclamp == true && !mogo_seated())
// 		{
// 			disableautoclamp = false;
// 		}
// #pragma endregion MOGOCLAMP

#pragma region MOGOCLAMP
// New MOGOCLAMP code by Sean (05.03.2025)

		if (master.get_digital(DIGITAL_A) && mobostate == false)
		{
			mogo.set_value(true);
			mobostate = true;
		}

		else if (master.get_digital(DIGITAL_A) && mobostate == true)
		{
			mogo.set_value(false);
			intakeOn(-127, 70);
			mobostate = false;
			enableAutoClamp = false;
			// pros::delay(1000);
			// enableAutoClamp = true;
		}

		if (mogo_seated() && mobostate == false && enableAutoClamp == true)
		{
			mogo.set_value(true);
			pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, ".");
			mobostate = true;
			enableAutoClamp = false;
		}

		if (!mogo_seated()) enableAutoClamp = true;

#pragma endregion MOGOCLAMP

		if (master.get_digital(DIGITAL_B) && !b_pressed)
		{
			// swiper_flag = !swiper_flag;
			// enablesort = false;
			b_pressed = true;
			// arm_mutex.lock();
			arm_move = false;
			// arm_mutex.unlock();
			int a = 0;
			// target_mutex.lock();
			global_target = 2600;

			// global_target=5000;
			// target_mutex.unlock();
			pros::Task drive_task2([&]()
								   {
									int count=0;
									global_target = 2600;
									while(fabs(arm_control.get_position()-2480)>850){
					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2)) return;
					pros::delay(10);
									}
									global_target = 2600;
									intake_on = false;
									intakemutex.lock();
					// 				set_intake_speed(127);
					// 				while(top_distance.get_distance()>50) {
					// 					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2))goto jmp;
										
					// pros::delay(10);
					// 				}
									set_intake_speed(127,false);
									
				while(top_distance.get_distance()>50) {
					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2))goto jmp;
					pros::delay(10);
				}
				// arm.set_brake_mode_all(MOTOR_BRAKE_BRAKE);
				while(count<=60){
					count++;
					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2))
						// return;
						goto jmp;
					pros::delay(10);
				}
				// pros::delay(700);
				set_intake_speed(-15);
				// arm.move(127);
				// pros::delay(60);
				// // target_mutex.lock();
				// global_target=5100;
				// target_mutex.unlock();
				// intake.move(-50);
				// count=0;
				// while(count<=40){
				// 	count++;
				// 	if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2))
				// 		// return;
				// 		goto jmp;
				// 	pros::delay(10);
				// }
				// set_intake_speed(0);
				pros::delay(150);
				// set_intake_speed(127,false);
				// pros::delay(100);
				// set_intake_speed(0,false);
				arm_move = true;
				arm.move(127);
				pros::delay(160);
				// target_mutex.lock();
				arm_move = false;
				global_target=5100;
				while(fabs(arm_control.get_position()-5100)>1500){
					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2)) goto jmp;
					pros::delay(10);
									}
				set_intake_speed(127,false);
				while(top_distance.get_distance()>50) {
					if( master.get_digital(DIGITAL_R1)||master.get_digital(DIGITAL_R2)||master.get_digital(DIGITAL_Y) || master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2))
						// return;
						goto jmp;
					pros::delay(5);
				}
				set_intake_speed(-60);
				pros::delay(150);
				set_intake_speed(0,false);
				// arm.set_brake_mode_all(MOTOR_BRAKE_HOLD);
				jmp: 
				intake_on = true;
				arm_move=true; 
				intakemutex.unlock(); 
				// enablesort=true; 
			});
		}

		else if (master.get_digital(DIGITAL_B) != 1 && b_pressed)
		{
			b_pressed = false;
		}

		if (master.get_digital(DIGITAL_Y) && !y_pressed)
		{
			// hang_flag = !hang_flag;
			y_pressed = true;
			// arm_mutex.lock();
			arm_move = false;
			// arm_mutex.unlock();

			// target_mutex.lock();
			global_target = 100;
			// target_mutex.unlock();
		}
		else if (master.get_digital(DIGITAL_Y) != 1 && y_pressed)
		{
			y_pressed = false;
		}

		if (master.get_digital(DIGITAL_UP) && !uppressed)
		{
			chassis.moveDistance(7.5, 1000, {.forwards = false});
			chassis.waitUntil(4);
			arm_move = true;
			arm.move(127);

			// pros::Task drive_task2([&]()
			// 					   {
			// 						uppressed = true;
			// arm_move = false;
			// arm.move(127);
			// 	while(fabs(arm_control.get_position()-18420)>1000) pros::delay(20);
			// global_target = 18420; });
		}
		else if (master.get_digital(DIGITAL_UP) != 1 && uppressed)
		{
			uppressed = false;
		}
		pros::delay(10); // Run for 20 ms then update
	}
}