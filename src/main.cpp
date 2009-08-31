#include <ctime>
#include <string>
#include "capp.h"
#include "tapp.h"
#include "pngapp.h"
#include "papp.h"
#include "camera_app.h"
const Uint8 NAPP = 5;
const std::string APP[NAPP] = {"triangle","cube","png","perlin","camera"};
const std::string DAPP[NAPP] = {"Affiches des triangles en 2D","Affiche un cube en 3D",
"Lit et écrit une image png","Crée une carte de perlin","Un cube avec une caméra dirigée au clavier"};
int Help() {
	for (Uint8 i=0;i<NAPP;i++)
		printf("%s : %s\n",APP[i].c_str(),DAPP[i].c_str());
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
			Tapp a = Tapp();
			return a.Run();
		}
		if (cur_app==1) {
			Capp a = Capp();
			return a.Run();
		}
		if (cur_app==2) {
			PNGapp a = PNGapp();
			return a.Run();
		}
		if (cur_app==3) {
			Papp a = Papp();
			return a.Run();
		}
		if (cur_app==4) {
			CameraApp a = CameraApp();
			return a.Run();
		}
	}
	else 
		return Help();
}

