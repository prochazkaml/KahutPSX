void PlayerScreen(int player) {
	int PadStatus, i = -630, intro = 35;
	
	char string[64];

	sprintf(string, PLAYER_SCREEN_MSG1_FMT, player + 1);
	
	do {
		i += intro;
		if(intro > 0) intro--;
		
		PadStatus = PadRead(0);
		
		PrepDisplay();
		
		Font_ChangeColor(255, 255, 255);
		
		Font_ChangePosition(i, -32);
		Font_PrintStringCentered(string);
		
		Font_ChangePosition(i, 0);
		Font_PrintStringCentered(PLAYER_SCREEN_MSG2);

		Font_ChangePosition(i, 32);
		Font_PrintStringCentered(PLAYER_SCREEN_MSG3);
		
		Font_ChangePosition(-160, -160);
		
		if(PadStatus & 0x0800) {
			Font_ChangeColor(128, 255, 128);
			Font_PrintStringCentered(PLAYER_SCREEN_OK);
		} else {
			Font_ChangeColor(255, 64, 64);
			Font_PrintStringCentered(PLAYER_SCREEN_WAITING);
		}

		Font_ChangePosition(160, -160);
		
		if(PadStatus & 0x08000000) {
			Font_ChangeColor(128, 255, 128);
			Font_PrintStringCentered(PLAYER_SCREEN_OK);
		} else {
			Font_ChangeColor(255, 64, 64);
			Font_PrintStringCentered(PLAYER_SCREEN_WAITING);
		}
		
		DrawScoreboard();
		
		Display();
	} while((-1-PadStatus) & 0x08000800);
}
