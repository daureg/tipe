#include <ctime>
#include <string>
#include "capp.h"
#include "tapp.h"
const Uint8 NAPP = 2;
const std::string APP[NAPP] = {"triangle","cube"};
const std::string DAPP[NAPP] = {"Affiches des triangles en 2D","Affiche un cube en 3D"};
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
		Conf c1 = Conf();
		if (cur_app==0) {
			Tapp a = Tapp(&c1);
			a.Run();
		}
		if (cur_app==1) {
			Capp a = Capp(&c1);
			a.Run();
		}
		return EXIT_SUCCESS;
	}
	else 
		return Help();
}

