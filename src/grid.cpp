#include "grid.h"
float sm=.0f;
int co=0;
Grid::Grid(Uint16 size=MAP_SIZE):m_png("outmap.png"),m_perlin(size,5,0.7f),m_scale(0.06f),
	m_cellspace(0.9f), m_nb_vert(3*size*size),m_nb_idx(6*(size-1)*(size-1)),
m_max_slope(0), m_min_slope(255), m_size(size) {
	m_vertex = new float[m_nb_vert];
	m_color = new float[m_nb_vert];
	m_index = new Uint32[m_nb_idx];
	m_slope = new float[size*size];

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
	printf("Hauteur : %d - %d\n",hmin,hmax);

	// Rescale to 0-255
	tmp=(255/float(hmax-hmin));
	for (i=0;i<size;i++)
		for (j=0;j<size;j++)
			m_height[size*i+j]=Uint8((m_height[size*i+j]-hmin)*tmp);

	//Compute Slopes
	for (i=0;i<size;i++)
		for (j=0;j<size;j++)
			m_slope[size*i+j]=MakeSlope(i,j);
	printf("Pente : %.3f - %.3f\n",m_min_slope,m_max_slope);

	float xe=m_cellspace*size;
	Color c;
	i=0;
	for (float x = 0; x < xe; x+=m_cellspace) {
		j=0;
		for (float z = 0; z < xe; z+=m_cellspace) {
			m_vertex[index]=x;
			m_vertex[index+1]=m_height[i*size+j]*m_scale;
			m_vertex[index+2]=z;
			c=MakeColor(i,j);
			m_color[index]=c(1);
			m_color[index+1]=c(2);
			m_color[index+2]=c(3);
			index+=3;
			j++;
		}
		i++;
	}
	printf("Indice moyen de pente : %.3f\n", sm/co);

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
	delete [] m_height;
	delete [] m_slope;
	glDeleteBuffers(1, &m_buf);
	glDeleteBuffers(1, &m_buf_index);
}
Color Grid::MakeColor(Uint16 i, Uint16 j) const {
	Uint8 z=m_height[i*m_size+j];
	float s=(m_slope[i*m_size+j]-m_min_slope)/(m_max_slope-m_min_slope);
	sm+=s;
	co++;
	if (z>=0 and z<=LEVEL1)
		return SAND_BEACH*(1-z/float(LEVEL1))
			+ PURE_GREEN*(z/float(LEVEL1))
			- BLACK*(s/3);
	if (z>LEVEL1 and z<=LEVEL2) 
		return PURE_GREEN*(1-(z-LEVEL1)/float(LEVEL2-LEVEL1))
			+ DARK_GREEN*((z-LEVEL1)/float(LEVEL2-LEVEL1))
			- BLACK*(s/3);
	if (z>LEVEL2 and z<=LEVEL3) 
		return DARK_GREEN*(1-(z-LEVEL2)/float(LEVEL3-LEVEL2))
			+ ROCK_LIGHT*((z-LEVEL2)/float(LEVEL3-LEVEL2))
			- BLACK*(s/3);
	if (z>LEVEL3 and z<=255) 
		return ROCK_LIGHT*(1-(z-LEVEL3)/float(255-LEVEL3))
			+ SNOW*5*((z-LEVEL3)/float(255-LEVEL3))
			- BLACK*(s/3);
}
float Grid::MakeSlope(Uint16 i, Uint16 j) {
	Uint8 count=0, idx=i*m_size+j, h=m_height[idx];
	float slope=.0f;
	if (i>0) {
		if (j>0) {
			slope+=abs(m_height[idx-m_size-1]-h);
			count++;
		}	
		slope+=abs(m_height[idx-m_size]-h);
		count++;
		if (j<m_size) {
			slope+=abs(m_height[idx-m_size+1]-h);
			count++;
		}
	}
	if (j>0) {
		slope+=abs(m_height[idx-1]-h);
		count++;
	}	
	if (j<m_size) {
		slope+=abs(m_height[idx+1]-h);
		count++;
	}
	if (i<m_size) {
		if (j>0) {
			slope+=abs(m_height[idx+m_size-1]-h);
			count++;
		}	
		slope+=abs(m_height[idx+m_size]-h);
		count++;
		if (j<m_size) {
			slope+=abs(m_height[idx+m_size+1]-h);
			count++;
		}
	}
	slope=m_scale*slope/count;
	if (slope < m_min_slope)
		m_min_slope=slope;
	if (slope > m_max_slope)
		m_max_slope=slope;
	return slope;
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
