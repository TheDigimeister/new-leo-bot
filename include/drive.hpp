#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

#define LEFTMOTOR1PORT 5
#define LEFTMOTOR2PORT 20
#define LEFTMOTOR3PORT 21
#define RIGHTMOTOR1PORT 11
#define RIGHTMOTOR2PORT 12
#define RIGHTMOTOR3PORT 13

#define IMUPORT 8
#define VERTICALENCODERPORT 9
#define HORIZONTALENCODERPORT 4

extern lemlib::Chassis chassis;
extern pros::MotorGroup left;
extern pros::MotorGroup right;

#endif