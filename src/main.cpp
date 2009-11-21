#include <ctime>
#include <string>
#include "capp.h"
#include "triangle_app.h"
#include "png_app.h"
#include "perlin_app.h"
#include "camera_app.h"
#include "proj_app.h"
#include "grid_app.h"
const Uint8 NAPP = 7;
const std::string APP[NAPP] = {"triangle","cube","png","perlin","camera","proj","grid"};
const std::string DAPP[NAPP] = {"Affiches des triangles en 2D","Affiche un cube en 3D",
"Lit et écrit une image png","Crée une carte de perlin","Un cube avec une caméra dirigée au clavier",
"Projete un sommet à l'écran","Dessine un maillage" };
int Help() {
	fprintf(stderr,"Please use one of the following argument :\n");
	for (Uint8 i=0;i<NAPP;i++)
		fprintf(stderr, "%s : %s\n",APP[i].c_str(),DAPP[i].c_str());
	return EXIT_SUCCESS;
}
int main(int argc, char *argv[])
{
	Uint8 cur_app = 255;
	srand(time(NULL));
	if (argc < 2)
		return Help();
	for (Uint8 i=0;i<NAPP;i++)
		if (argv[1]==APP[i]) {
			cur_app = i;
			break;
		}
	if (cur_app!=255) {
		if (cur_app==0) {
			TriangleApp a = TriangleApp();
			return a.Run();
		}
		if (cur_app==1) {
			Capp a = Capp();
			return a.Run();
		}
		if (cur_app==2) {
			PngApp a = PngApp();
			return a.Run();
		}
		if (cur_app==3) {
			PerlinApp a = PerlinApp();
			return a.Run();
		}
		if (cur_app==4) {
			CameraApp a = CameraApp();
			return a.Run();
		}
		if (cur_app==5) {
			ProjApp a = ProjApp();
			return a.Run();
		}
		if (cur_app==6) {
			GridApp a = GridApp();
			return a.Run();
		}
	}
	else 
		return Help();
}

