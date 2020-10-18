#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>


int main(){

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	amInit();
	cfguInit();

	
	bool helpison = false;
        bool refreshed = false; //there is probably an easier way to do this
	while (aptMainLoop()) {

		gspWaitForVBlank(); 
		gfxSwapBuffers(); 
		hidScanInput();

		u32 kDown = hidKeysDown();

		u8 output = 0;
		CFGU_SecureInfoGetRegion(&output);

		if (kDown & KEY_START) break;

		if (kDown & KEY_A){
			switch(output){
				case 0:
					aptSetChainloader(0x0004000100076400LL, 0); //luigi's mansion DlP app - JP
				case 1:
					aptSetChainloader(0x0004000100055F00LL, 0); //luigi's mansion DlP app - US
				case 2:
					aptSetChainloader(0x0004000100076500LL, 0); //luigi's mansion DlP app - EUR
				case 3:
					aptSetChainloader(0x0004000100076500LL, 0); //same as EUR, but it also work for AUS
				default:
					aptSetChainloader(0x0004000100076400LL, 0); //this is the JP one because idk what to put here

			}
			break;
		}

		if (helpison == true){
                    if (refreshed == false){
			consoleClear();
			printf("Q : Where can i find the Luigi's mansion Download\nPlay cia file?\n");
			printf("A : in the full game files, in the folder\n /content2.dlp/romfs/, or get it by downoading it using DlP\n");
			printf("\nNote: if the app doesn't start/crashes, create \nan issue in the github at bit.do/LMHissue");
                        refreshed = true;
                    }
		}
		else{
                    if (refreshed == false){
			consoleClear();
			printf("Luigi's Mansion 2 Download Play App launcher\n"); 
			printf("Press A to launch the multiplayer app.\n");
			printf("Press L to toggle help\n");
			printf("Press START to exit\n");
                        refreshed = true;
                    }
		}

		if (kDown & KEY_L){
			helpison = !helpison;
                        refreshed = false;
		}
			
		
	}
	return 0;
}
