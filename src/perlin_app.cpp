#include "perlin_app.h"
PerlinApp::PerlinApp():m_png("perlin.png"),m_perlin(256,5,0.7f) {
	float tmp=0.0f;
	Uint8 expand=0;
	Uint16 i,j;
	for (i=0;i<5;i++)
		tmp+=pow(0.7f,i);
	expand=Uint8(255/tmp);
	Uint16 hmin=255,hmax=0,height;
	m_t = new Uint8[PICTURE_SIZE*PICTURE_SIZE];
	for (i=0;i<PICTURE_SIZE;i++)
		for (j=0;j<PICTURE_SIZE;j++) {
			height=expand*m_perlin.Noise(i,j);
			if (height<hmin)
				hmin=height;
			else if (height>hmax)
				hmax=height;
			m_t[PICTURE_SIZE*i+j]=height;
		}
	printf("%d - %d\n",hmin,hmax);
	// Rescale to 0-255
	tmp=(255/float(hmax-hmin));
	for (i=0;i<PICTURE_SIZE;i++)
		for (j=0;j<PICTURE_SIZE;j++)
			m_t[PICTURE_SIZE*i+j]=Uint8((m_t[PICTURE_SIZE*i+j]-hmin)*tmp);
}
bool PerlinApp::Run() {return m_png.Write(m_t);}
PerlinApp::~PerlinApp() {delete [] m_t;}
