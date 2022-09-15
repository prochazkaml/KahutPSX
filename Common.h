// Camera coordinates
struct {
	int		x, y, z;
	int		pan, til, rol;
	VECTOR	pos;
	SVECTOR rot;
	GsRVIEW2 view;
	GsCOORDINATE2 coord2;
} Camera = {0};

typedef struct {
	int x, y, z, pan, til;
} Player_t;

// Lighting coordinates
GsF_LIGHT pslt;

#define SCREEN_XRES		640
#define SCREEN_YRES 	480
#define DITHER			1

#define CENTERX			SCREEN_XRES/2
#define CENTERY			SCREEN_YRES/2

// Increasing this value (max is 14) reduces sorting errors in certain cases
#define OT_LENGTH	12

#define OT_ENTRIES	1<<OT_LENGTH
#define PACKETMAX	2048

GsOT		myOT[2];						// OT handlers
GsOT_TAG	myOT_TAG[2][OT_ENTRIES];		// OT tables
PACKET		myPacketArea[2][PACKETMAX*24];	// Packet buffers
int			myActiveBuff=0;					// Page index counter

unsigned long __ramsize =   0x002000000; // force 2 megabytes of RAM
unsigned long __stacksize = 0x00004000; // force 16 kilobytes of stack

int BG_Brightness = 0;

#define	MAX_VOLUME	0x3FFF
#define	CD_ONETIME	1
#define	CD_REPEAT	2

