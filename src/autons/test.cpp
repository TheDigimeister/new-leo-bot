#include "main.h"
void test()
{
    chassis.turnToHeading(90, 1000);
    chassis.moveDistance(10, 1000);
    chassis.turnToHeading(180, 1000);
    chassis.moveDistance(10, 1000);
    chassis.turnToHeading(270, 1000);
    chassis.moveDistance(10, 1000);
    chassis.turnToHeading(0, 1000);
    chassis.moveDistance(10, 1000);
}