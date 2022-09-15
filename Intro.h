void Intro() {
	int i, PadStatus, intro = 90;
	
	Element StageExplanation[] = {
		{ .type = BOX,  .x1 = -320, .y1 = -176, .w = 320, .h = 208, .r = 255, .g = 64,  .b = 64,  .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  0,   .y1 = -176, .w = 320, .h = 208, .r = 192, .g = 32,  .b = 32,  .depth = OT_ENTRIES - 1 },

		{ .type = BOX,  .x1 = -320, .y1 =  32,  .w = 320, .h = 208, .r = 64,  .g = 255, .b = 64,  .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  0,   .y1 =  32,  .w = 320, .h = 208, .r = 32,  .g = 192, .b = 32,  .depth = OT_ENTRIES - 1 },
		
		{ .type = TEXT, .x1 =  0,   .y1 = -156, .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = INTRO_FIRST_ROUND },
		{ .type = TEXT, .x1 =  0,   .y1 =  56,  .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = INTRO_SECOND_ROUND },
		
		{ .type = BOX,  .x1 = -310, .y1 = -94,  .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 = -246, .y1 = -94,  .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 = -182, .y1 = -94,  .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 = -118, .y1 = -94,  .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 = -56,  .y1 = -94,  .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },

		{ .type = BOX,  .x1 = -306, .y1 = -90,  .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 = -242, .y1 = -90,  .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 = -178, .y1 = -90,  .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 = -114, .y1 = -90,  .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 = -52,  .y1 = -90,  .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },
		
		{ .type = BOX,  .x1 =  266, .y1 = -94,  .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 =  202, .y1 = -94,  .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 =  138, .y1 = -94,  .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 =  74,  .y1 = -94,  .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 =  10,  .y1 = -94,  .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },

		{ .type = BOX,  .x1 =  270, .y1 = -90,  .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 =  206, .y1 = -90,  .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 =  142, .y1 = -90,  .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 =  78,  .y1 = -90,  .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		{ .type = BOX,  .x1 =  14,  .y1 = -90,  .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		
		{ .type = BOX,  .x1 = -182, .y1 =  114, .w = 44,  .h = 44,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 = -178, .y1 =  118, .w = 36,  .h = 36,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 4 },

		{ .type = BOX,  .x1 =  138, .y1 =  114, .w = 44,  .h = 44,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 3 },
		{ .type = BOX,  .x1 =  142, .y1 =  118, .w = 36,  .h = 36,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 4 },
		
		
		{ .type = BOX,  .x1 = -310, .y1 = -73,  .w = 290, .h = 4,   .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },
		{ .type = BOX,  .x1 =  14,  .y1 = -73,  .w = 290, .h = 4,   .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },

		{ .type = BOX,  .x1 = -161, .y1 = -94,  .w = 4,   .h = 208, .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },
		{ .type = BOX,  .x1 =  159, .y1 = -94,  .w = 4,   .h = 208, .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },
		
		{ .type = BOX,  .x1 = -182, .y1 =  135, .w = 320, .h = 4,   .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },
	
		{ .type = BOX,  .x1 = -2,   .y1 =  135, .w = 4,   .h = 43,  .r = 64,  .g = 64,  .b = 64,  .depth = OT_ENTRIES - 2 },
	
		{ .type = BOX,  .x1 = -100, .y1 =  178, .w = 200, .h = 52,  .r = 255, .g = 255, .b = 0,   .depth = OT_ENTRIES - 3 },
		{ .type = TEXT, .x1 =  0,   .y1 =  188, .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = INTRO_WINNER },
		
		{ .type = END }
	};
	
	GsDOBJ2 Object;
	VECTOR obj_pos1 = {0};
	VECTOR obj_pos2 = {0};
	SVECTOR obj_rot = {0};
	
	Camera.pos.vx = 0;
	Camera.pos.vy = 100;
	Camera.pos.vz = 1420;
	Camera.rot.vy = 0;
	Camera.rot.vx = 100;

	// Link the TMD model
	LinkModel((u_long*)assets_ARROW_TMD, &Object);		// The test model
	
	Object.attribute = 0;		// Re-enable lighting for the test model
	
	// Object positions
	obj_pos1.vx = -700 - 4095;
	obj_pos2.vx = 700 - 4095;

	do {
		PadStatus = PadRead(0);
		
		if(PadStatus) break;
		
		PrepDisplay();
		
		DrawScoreboard();
		
		Display();
	} while(1);

	// Show the arrows
	do {
		PadStatus = PadRead(0);
		
		if(intro > 0) {
			obj_pos1.vx += intro;
			obj_pos2.vx += intro;
			intro--;
		}
		
		if((intro == 0) && PadStatus) intro = -1;
		
		if(intro < 0) {
			obj_pos1.vx -= intro;
			obj_pos2.vx -= intro;
			intro--;
		}
		
		PrepDisplay();
		
		DrawScoreboard();
		
		// Calculate the camera and viewpoint matrix
		CalculateCamera();
		
		// Set the light source
		GsSetFlatLight(0, &pslt);
		
		// Rotate the object
		obj_rot.vy += 16;

		// Sort the arrows
		PutObject(obj_pos1, obj_rot, &Object);
		PutObject(obj_pos2, obj_rot, &Object);
		
		Display();
	} while(intro > -90);
	
	i = -528;
	intro = -32;
	
	do {
		PadStatus = PadRead(0);

		if(intro < 0) {
			i -= intro;
			intro++;
		}

		if((intro == 0) && PadStatus) break;

		PrepDisplay();
		
		DrawScoreboard();
		
		DrawElements(StageExplanation, i, 0);
		
		Display();
	} while(intro < 128);
	
	i = -528;
	intro = -32;
	
	do {
		PadStatus = PadRead(0);

		if(intro < 0) {
			i -= intro;
			intro++;
		}

		if((intro == 0) && PadStatus) break;

		PrepDisplay();
		
		DrawScoreboard();
		
		DrawElements(Answers, i, 0);
		
		Font_ChangePosition(i, -114);
		Font_PrintStringCentered(INTRO_QUESTION_PLACEMENT);
		
		Display();
	} while(intro < 128);
	
	Sound_CD_Stop();
}
