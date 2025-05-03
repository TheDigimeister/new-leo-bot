#include "main.h"

int convert_bit(int input)
{
    if (input & LCD_BTN_LEFT)
    {
        return -1;
    }
    else if (input & LCD_BTN_CENTER)
    {
        return 100;
    }
    else if (input & LCD_BTN_RIGHT)
    {
        return 1;
    }
    else
        return 0;
}

void chooser(int &status)
{
    bool set_text = false;
    int selected = 0;

    while (true)
    {
        if (pros::competition::get_status() == 4)
            break;
        if (master.get_digital(DIGITAL_LEFT))
            break;
        selected = convert_bit(pros::lcd::read_buttons());
        // printf("%d , %d\n",pros::lcd::read_buttons(),status);
        if (status == -7)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "BLUE(-)NEG FINALS");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -6)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "BLUE(+)POS FINALS NO GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -5)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "BLUE(+)POS FINALS GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -4)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "BLUE(+)POS TEAMWORK NO GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -3)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "BLUE(+)POS TEAMWORK GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -2)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    BLUE(-)NEG SIG WP   ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == -1)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    BLUE(-)NEG TEAMWORK  ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 0)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "<-BLUE       CHOOSE       RED->");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected != 100)
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 1)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    RED(-)NEG TEAMWORK  ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 2)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    RED(-)NEG SIG WP   ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 3)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "RED(+)POS TEAMWORK GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 4)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "RED(+)POS TEAMWORK NO GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 5)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "RED(+)POS FINALS GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 6)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "RED(+)POS FINALS NO GRAB 3RD MOGO");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 7)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "RED(-)NEG FINALS");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 8)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    SKILLS   ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else if (status == 9)
        {
            if (!set_text)
            {
                pros::lcd::set_text(1, "    TEST   ");
                set_text = true;
            }
            if (selected != 0)
            {
                set_text = false;
                if (selected == 100)
                    return;
                else
                    status += selected;
                pros::delay(500);
                continue;
            }
        }
        else
            status = 0;

        selected = 0;
        pros::delay(20);
    }
}

void run_auton(int selected)
{
    switch (selected)
    {
    case -7:
        blueneg_finals();
        break;
    case -6:
        bluepos_finals_nograb3rdmogo();
        break;
    case -5:
        bluepos_finals_grab3rdmogo();
        break;
    case -4:
        bluepos_teamwork_nograb3rdmogo();
        break;
    case -3:
        bluepos_teamwork_grab3rdmogo();
        break;
    case -2:
        blueneg_sigWP();
        break;
    case -1:
        blueneg_teamwork();
        break;
    case 1:
        redneg_teamwork();
        break;
    case 2:
        redneg_sigWP();
        break;
    case 3:
        redpos_teamwork_grab3rdmogo();
        break;
    case 4:
        redpos_teamwork_nograb3rdmogo();
        break;
    case 5:
        redpos_finals_grab3rdmogo();
        break;
    case 6:
        redpos_finals_nograb3rdmogo();
        break;
    case 7:
        redneg_finals();
        break;
    case 8:
        skills();
        break;
    case 9:
        test();
        break;
    default:
        break;
    }
}