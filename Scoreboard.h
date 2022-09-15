int blackscore = 0, whitescore = 0;
int scoreboardmode = 0;

GsBOXF WhiteBar = { .x = -SCREEN_XRES/2, .y = -SCREEN_YRES/2, .w = 320, .h = 64, .r = 255, .g = 255, .b = 255, .attribute = 0 };
GsBOXF BlackBar = { .x = 0, .y = -SCREEN_YRES/2, .w = 320, .h = 64, .r = 0, .g = 0, .b = 0, .attribute = 0 };

void DrawScoreboard() {
	char buffer[64];

	Font_ChangePositionY(-224);
	
	if(scoreboardmode)
		sprintf(buffer, SCOREBOARD_WHITES_TIME_FMT, whitescore / 60, (whitescore / 6) % 10);
	else
		sprintf(buffer, SCOREBOARD_WHITES_PTS_FMT, whitescore);
	
	GsSortBoxFill(&WhiteBar, &myOT[myActiveBuff], OT_ENTRIES - 1);		// As far away as possible
	Font_ChangeColor(0, 0, 0);
	Font_ChangePositionX(-300);
	Font_PrintString(buffer);
	
	if(scoreboardmode)
		sprintf(buffer, SCOREBOARD_BLACKS_TIME_FMT, blackscore / 60, (blackscore / 6) % 10);
	else
		sprintf(buffer, SCOREBOARD_BLACKS_PTS_FMT, blackscore);
	
	GsSortBoxFill(&BlackBar, &myOT[myActiveBuff], OT_ENTRIES - 1);		// As far away as possible
	Font_ChangeColor(255, 255, 255);
	Font_ChangePositionX(20);
	Font_PrintString(buffer);
}
