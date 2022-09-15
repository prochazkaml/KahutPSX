int currentsong = 0;
int currentquestion = 0;

Element Answers[] = {
	{ .type = TEXT, .x1 = 0,    .y1 = -21,  .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = QUIZ_SCREEN_RESP_A },
	{ .type = TEXT, .x1 = 0,    .y1 =  39,  .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = QUIZ_SCREEN_RESP_B },
	{ .type = TEXT, .x1 = 0,    .y1 =  99,  .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = QUIZ_SCREEN_RESP_C },
	{ .type = TEXT, .x1 = 0,    .y1 =  159, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = QUIZ_SCREEN_RESP_D },
	
	{ .type = BOX,  .x1 = -310, .y1 = -30,  .w = 620, .h = 50,  .r = 64,  .g = 255, .b = 64,  .depth = OT_ENTRIES - 1 },
	{ .type = BOX,  .x1 = -310, .y1 =  30,  .w = 620, .h = 50,  .r = 255, .g = 64,  .b = 255, .depth = OT_ENTRIES - 1 },
	{ .type = BOX,  .x1 = -310, .y1 =  90,  .w = 620, .h = 50,  .r = 255, .g = 32,  .b = 32,  .depth = OT_ENTRIES - 1 },
	{ .type = BOX,  .x1 = -310, .y1 =  150, .w = 620, .h = 50,  .r = 32,  .g = 32,  .b = 255, .depth = OT_ENTRIES - 1 },

	{ .type = SPRT, .x1 = -301, .y1 = -21,  .w = 32,  .h = 32,  .x2 = 0,  .y2 = 0,  .tp = 14, .depth = OT_ENTRIES - 2, .cx = 960, .cy = 1 },
	{ .type = SPRT, .x1 = -301, .y1 =  39,  .w = 32,  .h = 32,  .x2 = 32, .y2 = 0,  .tp = 14, .depth = OT_ENTRIES - 2, .cx = 960, .cy = 1 },
	{ .type = SPRT, .x1 = -301, .y1 =  99,  .w = 32,  .h = 32,  .x2 = 64, .y2 = 0,  .tp = 14, .depth = OT_ENTRIES - 2, .cx = 960, .cy = 1 },
	{ .type = SPRT, .x1 = -301, .y1 =  159, .w = 32,  .h = 32,  .x2 = 96, .y2 = 0,  .tp = 14, .depth = OT_ENTRIES - 2, .cx = 960, .cy = 1 },
	
	{ .type = END }
};

void QuizScreen(Question question, int stage) {
	int ctr, x, i, PadStatus, p1ans = 0, p2ans = 0, p1time = 0, p2time = 0;
	
	char buffer[16];
	
	char randomtable[24][4] = {
		{ 1, 2, 3, 4 }, { 1, 2, 4, 3 }, { 1, 3, 2, 4 }, { 1, 3, 4, 2 }, { 1, 4, 2, 3 }, { 1, 4, 3, 2 },
		{ 2, 1, 3, 4 }, { 2, 1, 4, 3 }, { 2, 3, 1, 4 }, { 2, 3, 4, 1 }, { 2, 4, 1, 3 }, { 2, 4, 3, 1 },
		{ 3, 2, 1, 4 }, { 3, 2, 4, 1 }, { 3, 1, 2, 4 }, { 3, 1, 4, 2 }, { 3, 4, 2, 1 }, { 3, 4, 1, 2 },
		{ 4, 2, 3, 1 }, { 4, 2, 1, 3 }, { 4, 3, 2, 1 }, { 4, 3, 1, 2 }, { 4, 1, 2, 3 }, { 4, 1, 3, 2 },
	};
	
	char randomsongtable[15] = { 1, 2, 3, 2, 2, 1, 3, 1, 1, 3, 2, 3, 1, 3, 2 };
	
	Element QuestionPrecard[] = {
		{ .type = TEXT, .x1 =  0,   .y1 =  -32, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = QUIZ_SCREEN_GETREADY },
		{ .type = TEXT, .x1 =  0,   .y1 =   32, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = question.qtext },
		{ .type = TEXT, .x1 =  0,   .y1 =   64, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = question.qtext2 },

		{ .type = END }
	};
	
	Element GoodAnswer[] = {
		{ .type = TEXT, .x1 =  160, .y1 =  0,   .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = buffer },

		{ .type = BOX,  .x1 =  0,   .y1 = -176, .w = 320, .h = 320, .r = 32,  .g = 255, .b = 32,  .depth = OT_ENTRIES - 1 },
		{ .type = TEXT, .x1 =  160, .y1 = -64,  .align = CENTER,    .r = 0,   .g = 0,   .b = 0,   .text = QUIZ_SCREEN_PERFECT },
		{ .type = END }
	};

	Element BadAnswer[] = {
		{ .type = BOX,  .x1 =  0,   .y1 = -176, .w = 320, .h = 320, .r = 255, .g = 32,  .b = 32,  .depth = OT_ENTRIES - 1 },
		{ .type = TEXT, .x1 =  160, .y1 = -32,  .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = QUIZ_SCREEN_TOO_BAD },
		{ .type = END }
	};

	Element CorrectAnswer[] = {
		{ .type = TEXT, .x1 =  0,   .y1 =  160, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = QUIZ_SCREEN_CORRECT_RESPONSE },
		{ .type = TEXT, .x1 =  0,   .y1 =  192, .align = CENTER,    .r = 255, .g = 255, .b = 255, .text = question.ans[0] },
		{ .type = END }
	};
	
	GsBOXF Counter = { .attribute = 0, .x = -320, .y = 210, .h = 30, .r = 255, .g = 255, .b = 255 };

	scoreboardmode = stage;
	
	x = rand() % 24;

	for(i = 0; i < 4; i++) {
		Answers[i].text = question.ans[randomtable[x][i] - 1];
	}
	
	if(!stage) {
		i = randomsongtable[currentsong++] - 1;
		
		SpuSetTransferStartAddr(SPU_QUIZSONG_ADDR);
		SpuWrite(quizsongs[i], quizsonglen[i]);
	
		currentsong %= 15;
	
		i = -630;
		
		for(ctr = 0; ctr < 300; ctr++) {
			PrepDisplay();
			
			if(ctr < 36) i += (35 - ctr);

			DrawElements(QuestionPrecard, i, 0);		
			
			Counter.w = ctr * 640 / 300;
			GsSortBoxFill(&Counter, &myOT[myActiveBuff], 0);
			
			DrawScoreboard();
			
			Display();
		}
		
		SpuIsTransferCompleted(SPU_TRANSFER_WAIT);
		
		SpuSetKey(SPU_ON, QUIZSONG_SFX);
	}

	for(ctr = 600; ctr > 0; ctr -= (stage ? 0 : 1)) {
		PadStatus = PadRead(0);		// haha "PadRead is for prototyping purposes only" my arse
		
		if(p1ans == 0) {
			if(PadStatus & PADRup)    p1ans = randomtable[x][0];
			if(PadStatus & PADRleft)  p1ans = randomtable[x][1];
			if(PadStatus & PADRright) p1ans = randomtable[x][2];
			if(PadStatus & PADRdown)  p1ans = randomtable[x][3];

			if(p1ans) {
				SpuSetKey(SPU_ON, ANSWER_SFX);
			}
			
			if(p1ans == 1) {
				p1time = ctr;
			}
		}
		
		PadStatus >>= 16;
		
		if(p2ans == 0) {
			if(PadStatus & PADRup)    p2ans = randomtable[x][0];
			if(PadStatus & PADRleft)  p2ans = randomtable[x][1];
			if(PadStatus & PADRright) p2ans = randomtable[x][2];
			if(PadStatus & PADRdown)  p2ans = randomtable[x][3];
		
			if(p2ans) {
				SpuSetKey(SPU_ON, ANSWER_SFX);
			}
			
			if(p2ans == 1) {
				p2time = ctr;
			}
		}
		
		if(stage) {
			if(!p1ans) whitescore--;
			if(!p2ans) blackscore--;
			
			if(!whitescore || !blackscore) goto end;
		}
		
		if(p1ans && p2ans) break;
		
		PrepDisplay();
		
		i = -130;
		
		if(!*question.qtext2) i += 16;

		Font_ChangePosition(0, i);
		Font_PrintStringCentered(question.qtext);
		Font_ChangePosition(0, i + 32);
		Font_PrintStringCentered(question.qtext2);
		
		DrawElements(Answers, 0, 0);
		
		if(!stage)
			Counter.w = ctr * 640 / 600;
		else
			Counter.w = currentquestion * 640 / NUM_OF_QUESTIONS;

		GsSortBoxFill(&Counter, &myOT[myActiveBuff], 0);
		
		DrawScoreboard();
		
		Display();
	}
	
	SpuSetKey(SPU_ON, QUIZEND_SFX);
	SpuSetKey(SPU_OFF, ANSWER_SFX | QUIZSONG_SFX);

	if(!stage) {
		p1time = p1time * 1000 / 600;
		p2time = p2time * 1000 / 600;
		
		whitescore += p1time;
		blackscore += p2time;
		
		i = 120;
		
		do {
			PadStatus = PadRead(0);
			
			if(i)
				i--;
			else if(PadStatus)
				break;

			PrepDisplay();

			DrawScoreboard();
			
			sprintf(buffer, QUIZ_SCREEN_PTS_ADD_FMT, p1time);
			
			if(p1ans == 1)
				DrawElements(GoodAnswer, -320, 0);
			else
				DrawElements(BadAnswer, -320, 0);

			sprintf(buffer, QUIZ_SCREEN_PTS_ADD_FMT, p2time);
			
			if(p2ans == 1)
				DrawElements(GoodAnswer, 0, 0);
			else
				DrawElements(BadAnswer, 0, 0);
			
			DrawElements(CorrectAnswer, 0, 0);
			
			Display();
		} while(1);
	} else {
		if(p1time) whitescore += 120; else whitescore -= 240;
		if(p2time) blackscore += 120; else blackscore -= 240;

		if(whitescore <= 0 || blackscore <= 0) goto end;
		
		for(ctr = 0; ctr < 128; ctr++) {
			PrepDisplay();
			
			i = -130;
			
			if(!*question.qtext2) i += 16;

			Font_ChangePosition(0, i);
			Font_PrintStringCentered(question.qtext);
			Font_ChangePosition(0, i + 32);
			Font_PrintStringCentered(question.qtext2);
			
			Font_ChangeColorWithOpacity(255, 255, 255, 70, 23, 143, 256 - (ctr << 1));

			i = -160 + (ctr >> 2);

			sprintf(buffer, "%c%d s", p1time ? '+' : '-', p1time ? 2 : 4);
			Font_ChangePosition(-300, i);
			Font_PrintString(buffer);
			
			sprintf(buffer, "%c%d s", p2time ? '+' : '-', p2time ? 2 : 4);
			Font_ChangePosition(300, i);
			Font_PrintStringRTL(buffer);
			
			DrawElements(Answers, 0, 0);

			GsSortBoxFill(&Counter, &myOT[myActiveBuff], 0);

			DrawScoreboard();
			
			Display();
		}
	}

	SpuSetKey(SPU_OFF, QUIZEND_SFX);
	return;
	
end:
	SpuSetKey(SPU_OFF, SPU_ALLCH);
	
	for(ctr = 127; ctr >= 0; ctr--) {
		BG_Brightness = ctr << 1;

		SpuSetCommonCDVolume(ctr << 7, ctr << 7);
		
		PrepDisplay();
		
		Display();
	}
	
	Sound_CD_Stop();
}
