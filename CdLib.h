int CDTracks[2];

void Sound_CD_Play(int t, int mode) {
	CDTracks[0] = t;
	CDTracks[1] = 0;

	CdPlay(mode, CDTracks, 0);
}

void Sound_CD_Init() {
	SpuSetCommonCDMix(SPU_ON);
	SpuSetCommonCDVolume(MAX_VOLUME, MAX_VOLUME);
}

void Sound_CD_Stop() {
	CDTracks[0] = 0;

	CdPlay(0, CDTracks, 0);
}

int CD_LoadFile(char *filename, unsigned char *address) {
	int status = 0;
	CdlFILE fp;
	
	CdSearchFile(&fp, filename);

	CdReadFile(filename, (long *) address, 0);

	return fp.size;
}
