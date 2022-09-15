void PointTimeScreen() {
	int PadStatus, cnt = -64, i, p1time, p2time, p1pts = whitescore, p2pts = blackscore;
	char buffer[16];
	
	Element Bars[] = {
		{ .type = BOX,  .x1 = -320, .y1 = -16,  .w = 320, .h = 64,  .r = 255, .g = 255, .b = 255, .depth = OT_ENTRIES - 1 },
		{ .type = BOX,  .x1 =  0,   .y1 = -16,  .w = 320, .h = 64,  .r = 0,   .g = 0,   .b = 0,   .depth = OT_ENTRIES - 1 },
		
		{ .type = END }
	};
	
	if(p1pts < p2pts) {
		p1time = 3600;
		p2time = p1time * p2pts / p1pts;
	} else {
		p2time = 3600;
		p1time = p2time * p1pts / p2pts;
	}
	
	do {
		if(cnt == 0) SpuSetKey(SPU_ON, POINTS_SFX);
		
		PrepDisplay();
		
		Font_ChangeColor(255, 255, 255);
		
		Font_ChangePosition(0, -64);
		Font_PrintStringCentered(PTTIME_SCREEN_MSG1);
		
		Font_ChangePosition(0, 64);
		Font_PrintStringCentered(PTTIME_SCREEN_MSG2);

		if(cnt >= 0)
			i = (p1time * cnt) >> 8;
		else
			i = 0;
		
		sprintf(buffer, "%d.%d s", i / 60, (i / 6) % 10);
		
		Font_ChangeColor(0, 0, 0);
		Font_ChangePosition(-160, 0);
		Font_PrintStringCentered(buffer);
		
		if(cnt >= 0)
			i = (p2time * cnt) >> 8;
		else
			i = 0;
		
		sprintf(buffer, "%d.%d s", i / 60, (i / 6) % 10);
		
		Font_ChangeColor(255, 255, 255);
		Font_ChangePosition(160, 0);
		Font_PrintStringCentered(buffer);
		
		if(cnt >= 0) {
			whitescore = (p1pts * (256 - cnt)) >> 8;
			blackscore = (p2pts * (256 - cnt)) >> 8;
		}
		
		if(cnt == 256) {
			Font_ChangePosition(0, 128);
			Font_PrintStringCentered(PTTIME_SCREEN_MSG3);
			Font_ChangePosition(0, 160);
			Font_PrintStringCentered(PTTIME_SCREEN_MSG4);
		}
		
		DrawElements(Bars, 0, 0);
		
		DrawScoreboard();
		
		Display();
		
		if(cnt < 256) {
			cnt++;
		} else {

			SpuSetKey(SPU_OFF, POINTS_SFX);

			PadStatus = PadRead(0);
			if(PadStatus & PADstart) break;
		}
	} while(1);
	
	whitescore = p1time;
	blackscore = p2time;
}
