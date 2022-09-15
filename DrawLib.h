#define LINE 0
#define BOX 1
#define TEXT 2
#define SPRT 3

#define END -1

#define LEFT 0
#define CENTER 1
#define RIGHT 2

typedef struct {
	u_char r, g, b, align;
	short type, x1, y1, x2, y2, depth, w, h, tp, cx, cy;
	u_char *text;
} Element;

void (*texthandler[3]) (u_char *str) = { Font_PrintString, Font_PrintStringCentered, Font_PrintStringRTL };

void DrawElement(Element element, int ox, int oy) {
	GsLINE Line = { .attribute = 0, .x0 = element.x1 + ox, .x1 = element.x2 + ox, .y0 = element.y1 + oy, .y1 = element.y2 + oy, .r = element.r, .g = element.g, .b = element.b };
	GsBOXF Box = { .attribute = 0, .x = element.x1 + ox, .y = element.y1 + oy, .w = element.w, .h = element.h, .r = element.r, .g = element.g, .b = element.b };
	GsSPRITE Sprite = { .attribute = 0, .x = element.x1 + ox, .y = element.y1 + oy, .w = element.w, .h = element.h, .r = 128, .g = 128, .b = 128, .tpage = element.tp, .cx = element.cx, .cy = element.cy, .u = element.x2, .v = element.y2 }; 
	
	switch(element.type) {
		case 0:
			GsSortLine(&Line, &myOT[myActiveBuff], element.depth);
			break;
			
		case 1:
			GsSortBoxFill(&Box, &myOT[myActiveBuff], element.depth);
			break;
			
		case 2:
			Font_ChangeColor(element.r, element.g, element.b);
			Font_ChangePosition(element.x1 + ox, element.y1 + oy);
			
			(*texthandler[element.align]) (element.text);
			break;

		case 3:
			GsSortFastSprite(&Sprite, &myOT[myActiveBuff], element.depth);
			break;
			
	}
}

void DrawElements(Element *element, int ox, int oy) {
	int i = 0;

	while(element[i].type != END)
		DrawElement(element[i++], ox, oy);
}
