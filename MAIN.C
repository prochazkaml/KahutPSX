#include <sys/types.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libspu.h>
#include <libcd.h>

#include "l10n/French.h"
#include "Assets.h"
#include "Questions.h"

#define SPU_ANSWER_ADDR 0x1010
#define SPU_POINTS_ADDR (SPU_ANSWER_ADDR + assets_ANSWER_VAG_len)
#define SPU_WINNER_ADDR (SPU_POINTS_ADDR + assets_POINTS_VAG_len)
#define SPU_QUIZEND_ADDR (SPU_WINNER_ADDR + assets_WINNER_VAG_len)
#define SPU_QUIZSONG_ADDR (SPU_QUIZEND_ADDR + assets_QUIZEND_VAG_len)

unsigned char *quizsongs[3] = { assets_QUIZ1_VAG, assets_QUIZ2_VAG, assets_QUIZ3_VAG };
unsigned int quizsonglen[3] = { assets_QUIZ1_VAG_len, assets_QUIZ2_VAG_len, assets_QUIZ3_VAG_len };

#define ANSWER_SFX SPU_0CH
#define POINTS_SFX SPU_1CH
#define WINNER_SFX SPU_2CH
#define QUIZEND_SFX SPU_3CH
#define QUIZSONG_SFX SPU_4CH

#include "Common.h"
#include "CdLib.h"
#include "FontLib.h"
#include "SysLib.h"
#include "3DLib.h"
#include "DrawLib.h"

#include "Scoreboard.h"
#include "QuizScreen.h"
#include "TitleScreen.h"
#include "WinnerScreen.h"
#include "PlayerScreen.h"
#include "PointTimeScreen.h"
#include "Intro.h"
#include "StartupTest.h"

int main() {
	int player, question;
	
	init();

	StartupTest();
	
	TitleScreen();

	Intro();
	
	srand(GsGetVcount());		// cheap, but effective

	for(player = 0; player < 5; player++) {
 		PlayerScreen(player);
		
		for(question = 0; question < 3; question++) {
			QuizScreen(questions[player + question * 5], 0);
		}
	}

	if(blackscore > 0 && whitescore > 0) {
		PointTimeScreen();
		
		SpuSetCommonCDVolume(MAX_VOLUME, MAX_VOLUME);
		Sound_CD_Play(2, CD_REPEAT);
		
		while(blackscore > 0 && whitescore > 0 && currentquestion < NUM_OF_QUESTIONS)
			QuizScreen(questions[((currentquestion++) + 15) % NUM_OF_QUESTIONS], 1);
	}
	
	WinnerScreen();
}
