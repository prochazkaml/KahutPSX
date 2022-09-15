void WinnerScreen() {
	int i, PadStatus, playing = 0, intro = 128;

	Player_t Player;
	
	char buffer[64];
	
	GsDOBJ2 Object;
	VECTOR	obj_pos={0};
	SVECTOR	obj_rot={0};
	
	// Link the TMD model
	LinkModel((u_long*)assets_TROPHY_TMD, &Object);		// The test model
	
	Object.attribute = 0;		// Re-enable lighting for the test model
	
	Player.pan = 0;
	Player.til = 0;
	
	// Default camera/player position
	Player.x = ONE * 0;
	Player.y = ONE * 0 - csin(Player.til) * 128 * 128;
	Player.z = ONE * 1420 + ccos(Player.til) * 128 * 128;
	
	// Light color
	pslt.r = 0xff; pslt.g = 0xff; pslt.b = 0x00;

	// Object positions
	obj_rot.vy = 2048;

	BG_Brightness = 0;
	
	sprintf(buffer, WINNER_SCREEN_WINMSG_FMT, (blackscore > whitescore) ?
		WINNER_SCREEN_WINMSG_BLACKS :
		WINNER_SCREEN_WINMSG_WHITES);
		
	Font_ChangeColor(255, 255, 255);

	do {
		// Nice zoom effect
		if(intro > 0) {
			Player.y += csin(Player.til) * 128;
			Player.z -= ccos(Player.til) * 128;
			intro--;
		}

		if(intro == 0) {
			// Play the sound if we're done
			SpuSetKey(SPU_ON, WINNER_SFX);
			intro--;
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
		if(intro < 0) {
			Font_ChangePosition(0, -150);
			Font_PrintStringCentered(buffer);
			Font_ChangePosition(0, 132);
			Font_PrintStringCentered(WINNER_SCREEN_WINMSG_2);
		}
		
		// Display the new frame
		Display();
	} while(1);
}
