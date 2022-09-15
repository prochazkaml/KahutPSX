void CalculateCamera() {
	VECTOR	vec;
	GsVIEW2 view;
	
	// Copy the camera (base) matrix for the viewpoint matrix
	view.view = Camera.coord2.coord;
	view.super = WORLD;
	
	// I really can't explain how this works but I found it in one of the ZIMEN examples
	RotMatrix(&Camera.rot, &view.view);
	ApplyMatrixLV(&view.view, &Camera.pos, &vec);
	TransMatrix(&view.view, &vec);
	
	// Set the viewpoint matrix to the GTE
	GsSetView2(&view);
}

void PutObject(VECTOR pos, SVECTOR rot, GsDOBJ2 *obj) {
	MATRIX lmtx,omtx;
	GsCOORDINATE2 coord;
	
	// Copy the camera (base) matrix for the model
	coord = Camera.coord2;
	
	// Rotate and translate the matrix according to the specified coordinates
	RotMatrix(&rot, &omtx);
	TransMatrix(&omtx, &pos);
	CompMatrixLV(&Camera.coord2.coord, &omtx, &coord.coord);
	coord.flg = 0;
	
	// Apply coordinate matrix to the object
	obj->coord2 = &coord;
	
	// Calculate Local-World (for lighting) and Local-Screen (for projection) matrices and set both to the GTE
	GsGetLws(obj->coord2, &lmtx, &omtx);
	GsSetLightMatrix(&lmtx);
	GsSetLsMatrix(&omtx);
	
	// Sort the object!
	GsSortObject4(obj, &myOT[myActiveBuff], 14-OT_LENGTH, getScratchAddr(0));
}


int LinkModel(u_long *tmd, GsDOBJ2 *obj) {
	
	/*	This function prepares the specified TMD model for drawing and then
		links it to a GsDOBJ2 structure so it can be drawn using GsSortObject4().
		
		By default, light source calculation is disabled but can be re-enabled by
		simply setting the attribute variable in your GsDOBJ2 structure to 0.
		
		Parameters:
			*tmd - Pointer to a TMD model file loaded in memory.
			*obj - Pointer to an empty GsDOBJ2 structure.
	
		Returns:
			Number of objects found inside the TMD file.
			
	*/
	
	u_long *dop;
	int i,NumObj;
	
	// Copy pointer to TMD file so that the original pointer won't get destroyed
	dop = tmd;
	
	// Skip header and then remap the addresses inside the TMD file
	dop++; GsMapModelingData(dop);
	
	// Get object count
	dop++; NumObj = *dop;

	// Link object handler with the specified TMD
	dop++;
	for(i=0; i<NumObj; i++) {
		GsLinkObject4((u_long)dop, &obj[i], i);
		obj[i].attribute = (1<<6);	// Disables light source calculation
	}
	
	// Return the object count found inside the TMD
	return(NumObj);
	
}

