#include "grid.h"
Grid::Grid(Uint16 size=MAP_SIZE):m_png("outmap.png"),m_perlin(size,5,0.7f),m_cellspace(0.9f),
m_nb_vert(3*size*size),m_nb_idx(6*(size-1)*(size-1)),m_scale(0.06f) {
	m_vertex = new float[m_nb_vert];
	m_color = new float[m_nb_vert];
	m_index = new Uint32[m_nb_idx];

	float tmp=0.0f;
	Uint8 expand=0;
	Uint32 index=0,i=0,j=0,cd;
	for (i=0;i<5;i++)
		tmp+=pow(0.7f,i);
	expand=Uint8(255/tmp);
	Uint16 hmin=255,hmax=0,height;
	m_height = new Uint8[size*size];
	for (i=0;i<size;i++)
		for (j=0;j<size;j++) {
			height=expand*m_perlin.Noise(i,j);
			if (height<hmin)
				hmin=height;
			else if (height>hmax)
				hmax=height;
			m_height[size*i+j]=height;
		}
	printf("%d - %d\n",hmin,hmax);
	// Rescale to 0-255
	tmp=(255/float(hmax-hmin));
	for (i=0;i<size;i++)
		for (j=0;j<size;j++)
			m_height[size*i+j]=Uint8((m_height[size*i+j]-hmin)*tmp);

	float xe=m_cellspace*size;
	i=0;
	for (float x = 0; x < xe; x+=m_cellspace) {
		j=0;
		for (float z = 0; z < xe; z+=m_cellspace) {
			m_vertex[index]=x;
			m_vertex[index+1]=m_height[i*size+j]*m_scale;
			m_vertex[index+2]=z;
			m_color[index]=0.0f;
			m_color[index+1]=0.0f;
			m_color[index+2]=0.0f;
			index+=3;
			j++;
		}
		i++;
	}
	index=0;
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-1; j++) {
			cd=i*size+j;
			m_index[index]=cd;
			m_index[index+1]=cd+size+1;
			m_index[index+2]=cd+1;
			m_index[index+3]=cd;
			m_index[index+4]=cd+size;
			m_index[index+5]=cd+size+1;
			index+=6;
		}
	}

	glGenBuffers(1, &m_buf);
	glBindBuffer(GL_ARRAY_BUFFER, m_buf);
	glBufferData(GL_ARRAY_BUFFER,
			(m_nb_vert*V__SIZE*sizeof(m_vertex[0])) +    /* taille des positions */
			(m_nb_vert*C__SIZE*sizeof(m_color[0])),  /* taille des couleurs */
			NULL,                              /* ... */
			GL_STATIC_DRAW);                   /* mode */
	glBufferSubData(GL_ARRAY_BUFFER,
			0,                            /* emplacement des donnees dans le VBO (first) */
			(m_nb_vert*V__SIZE*sizeof(m_vertex[0])), /* taille des donnees (size) */
			m_vertex);                         /* adresse des donnees */
	glBufferSubData(GL_ARRAY_BUFFER,
			(m_nb_vert*V__SIZE*sizeof(m_vertex[0])),   /* emplacement (first) */
			(m_nb_vert*C__SIZE*sizeof(m_color[0])),/* taille (size) */
			m_color);                        /* donnees */

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/* construction du IBO */
	glGenBuffers(1, &m_buf_index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buf_index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_nb_idx * sizeof(m_index[0]), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_nb_idx * sizeof(m_index[0]), m_index);
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
	glColorPointer(C__SIZE, GL_FLOAT, 0, BUFFER_OFFSET(m_nb_vert*V__SIZE*sizeof(m_vertex[0])));
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buf_index);
	glDrawElements(GL_TRIANGLES, m_nb_idx, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
void Grid::Anim(Uint16 elapsed, Input *ui) {}
