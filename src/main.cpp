#include <ctime>
#include <string>
#include "capp.h"
#include "tapp.h"
#include "rapp.h"
#include "wapp.h"
#include "papp.h"
#include "gapp.h"
#include "iapp.h"
const Uint8 NAPP = 7;
const std::string APP[NAPP] = {"triangle","cube","rpng","wpng","perlin","camera","input"};
const std::string DAPP[NAPP] = {"Affiches des triangles en 2D","Affiche un cube en 3D",
"lit une image png","Écrit une image png","Crée une carte de perlin","Un cube avec une caméra",
"Teste les entrée clavier"};
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
			a.Run();
		}
		if (cur_app==1) {
			Capp a = Capp();
			a.Run();
		}
		if (cur_app==2) {
			Rapp a = Rapp();
			a.Run();
		}
		if (cur_app==3) {
			Wapp a = Wapp();
			a.Run();
		}
		if (cur_app==4) {
			Papp a = Papp();
			a.Run();
		}
		if (cur_app==5) {
			Gapp a = Gapp();
			a.Run();
		}
		if (cur_app==6) {
			Iapp a = Iapp();
			a.Run();
		}
		return EXIT_SUCCESS;
	}
	else 
		return Help();
}

