#include "grid.h"
Grid::Grid(Uint16 size=MAP_SIZE):m_png("outmap.png"),m_perlin(size) {
	m_vertex = new float[N__VERTS*V__SIZE];
	m_vertex[0]=1.0f; m_vertex[1]=1.0f; m_vertex[2]=1.0f; m_vertex[3]=-1.0f; m_vertex[4]=1.0f; m_vertex[5]=1.0f; m_vertex[6]=-1.0f; m_vertex[7]=-1.0f; m_vertex[8]=1.0f; m_vertex[9]=1.0f; m_vertex[10]=-1.0f; m_vertex[11]=1.0f; m_vertex[12]=1.0f; m_vertex[13]=1.0f; m_vertex[14]=-1.0f; m_vertex[15]=-1.0f; m_vertex[16]=1.0f; m_vertex[17]=-1.0f; m_vertex[18]=-1.0f; m_vertex[19]=-1.0f; m_vertex[20]=-1.0f; m_vertex[21]=1.0f; m_vertex[22]=-1.0f; m_vertex[23]=-1.0f;
	m_color = new float[N__VERTS*C__SIZE];
	m_color[0]=1.0f; m_color[1]=0.0f; m_color[2]=0.0f; m_color[3]=1.0f; m_color[4]=0.0f; m_color[5]=0.0f; m_color[6]=1.0f; m_color[7]=0.0f; m_color[8]=0.0f; m_color[9]=1.0f; m_color[10]=0.0f; m_color[11]=0.0f; m_color[12]=0.0f; m_color[13]=0.0f; m_color[14]=1.0f; m_color[15]=0.0f; m_color[16]=0.0f; m_color[17]=1.0f; m_color[18]=0.0f; m_color[19]=0.0f; m_color[20]=1.0f; m_color[21]=0.0f; m_color[22]=0.0f; m_color[23]=1.0f;
	m_index = new unsigned char[NUM__VERTICES];
	m_index[0]=0; m_index[1]=1; m_index[2]=2; m_index[3]=0; m_index[4]=2; m_index[5]=3; m_index[6]=4; m_index[7]=0; m_index[8]=3; m_index[9]=4; m_index[10]=3; m_index[11]=7; m_index[12]=5; m_index[13]=4; m_index[14]=7; m_index[15]=5; m_index[16]=7; m_index[17]=6; m_index[18]=1; m_index[19]=5; m_index[20]=6; m_index[21]=1; m_index[22]=6; m_index[23]=2; m_index[24]=4; m_index[25]=5; m_index[26]=1; m_index[27]=4; m_index[28]=1; m_index[29]=0; m_index[30]=2; m_index[31]=6; m_index[32]=7; m_index[33]=2; m_index[34]=7; m_index[35]=3;

	glGenBuffers(1, &m_buf);
	glBindBuffer(GL_ARRAY_BUFFER, m_buf);
	glBufferData(GL_ARRAY_BUFFER,
			(N__VERTS*V__SIZE*sizeof(m_vertex[0])) +    /* taille des positions */
			(N__VERTS*C__SIZE*sizeof(m_color[0])),  /* taille des couleurs */
			NULL,                              /* ... */
			GL_STATIC_DRAW);                   /* mode */
	glBufferSubData(GL_ARRAY_BUFFER,
			0,                            /* emplacement des donnees dans le VBO (first) */
			(N__VERTS*V__SIZE*sizeof(m_vertex[0])), /* taille des donnees (size) */
			m_vertex);                         /* adresse des donnees */
	glBufferSubData(GL_ARRAY_BUFFER,
			(N__VERTS*V__SIZE*sizeof(m_vertex[0])),   /* emplacement (first) */
			(N__VERTS*C__SIZE*sizeof(m_color[0])),/* taille (size) */
			m_color);                        /* donnees */

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/* construction du IBO */
	glGenBuffers(1, &m_buf_index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buf_index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, NUM__VERTICES * sizeof(m_index[0]), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, NUM__VERTICES * sizeof(m_index[0]), m_index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
Grid::~Grid() {	
	delete [] m_vertex;
	delete [] m_color;
	delete [] m_index;
	glDeleteBuffers(1, &m_buf);
	glDeleteBuffers(1, &m_buf_index);
}
void Grid::Draw(SDL_Surface *s) {
	glBindBuffer(GL_ARRAY_BUFFER, m_buf);
	glVertexPointer(V__SIZE, GL_FLOAT, 0, BUFFER_OFFSET(0));
	glColorPointer(C__SIZE, GL_FLOAT, 0, BUFFER_OFFSET(N__VERTS*V__SIZE*sizeof(m_vertex[0])));
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buf_index);
	glDrawElements(GL_TRIANGLES, NUM__VERTICES, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
void Grid::Anim(Uint16 elapsed, Input *ui) {}
