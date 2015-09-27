#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "firmware_tools.h"

int main(int argc, char const *argv[])
{
	int choice;
	system("clear");
	ipswDownloader();
	
	system("clear");
	printf("Which file you want to decrypt ?\n");
	printf(" 1) Root Filesystem\n");
	printf(" 2) Update Ramdisk\n");
	printf(" 3) Restore Ramdisk\n");
	printf(" 4) AppleLogo\n");
	printf(" 5) BatteryCharging0\n");
	printf(" 6) BatteryCharging1\n");
	printf(" 7) BatteryFull\n");
	printf(" 8) BatteryLow0\n");
	printf(" 9) BatteryLow1\n");
	printf("10) DeviceTree\n");
	printf("11) GlyphPlugin\n");
	printf("12) iBEC\n");
	printf("13) iBoot\n");
	printf("14) iBSS\n");
	printf("15) Kernelcache\n");
	printf("16) LLB\n");
	printf("17) RecoveryMode\n");
	printf("18) Print manifest\n");
	printf("19) Options\n");
	printf("Command : ");
	choice = fgetn();

	switch (choice)
	{
		case 1 : rootfs(); break;
		case 2 : Ramdisk(); break;
		case 3 : Ramdisk(); break;
		case 4 : IMG3(); break;
		case 5 : IMG3(); break; 
		case 6 : IMG3(); break;
		case 7 : IMG3(); break;
		case 8 : IMG3(); break;
		case 9 : IMG3();; break;
		case 10 : IMG3(); break;
		case 11 : IMG3(); break;
		case 12 : IMG3(); break;
		case 13 : IMG3(); break;
		case 14 : IMG3(); break;
		case 15 : IMG3(); break;
		case 16 : IMG3(); break;
		case 17 : IMG3(); break;
		case 18 : manifest(); break;
		case 19 : options(); break;
		default : printf("No option available yet\n"); 
	}	
}
