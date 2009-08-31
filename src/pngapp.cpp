#include "pngapp.h"
PNGapp::PNGapp():m_rpng("in.png"),m_wpng("out.png") {
	m_written = new Uint8[PICTURE_SIZE*PICTURE_SIZE];
}
PNGapp::~PNGapp() {
	delete [] m_written;
}
int PNGapp::Run() {
	const Uint8 *read = m_rpng.Read();
	Uint16 size = PICTURE_SIZE;
	for (Uint16 i=0; i<size; i++)
		for (Uint16 j=0; j<size; j++)
			m_written[size*i+j]=255-read[size*i+j];
	if (m_wpng.Write(m_written))
		return EXIT_SUCCESS;
	else {
		printf("%s\n",m_wpng.ErrorMsg().c_str());
		return EXIT_FAILURE;
	}
}
