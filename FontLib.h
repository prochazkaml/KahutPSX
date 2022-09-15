GsSPRITE Letter = { .x = 0, .y = 0, .w = 32, .h = 32, .tpage = 10, .u = 32, .v = 0, .cx = 960, .cy = 0, .r = 128, .g = 128, .b = 128, .attribute = 0 };

int base_x = 0, base_y = 0, kerning = 3, lefttoright = 1;

#define Font_ChangeKerning(i) kerning = i
#define Font_ChangePositionX(i) Letter.x = i
#define Font_ChangePositionY(i) Letter.y = i

char FontWidth[256] = {
	0,	20,	20,	20,	20,	20,	14,	20,	20,	20,	20,	20,	20,	20,	20,	12,
	12,	28,	20,	20,	20,	20,	20,	20,	20,	20,	0,	0,	0,	0,	0,	0,
	4,	4,	16,	20,	20,	20,	20,	8,	16,	16,	16,	20,	4,	20,	4,	20,
	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	4,	4,	20,	20,	20,	20,
	24,	20,	20,	20,	20,	20,	20,	20,	20,	12,	20,	20,	20,	20,	20,	20,
	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	12,	20,	12,	20,	20,
	8,	20,	20,	20,	20,	20,	16,	20,	20,	4,	20,	16,	8,	20,	20,	20,
	20,	20,	20,	20,	12,	20,	20,	20,	20,	20,	20,	16,	4,	16,	24,	24,
	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	12,	10,	9,	20,	20,
	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	12,	20,
	20,	9,	20,	20,	20,	20,	20,	20,	20,	24,	20,	20,	20,	4,	20,	20,
	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,
	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,
	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,	32,
	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	24,	20,	30,	30,	20,	20,
	20,	20,	20,	20,	10,	10,	20,	24,	13,	6,	10,	27,	11,	11,	32,	0
};

void Font_ChangeColor(int r, int g, int b) {
	Letter.r = r >> 1;
	Letter.g = g >> 1;
	Letter.b = b >> 1;
}

void Font_ChangeColorWithOpacity(int r, int g, int b, int bg_r, int bg_g, int bg_b, int op) {
	Letter.r = (r * op + bg_r * (256 - op)) >> 9;
	Letter.g = (g * op + bg_g * (256 - op)) >> 9;
	Letter.b = (b * op + bg_b * (256 - op)) >> 9;
}

void Font_ChangePosition(int x, int y) {
	Letter.x = x;
	Letter.y = y;

	base_x = x;
	base_y = y;
}

void Font_ResetPos() {
	Letter.x = base_x;
	Letter.y = base_y;
}

void Font_PutChar(u_char c) {
	if(c == '\n') {
		Letter.x = base_x;
		Letter.y += 32;
	} else if(c) {
		Letter.tpage = ((c & 8) ? 11 : 10) + ((c & 128) ? 2 : 0);

		Letter.u = (c & 7) << 5;
		Letter.v = (c >> 4) << 5;
		
		if(lefttoright) {
			GsSortFastSprite(&Letter, &myOT[myActiveBuff], 0);
			
			Letter.x += FontWidth[c] + kerning;
		} else {
			Letter.x -= FontWidth[c];

			GsSortFastSprite(&Letter, &myOT[myActiveBuff], 0);
			
			Letter.x -= kerning;
		}
	}
}

void Font_PrintString(u_char *str) {
	u_char c;
	
	do {
		c = *str++;
		Font_PutChar(c);
	} while(c);
}

void Font_PrintStringCentered(u_char *str) {
	u_char c;
	u_char *old = str;
	int ctr = 0;
	
	do {
		c = *str++;
		if(c) ctr += FontWidth[c] + kerning;
	} while(c);
	
	Letter.x -= (ctr - kerning) / 2;
	
	Font_PrintString(old);
}

void Font_PrintStringRTL(u_char *str) {
	u_char c;
	u_char *old = str;

	lefttoright = 0;
	
	do {
		c = *str++;
	} while(c);
	
	do {
		c = *--str;
		Font_PutChar(c);
	} while(str != old);
	
	lefttoright = 1;
}
