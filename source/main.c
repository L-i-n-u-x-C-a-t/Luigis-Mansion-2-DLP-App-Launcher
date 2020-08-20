#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

int main(){

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("Luigi's Mansion Download Play App launcher\n"); 
	printf("Press A to launch the EUR app, B to launch the US app,\nand X to launch the JP app.\n");
	printf("Press L to see help\n");
	printf("Press START to exit\n");
	u8 helpison = 0;
	while (apt MainLoop()) {

		gspWaitForVBlank(); 
		gfxSwapBuffers(); 
		hidScanInput();

		u32 kDown = hidkeysDown();

		if (kDown & KEY_START) break;

		if (kDown & KEY_A){
			aptSetChainloader(0x0004000100076500, 0); //luigi's mansion DlP app - EUR
			break;
		}
		if (kDown & KEY_B){
			aptSetChainloader(0x0004000100055F00, 0); //luigi's mansion DlP app - US
			break;
		}
		if (kDown & KEY_X){
		aptSetChainloader(0x0004000100076400, 0); //luigi's mansion DlP app - JP
		break;
		}
	
	
		if (kDown & KEY_L){
			if (helpison == 0){
				printf("Q : Where can i find the Luigi's mansion Download\nPlay cia file?\n");
				printf("A : in the full game files, in the folder\n /content2.dlp/romfs/, or get it by downoading it using DlP\n");
				helpison = 1;
			}
		}
	}
	return 0;
}