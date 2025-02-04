#include "main.h"


pros::MotorGroup intake({-1,2});
pros::MotorGroup arm({15,-17});
pros::ADIDigitalOut mogo('H');
pros::ADIDigitalOut swiper('G');
pros::ADIDigitalOut sort_thrower('A');


pros::Rotation arm_control(-16);


pros::Vision vision(14);
pros::Distance distance(8);
pros::Distance top_distance(3);
pros::Distance mogo_distance(19);
// pros::Distance ladybrown_dist(8);

pros::Controller master(pros::E_CONTROLLER_MASTER);


// red (1,252,215,220,7,.34)
// blue(2,173,254,254,26,.68)
