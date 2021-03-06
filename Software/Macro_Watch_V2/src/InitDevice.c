//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8SB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	PCA_0_enter_DefaultMode_from_RESET();
	PCACH_2_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	RTC_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

//================================================================================
// PCA_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCA_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0MD - PCA Mode]
	/***********************************************************************
	 - Disable Watchdog Timer
	 - System clock divided by 12
	 - PCA continues to function normally while the system controller is in
	 Idle Mode
	 - Disable the CF interrupt
	 - Disable Watchdog Timer
	 - Watchdog Timer Enable unlocked
	 ***********************************************************************/
	SFRPAGE = 0x00;
	PCA0MD &= ~PCA0MD_WDTE__BMASK;
	PCA0MD = PCA0MD_CPS__SYSCLK_DIV_12 | PCA0MD_CIDL__NORMAL
			| PCA0MD_ECF__OVF_INT_DISABLED | PCA0MD_WDTE__DISABLED
			| PCA0MD_WDLCK__UNLOCKED;
	// [PCA0MD - PCA Mode]$

	// $[PCA0H - PCA Counter/Timer High Byte]
	// [PCA0H - PCA Counter/Timer High Byte]$

	// $[PCA0L - PCA Counter/Timer Low Byte]
	// [PCA0L - PCA Counter/Timer Low Byte]$

	// $[PCA0PWM - PCA PWM Configuration]
	// [PCA0PWM - PCA PWM Configuration]$

	// $[PCA0CN0 - PCA Control 0]
	// [PCA0CN0 - PCA Control 0]$

}

//================================================================================
// PCACH_2_enter_DefaultMode_from_RESET
//================================================================================
extern void PCACH_2_enter_DefaultMode_from_RESET(void) {
	// $[PCA0 Settings Save]
	// Select Capture/Compare register)
	PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
	// [PCA0 Settings Save]$

	// $[PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]
	/***********************************************************************
	 - Disable negative edge capture
	 - Disable CCF2 interrupts
	 - Enable match function
	 - 8 to 11-bit PWM selected
	 - Disable positive edge capture
	 - Disable comparator function
	 - Disable PWM function
	 - Disable toggle function
	 ***********************************************************************/
	PCA0CPM2 = PCA0CPM2_CAPN__DISABLED | PCA0CPM2_ECCF__DISABLED
			| PCA0CPM2_MAT__ENABLED | PCA0CPM2_PWM16__8_BIT
			| PCA0CPM2_CAPP__DISABLED | PCA0CPM2_ECOM__DISABLED
			| PCA0CPM2_PWM__DISABLED | PCA0CPM2_TOG__DISABLED;
	// [PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]$

	// $[PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]
	// [PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]$

	// $[PCA0CPH2 - PCA Channel 2 Capture Module High Byte]
	// [PCA0CPH2 - PCA Channel 2 Capture Module High Byte]$

	// $[Auto-reload]
	// [Auto-reload]$

	// $[PCA0 Settings Restore]
	// [PCA0 Settings Restore]$

}

//================================================================================
// PORTS_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	/***********************************************************************
	 - P0.0 is low. Set P0.0 to drive low
	 - P0.1 is low. Set P0.1 to drive low
	 - P0.2 is low. Set P0.2 to drive low
	 - P0.3 is low. Set P0.3 to drive low
	 - P0.4 is low. Set P0.4 to drive low
	 - P0.5 is low. Set P0.5 to drive low
	 - P0.6 is high. Set P0.6 to drive or float high
	 - P0.7 is low. Set P0.7 to drive low
	 ***********************************************************************/
	P0 = P0_B0__LOW | P0_B1__LOW | P0_B2__LOW | P0_B3__LOW | P0_B4__LOW
			| P0_B5__LOW | P0_B6__HIGH | P0_B7__LOW;
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/***********************************************************************
	 - P0.0 output is push-pull
	 - P0.1 output is push-pull
	 - P0.2 output is push-pull
	 - P0.3 output is push-pull
	 - P0.4 output is push-pull
	 - P0.5 output is push-pull
	 - P0.6 output is open-drain
	 - P0.7 output is push-pull
	 ***********************************************************************/
	P0MDOUT = P0MDOUT_B0__PUSH_PULL | P0MDOUT_B1__PUSH_PULL
			| P0MDOUT_B2__PUSH_PULL | P0MDOUT_B3__PUSH_PULL
			| P0MDOUT_B4__PUSH_PULL | P0MDOUT_B5__PUSH_PULL
			| P0MDOUT_B6__OPEN_DRAIN | P0MDOUT_B7__PUSH_PULL;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

	// $[P0DRV - Port 0 Drive Strength]
	/***********************************************************************
	 - P0.0 output has low output drive strength
	 - P0.1 output has low output drive strength
	 - P0.2 output has high output drive strength
	 - P0.3 output has low output drive strength
	 - P0.4 output has low output drive strength
	 - P0.5 output has low output drive strength
	 - P0.6 output has low output drive strength
	 - P0.7 output has low output drive strength
	 ***********************************************************************/
	SFRPAGE = 0x0F;
	P0DRV = P0DRV_B0__LOW_DRIVE | P0DRV_B1__LOW_DRIVE | P0DRV_B2__HIGH_DRIVE
			| P0DRV_B3__LOW_DRIVE | P0DRV_B4__LOW_DRIVE | P0DRV_B5__LOW_DRIVE
			| P0DRV_B6__LOW_DRIVE | P0DRV_B7__LOW_DRIVE;
	// [P0DRV - Port 0 Drive Strength]$

}

//================================================================================
// PORTS_1_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[Missing Pin Skip]
	// Skip any pins that are not available on this package
	P1SKIP |= P1SKIP_B4__SKIPPED;
	// [Missing Pin Skip]$

	// $[P1 - Port 1 Pin Latch]
	/***********************************************************************
	 - P1.0 is low. Set P1.0 to drive low
	 - P1.1 is low. Set P1.1 to drive low
	 - P1.2 is low. Set P1.2 to drive low
	 - P1.3 is low. Set P1.3 to drive low
	 - P1.5 is low. Set P1.5 to drive low
	 - P1.6 is high. Set P1.6 to drive or float high
	 - P1.7 is high. Set P1.7 to drive or float high
	 ***********************************************************************/
	SFRPAGE = 0x00;
	P1 = P1_B0__LOW | P1_B1__LOW | P1_B2__LOW | P1_B3__LOW | P1_B5__LOW
			| P1_B6__HIGH | P1_B7__HIGH;
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/***********************************************************************
	 - P1.0 output is push-pull
	 - P1.1 output is push-pull
	 - P1.2 output is push-pull
	 - P1.3 output is push-pull
	 - P1.5 output is push-pull
	 - P1.6 output is open-drain
	 - P1.7 output is open-drain
	 ***********************************************************************/
	P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__PUSH_PULL
			| P1MDOUT_B2__PUSH_PULL | P1MDOUT_B3__PUSH_PULL
			| P1MDOUT_B5__PUSH_PULL | P1MDOUT_B6__OPEN_DRAIN
			| P1MDOUT_B7__OPEN_DRAIN;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	/***********************************************************************
	 - P1.0 pin is configured for digital mode
	 - P1.1 pin is configured for digital mode
	 - P1.2 pin is configured for digital mode
	 - P1.3 pin is configured for digital mode
	 - P1.5 pin is configured for digital mode
	 - P1.6 pin is configured for analog mode
	 - P1.7 pin is configured for analog mode
	 ***********************************************************************/
	P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__DIGITAL | P1MDIN_B2__DIGITAL
			| P1MDIN_B3__DIGITAL | P1MDIN_B5__DIGITAL | P1MDIN_B6__ANALOG
			| P1MDIN_B7__ANALOG;
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/***********************************************************************
	 - P1.0 pin is not skipped by the crossbar
	 - P1.1 pin is not skipped by the crossbar
	 - P1.2 pin is not skipped by the crossbar
	 - P1.3 pin is not skipped by the crossbar
	 - P1.5 pin is not skipped by the crossbar
	 - P1.6 pin is skipped by the crossbar
	 - P1.7 pin is skipped by the crossbar
	 ***********************************************************************/
	P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__NOT_SKIPPED
			| P1SKIP_B2__NOT_SKIPPED | P1SKIP_B3__NOT_SKIPPED
			| P1SKIP_B5__NOT_SKIPPED | P1SKIP_B6__SKIPPED | P1SKIP_B7__SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

	// $[P1DRV - Port 1 Drive Strength]
	// [P1DRV - Port 1 Drive Strength]$

}

//================================================================================
// PBCFG_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 ***********************************************************************/
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[XBR0 - Port I/O Crossbar 0]
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

//================================================================================
// RTC_0_enter_DefaultMode_from_RESET
//================================================================================
extern void RTC_0_enter_DefaultMode_from_RESET(void) {
	// $[RTC Initialization]
	// A variable for providing a delay for external oscillator startup
	uint16_t delayCounter;
	// Save the system clock (the system clock will be slowed during the startup delay)
	uint8_t CLKSEL_save;
	CLKSEL_save = CLKSEL;

	// Enable power to the SmaRTClock oscillator circuit (RTC0EN = 1)
	// [RTC Initialization]$

	// $[RTC0XCN0 - RTC Oscillator Control: Initial start-up setting]
	// Set SmaRTClock to Crystal Mode (XMODE = 1).
	// Disable Automatic Gain Control (AGCEN) and enable Bias Doubling (BIASX2) for fast crystal startup.
	RTC0ADR = RTC0XCN0;
	RTC0DAT = RTC0XCN0_XMODE__CRYSTAL | RTC0XCN0_BIASX2__ENABLED;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit
	// [RTC0XCN0 - RTC Oscillator Control: Initial start-up setting]$

	// $[RTC0XCF - RTC Oscillator Configuration]
	/***********************************************************************
	 - Enable load capacitance stepping
	 - Load Capacitance Programmed Value = 0x0E
	 ***********************************************************************/
	RTC0ADR = RTC0XCF;
	RTC0DAT = RTC0XCF_AUTOSTP__ENABLED | (0x0E << RTC0XCF_LOADCAP__SHIFT);
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit
	// [RTC0XCF - RTC Oscillator Configuration]$

	// $[CAPTURE0 - RTC Timer Capture 0]
	// [CAPTURE0 - RTC Timer Capture 0]$

	// $[CAPTURE1 - RTC Timer Capture 1]
	// [CAPTURE1 - RTC Timer Capture 1]$

	// $[CAPTURE2 - RTC Timer Capture 2]
	// [CAPTURE2 - RTC Timer Capture 2]$

	// $[CAPTURE3 - RTC Timer Capture 3]
	// [CAPTURE3 - RTC Timer Capture 3]$

	// $[ALARM0 - RTC Alarm Programmed Value 0]
	// [ALARM0 - RTC Alarm Programmed Value 0]$

	// $[ALARM1 - RTC Alarm Programmed Value 1]
	/***********************************************************************
	 - RTC Alarm Programmed Value 1 = 0x80
	 ***********************************************************************/
	RTC0ADR = ALARM1;
	RTC0DAT = (0x80 << ALARM1_ALARM1__SHIFT);
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit
	// [ALARM1 - RTC Alarm Programmed Value 1]$

	// $[ALARM2 - RTC Alarm Programmed Value 2]
	// [ALARM2 - RTC Alarm Programmed Value 2]$

	// $[ALARM3 - RTC Alarm Programmed Value 3]
	// [ALARM3 - RTC Alarm Programmed Value 3]$

	// $[RTC0CN - RTC Control]
	/***********************************************************************
	 - Enable RTC oscillator
	 ***********************************************************************/
	RTC0ADR = RTC0CN0;
	RTC0DAT = 0;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit

	RTC0ADR = RTC0CN0;
	RTC0DAT |= RTC0CN0_RTC0EN__ENABLED;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit

	// [RTC0CN - RTC Control]$

	// $[External Oscillator Setup]
	// Set the clock to a known value for the delay
	CLKSEL = CLKSEL_CLKSL__LPOSC | CLKSEL_CLKDIV__SYSCLK_DIV_128;

	// Delay for > 20 ms
	for (delayCounter = 0x150; delayCounter != 0; delayCounter--)
		;

	// Poll the SmaRTClock Clock Valid Bit (CLKVLD) until the crystal oscillator stabilizes
	do {
		RTC0ADR = RTC0ADR_BUSY__SET | RTC0ADR_ADDR__RTC0XCN0;
		while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
			;    //Poll Busy Bit
	} while ((RTC0DAT & RTC0XCN0_CLKVLD__BMASK) == RTC0XCN0_CLKVLD__NOT_SET);

	// Poll the SmaRTClock Load Capacitance Ready Bit (LOADRDY) until the load capacitance reaches its programmed value
	do {
		RTC0ADR = RTC0ADR_BUSY__SET | RTC0ADR_ADDR__RTC0XCF;
		while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
			;    //Poll Busy Bit
	} while ((RTC0DAT & RTC0XCF_LOADRDY__BMASK) == RTC0XCF_LOADRDY__NOT_SET);

	// Enable Automatic Gain Control (AGCEN) and disable Bias Doubling (BIASX2) for maximum power savings
	/***********************************************************************
	 - Crystal Mode selected
	 - Enable AGC
	 - Disable the Bias Double feature
	 - XMODE determines RTC oscillator source
	 ***********************************************************************/
	RTC0ADR = RTC0XCN0;
	RTC0DAT = RTC0XCN0_XMODE__CRYSTAL | RTC0XCN0_AGCEN__ENABLED
			| RTC0XCN0_BIASX2__DISABLED | RTC0XCN0_LFOEN__DISABLED;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit

	// Enable the SmaRTClock missing clock detector.
	RTC0ADR = RTC0CN0;

	// Delay for > 2 ms
	for (delayCounter = 0x100; delayCounter != 0; delayCounter--)
		;

	// Clear PMU wake-up source flags
	PMU0CF = PMU0CF_CLEAR__ALL_FLAGS;

	// Restore system clock
	CLKSEL = CLKSEL_save;
	// Poll CLKRDY to wait for the clock to stabilize
	while (!((CLKSEL & CLKSEL_CLKRDY__BMASK) == CLKSEL_CLKRDY__SET))
		;

	/***********************************************************************
	 - Enable RTC oscillator
	 - RTC timer is running
	 - Disable missing RTC detector
	 - Enable RTC alarm
	 - Alarm event flag is set or enable the auto reset function
	 - Do not start a capture operation
	 - Do not start a set operation
	 ***********************************************************************/
	RTC0ADR = RTC0CN0;
	RTC0DAT = RTC0CN0_RTC0EN__ENABLED | RTC0CN0_RTC0TR__RUN
			| RTC0CN0_MCLKEN__DISABLED | RTC0CN0_RTC0AEN__ENABLED
			| RTC0CN0_ALRM__SET | RTC0CN0_RTC0CAP__NOT_SET
			| RTC0CN0_RTC0SET__NOT_SET;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit

	// [External Oscillator Setup]$

}

//================================================================================
// CLOCK_0_enter_DefaultMode_from_RESET
//================================================================================
extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {

	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - SYSCLK is equal to selected clock source divided by 1
	 - Clock derived from the RTC
	 ***********************************************************************/
	CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__RTC;
	// Wait for the clock to be ready
	while ((CLKSEL & CLKSEL_CLKRDY__BMASK) != CLKSEL_CLKRDY__SET)
		;
	// [CLKSEL - Clock Select]$

}

extern void PMU_0_enter_DefaultMode_from_RESET(void) {

}

