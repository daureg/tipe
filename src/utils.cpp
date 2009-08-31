#include "utils.h"
void Screenshot(SDL_Surface *s) {
	static Uint16 count=0;
	count++;
	char name[15];
	snprintf(name,11,"screen_%03d",count);
	if (s==NULL) {
		strncat(name,".tga",4);
		FILE *out = fopen(name, "w");
		char pixel_data[3*RES_X*RES_Y];
		short TGAhead[] = {0, 2, 0, 0, 0, 0, RES_X, RES_Y, 24};
		glReadBuffer(GL_FRONT);
		glReadPixels(0, 0, RES_X, RES_Y, GL_BGR, GL_UNSIGNED_BYTE, pixel_data);
		fwrite(&TGAhead, sizeof(TGAhead), 1, out);
		fwrite(pixel_data, 3*RES_X*RES_Y, 1, out);
		fclose(out);
	}
	else {
		strncat(name,".bmp",4);
		SDL_SaveBMP(s,name);
	}
	printf("Taken %s\n",name);
}
