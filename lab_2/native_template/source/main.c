// main.c - main for the CECS 525 Raspberry PI kernel
// by Eugene Rockey Copyright 2015 All Rights Reserved
// debug everything that needs debugging
// Add, remove, modify, preserve in order to fulfill project requirements.

#include <stdint.h>
#include <stdlib.h>
#include "uart.h"
#include "mmio.h"
#include "bcm2835.h"
#include "can.h"
#include "softfloat.h"
#include "math.h"
#include "calculator.h"

#define SECS 0x00
#define MINS 0x01
#define HRS 0x02
#define DOM 0x04
#define MONTH 0x05
#define YEAR 0x06
#define ASECS 0x07
#define CR 0x0D
#define GPUREAD 0x2000B880
#define GPUPOLL 0x2000B890
#define GPUSENDER 0x2000B894
#define GPUSTATUS 0x2000B898
#define GPUCONFIG 0x2000B89C
#define GPUWRITE 0x2000B8A0

const char MS1[] = "\r\n\nCECS-525 Project 2 Demo";
const char MS2[] = "\r\nby Nicolas Mitchell, Abigail Spalding, Khem Guragai, Akash Nayak, Hunter Gray";
const char MS3[] = "\r\nReady: ";
const char MS4[] = "\r\nInvalid Command Try Again...";
const char GPUDATAERROR[] = "\r\nSystem Error: Invalid GPU Data";
const char LOGONNAME[] = "eugene    ";
const char PASSWORD[] = "cecs525   ";
//PWM Data for Alarm Tone
uint32_t N[200] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
				   36, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
				   70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 95, 94, 93, 92, 91, 90,
				   89, 88, 87, 86, 85, 84, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 60, 59, 58, 57,
				   56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,
				   22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
char logname[10];
char pass[10];
char *buffer[1];
char alarm[1];
uint8_t ones;
uint8_t tens;
char *tbuf;
char *rbuf;
void kernel_main(); //prototypes
void enable_arm_irq();
void disable_arm_irq();
void enable_arm_fiq();
void disable_arm_fiq();
void reboot();
void enable_irq_57();
void disable_irq_57();
void testdelay();
extern int invar; //assembly variables
extern int outvar;

//Pointers to some of the BCM2835 peripheral register bases
volatile uint32_t *bcm2835_gpio = (uint32_t *)BCM2835_GPIO_BASE;
volatile uint32_t *bcm2835_clk = (uint32_t *)BCM2835_CLOCK_BASE;
volatile uint32_t *bcm2835_pads = (uint32_t *)BCM2835_GPIO_PADS; //for later updates to program
volatile uint32_t *bcm2835_spi0 = (uint32_t *)BCM2835_SPI0_BASE;
volatile uint32_t *bcm2835_bsc0 = (uint32_t *)BCM2835_BSC0_BASE; //for later updates to program
volatile uint32_t *bcm2835_bsc1 = (uint32_t *)BCM2835_BSC1_BASE;
volatile uint32_t *bcm2835_st = (uint32_t *)BCM2835_ST_BASE;

void testdelay(void)
{
	int count = 0xFFFFF;
	while (count > 0)
	{
		count = count - 1;
	}
}

void enable_irq_57(void)
{
	mmio_write(0x2000B214, 0x02000000);
}

void disable_irq_57(void)
{
	mmio_write(0x2000B220, 0x02000000);
}

uint8_t ValidateGPUData(int data)
{
	if (data && 0b1111 != 0)
	{
		uart_puts(GPUDATAERROR);
		return 0;
	}
	return 1;
}

void GPUInit(void)
{
	int data;
	if (ValidateGPUData(data) == 1)
	{
		// Under Construction
	}
}

void banner(void)
{
	uart_puts(MS1);
	uart_puts(MS2);
}

uint8_t BCDtoUint8(uint8_t BCD)
{
	return (BCD & 0x0F) + ((BCD >> 4) * 10);
}

void RES(void)
{
	reboot();
}

void HELP(void) //Command List
{
	uart_puts("\r\n(A)dd, (S)ubtract, (M)ultiply, (D)ivide");
}

int read_number(void)
{
	uint8_t c = uart_readc();
	uint8_t neg = 0;
	if (c == '-')
	{
		neg = 1;
		c = uart_readc();
	}
	uint8_t digits[8];
	for (int i = 0; i < 8; i++)
	{
		digits[i] = -1;
	}
	int ind = 0;
	while (c != '\n')
	{
		digits[ind] = (c - 48);
		c = uart_readc();
		ind++;
	}
	int result = 0;
	for (int i = 0; i <= ind; i++)
	{
		int mult = 1;
		for (int j = 0; j < ind - i - 1; j++)
		{
			mult *= 10;
		}
		result += digits[i] * (mult);
	}
	if (neg == 1)
	{
		return result * -1;
	}
	return result;
}

void ADD(void)
{
	uart_puts("\r\nEnter number 1: ");
	int num1 = read_number();
	uart_puts("\r\nEnter number 2: ");
	int num2 = read_number();

	int res = add(num1, num2);
	char buf[9];
	itoa(buf, num1);
	uart_puts("\r\n");
	uart_puts(buf);
	uart_putc('+');
	itoa(buf, num2);
	uart_puts(buf);
	uart_puts(" = ");
	itoa(buf, res);
	uart_puts(buf);
}

void command(void)
{
	uart_puts(MS3);
	uint8_t c = '\0';
	while (c == '\0')
	{
		c = uart_readc();
	}
	switch (c)
	{
	case 'A' | 'a':
		break;
	case 'S' | 's':
		break;
	case 'M' | 'm':
		break;
	case 'D' | 'd':
		break;
	default:
		uart_puts(MS4);
		HELP();
		break;
	}
}

int logon(void)
{
	int success = 0;

	//Engineer the code here to LOGON to the system as was done with the MC68000 minimal computer.

	return success;
}

void kernel_main()
{
	uart_init();
	enable_irq_57();
	enable_arm_irq();
	//	if (logon() == 0) while (1) {}
	//	banner();
	//	HELP();
	//	while (1) {command();}

	while (1)
	{
		uart_putc(' ');
		uart_putc('A');
		uart_putc(' ');
		testdelay();
	}
}

void irq_handler(void)
{
	uint8_t c = uart_readc();
	uart_putc(' ');
	uart_putc(c);
	uart_putc(' ');
}
