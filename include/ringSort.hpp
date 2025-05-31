#ifndef _RINGSORT_HPP_
#define _RINGSORT_HPP_

#define REDCOLOR 1
#define BLUECOLOR 2
#define MOGOCOLOR 3
void sort(int color_type);
bool mogo_seated();
void init_intake();
void setup();
void turntomogo();
void getring();
void set_intake_speed(int speed, bool jam = true);
void fast_move(float x, float y, int timeout, bool async);
void init_driver_intake();
extern pros::Task *intake_task;

extern pros::Mutex arm_mutex;
extern pros::Mutex target_mutex;
extern int global_target;
extern bool arm_move;
// extern bool enablesort;
void arm_to_pos();

#endif