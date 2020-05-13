#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H

#include"gdal_priv.h"
#include "ogrsf_frmts.h"
#include"gdal.h"
#include"ogr_srs_api.h"
#include"ogr_spatialref.h"
#include"ogr_api.h"
#include"proj_api.h"
#include<cstring>
#include<iostream>

int main() {
	OGRSpatialReference oSourceSRS, oTargetSRS;
	OGRCoordinateTransformation* poCT;
	double x, y, z;

	oTargetSRS.importFromEPSG(4326);
	oSourceSRS.importFromEPSG(2437);
	char* pszWKT = nullptr;
	oSourceSRS.exportToPrettyWkt(&pszWKT);
	std::cout << pszWKT << std::endl;

	poCT = OGRCreateCoordinateTransformation(&oSourceSRS, &oTargetSRS);
	y = 474620.3849;
	x = 3509645.3412;
	z = 0;
	if (poCT == NULL || !poCT->Transform(1, &x, &y, &z))
		printf("Transformation failed.\n");
	else
		printf("%0.15f,%0.15f\n", x, y);


	system("pause");
	return 0;
}