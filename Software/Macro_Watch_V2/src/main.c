#include <si_toolchain.h>
#include <SI_EFM8SB1_Register_Enums.h>
#include "InitDevice.h"

SI_SBIT(M32, SFR_P0, 0);
SI_SBIT(M16, SFR_P0, 1);
SI_SBIT(M8, SFR_P0, 2);
SI_SBIT(M4, SFR_P0, 3);
SI_SBIT(M2, SFR_P0, 4);
SI_SBIT(M1, SFR_P0, 5);

SI_SBIT(EXTRA, SFR_P0, 7);

SI_SBIT(SEC, SFR_P1, 0);
SI_SBIT(H1, SFR_P1, 1);
SI_SBIT(H2, SFR_P1, 2);
SI_SBIT(H4, SFR_P1, 3);
SI_SBIT(H8, SFR_P1, 5);

SI_SBIT(SW, SFR_P0, 6);

#define SUSPEND            		    0x40        // Value to write to PMU0CF to place
                                                // the device in Suspend mode

#define SLEEP              		    0x80        // Value to write to PMU0CF to place
                                                // the device in Sleep Mode

#define POWER_MODE     			    SLEEP       // Select between Suspend and Sleep
                                                // mode. When debugging, if the
                                                // MCU is stopped/halted while
                                                // in Sleep Mode, the connection
                                                // to the IDE will be lost. The
                                                // IDE connection will not be lost
                                                // if the MCU is stopped/halted
                                                // while in suspend mode.

SI_SEGMENT_VARIABLE(wakeup_source, uint8_t, SI_SEG_XDATA);

int STATE = 0;

int BUTT_action = 0;

int Disp_timeout = 0;
int Change_time = 0;
int ADVCLKDELAY = 0;
int ADVCLKCNT = 0;

int SECONDS = 0;
int MINUTES = 12;
int HOUR = 12;

void delay_ms(int);
void TEST_LED_PATTERN(void);


int main(void)
{
	enter_DefaultMode_from_RESET();

    TEST_LED_PATTERN();

	M32 = 0;
	M16 = 0;
	M8 = 0;
	M4 = 0;
	M2 = 0;
	M1 = 0;
	SEC = 0;
	H1 = 0;
	H2 = 0;
	H4 = 0;
	H8 = 0;
	EXTRA = 0;

    // Set P0.6 to Digital Input for port match detection.
    P0MASK |= P0MASK_B6__COMPARED;
    P0MDIN |= P0MDIN_B6__DIGITAL;

	while (1)
	{
		//PMU0CF = 0x20;
		//RSTSRC = 0x04;                // Disable VDDMON, leave missing clock
									  // detector enabled
		// Put device to sleep
		PMU0CF = 0x0E | POWER_MODE;   // To change between SUSPEND or SLEEP
									  // modes, change the POWER_MODE
									  // definition in the global constants

		while (!(VDM0CN & 0x20));     // Wait for VDDOK to be set to 1

		EXTRA = 1;

        // Read the wake-up source flags
        wakeup_source = PMU0CF & 0x1F;

        // Clear the wake-up source flags
        //PMU0CF = 0x20;
        PMU0CF |= PMU0CF_CLEAR__ALL_FLAGS;

        // Check for smaRTClock alarm
        if (wakeup_source & 0x04)
        {
        	SECONDS++;
        	if(SECONDS == 60)
        	{
        		SECONDS = 0;
        		MINUTES++;
        		if(MINUTES == 60)
        		{
        			MINUTES = 0;
        			HOUR++;
        			if(HOUR == 13)
        			{
        				HOUR = 1;
        			}
        		}
        	}
        }

        switch(STATE)
        {
        case 0 : //OFF STATE

        	M32 = 0;
        	M16 = 0;
        	M8 = 0;
        	M4 = 0;
        	M2 = 0;
        	M1 = 0;
        	SEC = 0;
        	H1 = 0;
        	H2 = 0;
        	H4 = 0;
        	H8 = 0;

        	// Check for Port Match event
        	if (wakeup_source & 0x02)
        	{
        		STATE = 1;
        		BUTT_action = 1;

        		H1 = HOUR & 0x01;
				H2 = (HOUR >> 1) & 0x01;
				H4 = (HOUR >> 2) & 0x01;
				H8 = (HOUR >> 3) & 0x01;

				M1  = MINUTES & 0x01;
				M2  = (MINUTES >> 1) & 0x01;
				M4  = (MINUTES >> 2) & 0x01;
				M8  = (MINUTES >> 3) & 0x01;
				M16  = (MINUTES >> 4) & 0x01;
				M32  = (MINUTES >> 5) & 0x01;

				SEC = !SEC;
        	}
        	else
        	{
        		STATE = 0;
        		BUTT_action = 0;
        	}
        	break;
        case 1 : //BUTTON PRESSED. RECORD TIME.

        	H1 = HOUR & 0x01;
			H2 = (HOUR >> 1) & 0x01;
			H4 = (HOUR >> 2) & 0x01;
			H8 = (HOUR >> 3) & 0x01;

			M1  = MINUTES & 0x01;
			M2  = (MINUTES >> 1) & 0x01;
			M4  = (MINUTES >> 2) & 0x01;
			M8  = (MINUTES >> 3) & 0x01;
			M16  = (MINUTES >> 4) & 0x01;
			M32  = (MINUTES >> 5) & 0x01;

			SEC = !SEC;

        	Disp_timeout = SECONDS + 10;

        	if(Disp_timeout >= 60)
			{
				Disp_timeout = Disp_timeout - 60;
			}

			Change_time = SECONDS;
			Change_time = Change_time + 3;

			if(Change_time >= 60)
			{
				Change_time = Change_time - 60;
			}

			STATE = 2;

			break;
        case 2 : //TURN ON DISPLAY. AND WAIT FOR TIMEOUTS

        	H1 = HOUR & 0x01;
			H2 = (HOUR >> 1) & 0x01;
			H4 = (HOUR >> 2) & 0x01;
			H8 = (HOUR >> 3) & 0x01;

			M1  = MINUTES & 0x01;
			M2  = (MINUTES >> 1) & 0x01;
			M4  = (MINUTES >> 2) & 0x01;
			M8  = (MINUTES >> 3) & 0x01;
			M16  = (MINUTES >> 4) & 0x01;
			M32  = (MINUTES >> 5) & 0x01;

			SEC = !SEC;

			//Display time out. Time to turn off display.
			if(Disp_timeout == SECONDS)
			{
				STATE = 0;
				BUTT_action = BUTT_action;
			}

			//Button is pressed again. Reset display time and set button action flag.
			else if(SW == 0 && BUTT_action == 0)
			{
				STATE = 1;
				BUTT_action = 1;
			}

			//Button is held for 3 seconds. Time to hack time!
			else if(Change_time == SECONDS && SW == 0 && BUTT_action == 1)
			{
				STATE = 3;
				BUTT_action = BUTT_action;
				ADVCLKDELAY = 50;
				ADVCLKCNT   = 2;
			}
			//Button has stopped being pressed. Clear button action flag.
			else if(SW == 1 && BUTT_action == 1)
			{
				STATE = 2;
				BUTT_action = 0;
			}

			break;

        case 3 : //INCREASE TIME AND DISPLAY TIME.
        	//Switch held. Increase time.
			while(SW == 0)
			{
				SECONDS = 0;
				MINUTES = MINUTES + 1;
				if(MINUTES == 60)
				{
					MINUTES = 0;
					HOUR = HOUR + 1;
					if(HOUR == 13)
					{
						HOUR = 1;
					}
				}
				//Calculate "acceleration" of time hacking.
				ADVCLKCNT = ADVCLKCNT - 1;
				if(ADVCLKCNT == 0 && ADVCLKDELAY > 5)
				{
					ADVCLKCNT = 3;
					ADVCLKDELAY = ADVCLKDELAY - 5;
				}

				H1 = HOUR & 0x01;
				H2 = (HOUR >> 1) & 0x01;
				H4 = (HOUR >> 2) & 0x01;
				H8 = (HOUR >> 3) & 0x01;

				M1  = MINUTES & 0x01;
				M2  = (MINUTES >> 1) & 0x01;
				M4  = (MINUTES >> 2) & 0x01;
				M8  = (MINUTES >> 3) & 0x01;
				M16  = (MINUTES >> 4) & 0x01;
				M32  = (MINUTES >> 5) & 0x01;

				SEC = 0;

				delay_ms(ADVCLKDELAY);


			}
			//Switch released. Recalculate on time.
			if(SW == 1)
			{
				STATE = 1;
			}

			break;


		//Never supposed to get here but just encase of cosmic radiation flipping a bit.
		default:

			STATE = 0;

			break;
        }

        EXTRA = 0;
	}
}

void delay_ms(int milliseconds)
{
	milliseconds = milliseconds * 32;
	while((milliseconds) > 0)
	{
		milliseconds--;
	}
}

void TEST_LED_PATTERN(void)
{
	M32 = 1;
	delay_ms(20);
	M32 = 0;

	M16 = 1;
	delay_ms(20);
	M16 = 0;

	M8 = 1;
	delay_ms(20);
	M8 = 0;

	M4 = 1;
	delay_ms(20);
	M4 = 0;

	M2 = 1;
	delay_ms(20);
	M2 = 0;

	M1 = 1;
	delay_ms(20);
	M1 = 0;

	SEC = 1;
	delay_ms(20);
	SEC = 0;

	H1 = 1;
	delay_ms(20);
	H1 = 0;

	H2 = 1;
	delay_ms(20);
	H2 = 0;

	H4 = 1;
	delay_ms(20);
	H4 = 0;

	H8 = 1;
	delay_ms(20);
	H8 = 0;
}
