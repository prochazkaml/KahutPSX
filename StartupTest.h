void StartupTest() {
	int PadStatus;
	
	Element Bars[] = {
		{ .type = BOX,  .x1 = -320, .y1 = -240, .w = 80,  .h = 480, .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 = -240, .y1 = -240, .w = 80,  .h = 480, .r = 255, .g = 255, .b = 0,   .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 = -160, .y1 = -240, .w = 80,  .h = 480, .r = 0,   .g = 255, .b = 255, .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 = -80,  .y1 = -240, .w = 80,  .h = 480, .r = 0,   .g = 255, .b = 0,   .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  0,   .y1 = -240, .w = 80,  .h = 480, .r = 255, .g = 0,   .b = 255, .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  80,  .y1 = -240, .w = 80,  .h = 480, .r = 255, .g = 0,   .b = 0,   .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  160, .y1 = -240, .w = 80,  .h = 480, .r = 0,   .g = 0,   .b = 255, .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  240, .y1 = -240, .w = 80,  .h = 480, .r = 32,  .g = 32,  .b = 32,  .depth = OT_ENTRIES - 1 },

		{ .type = BOX,  .x1 = -320, .y1 = -48,  .w = 640, .h = 96,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 2 },
		
		{ .type = TEXT, .x1 =  0,   .y1 = -32,  .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = STARTUP_TEST_MSG1 },
		{ .type = TEXT, .x1 =  0,   .y1 =  0,   .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = STARTUP_TEST_MSG2 },
		
		{ .type = END }
	};
	
	do {
		PadStatus = PadRead(0);
		
		PrepDisplay();
		
		DrawElements(Bars, 0, 0);
		
		Display();
	} while((-1-PadStatus) & PADstart);
}
