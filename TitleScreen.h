void TitleScreen() {
	int i, PadStatus, playing = 0, intro = 128;

	Player_t Player;
	
	GsDOBJ2 Object;
	VECTOR	obj_pos={0};
	SVECTOR	obj_rot={0};
	
	// Link the TMD model
	LinkModel((u_long*)assets_LOGO_TMD, &Object);
	
	Object.attribute = 0;		// Re-enable lighting
	
	Player.pan = 0;
	Player.til = -100;
	
	// Default camera/player position
	Player.x = ONE * 0;
	Player.y = ONE * 100 - csin(Player.til) * 128 * 128;
	Player.z = ONE * 1420 + ccos(Player.til) * 128 * 128;
	
	// Object positions
	obj_rot.vy = 2048;

	for(i = 0; i < 256; i++) {
		PrepDisplay();
		
		if(i < 64)
			Font_ChangeColorWithOpacity(255, 255, 255, 0, 0, 0, i << 2);
		else if(i < 192)
			Font_ChangeColor(255, 255, 255);
		else
			Font_ChangeColorWithOpacity(255, 255, 255, 0, 0, 0, (256 - i) << 2);
	
		Font_ChangePosition(0, -32);
		Font_PrintStringCentered(TITLE_SCREEN_CARD1_MSG1);
		Font_ChangePosition(0, 0);
		Font_PrintStringCentered(TITLE_SCREEN_CARD1_MSG2);
		
		Display();
	}
	
	for(i = 0; i <= 256; i++) {
		PrepDisplay();
		
		if(i < 64)
			Font_ChangeColorWithOpacity(255, 255, 255, 0, 0, 0, i << 2);
		else if(i < 192)
			Font_ChangeColor(255, 255, 255);
		else {
			Font_ChangeColorWithOpacity(255, 255, 255, (70 * BG_Brightness) >> 8, (23 * BG_Brightness) >> 8, (143 * BG_Brightness) >> 8, (256 - i) << 2);
			BG_Brightness = (i - 192) << 2;
		}
			
		Font_ChangePosition(0, -32);
		Font_PrintStringCentered(TITLE_SCREEN_CARD2_MSG1);
		Font_ChangePosition(0, 0);
		Font_PrintStringCentered(TITLE_SCREEN_CARD2_MSG2);
		
		Display();
	}
	
	while(intro > -128) {
		PadStatus = PadRead(0);
		
		if(PadStatus & PADstart) intro = -2;

		// Nice zoom effect
		if(intro > 0) {
			Player.y += csin(Player.til) * 128;
			Player.z -= ccos(Player.til) * 128;
			intro--;
			
			// Start the soundtrack if we're done
			if(intro == 0) Sound_CD_Play(3, CD_REPEAT);
		}

		if(intro < 0) {
			obj_pos.vx += intro;
			
			SpuSetCommonCDVolume(MAX_VOLUME + intro * 112, MAX_VOLUME + intro * 112);
			
			intro -= 2;

			WhiteBar.h = -intro / 2;
			BlackBar.h = -intro / 2;			
		}
		
		// Translate player coordinates for the camera
		Camera.pos.vx = Player.x/ONE;
		Camera.pos.vy = Player.y/ONE;
		Camera.pos.vz = Player.z/ONE;
		Camera.rot.vy = -Player.pan;
		Camera.rot.vx = -Player.til;
		
		// Prepare for rendering
		PrepDisplay();
		
		// Calculate the camera and viewpoint matrix
		CalculateCamera();
		
		// Set the light source
		GsSetFlatLight(0, &pslt);
		
		// Rotate the object
		obj_rot.vy += 16;
		
		// Sort our test object
		PutObject(obj_pos, obj_rot, &Object);
		
		// Display the text
		if(intro <= 0) {
			Font_ChangeColorWithOpacity(255, 255, 255, 70, 23, 143, 256 + intro * 2);
		
			Font_ChangePosition(0, -150);
			Font_PrintStringCentered(TITLE_SCREEN_WELCOME);
			Font_ChangePosition(0, 100);
			Font_PrintStringCentered(TITLE_SCREEN_MSG1);
			Font_ChangePosition(0, 132);
			Font_PrintStringCentered(TITLE_SCREEN_MSG2);
		}
		
		// Start displaying the scoreboard
		if(intro < 0) {
			GsSortBoxFill(&WhiteBar, &myOT[myActiveBuff], OT_ENTRIES - 1);		// As far away as possible
			GsSortBoxFill(&BlackBar, &myOT[myActiveBuff], OT_ENTRIES - 1);
		}
		
		// Display the new frame
		Display();
	}
	
	PrepDisplay();
	DrawScoreboard();
	Display();
	
//	Sound_CD_Stop();
}
