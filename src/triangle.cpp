#include "triangle.h"
Triangle::Triangle():m_default(true) {
	m_vertex[0]=300;m_vertex[1]=250;
	m_vertex[2]=380;m_vertex[3]=150;
	m_vertex[4]=200;m_vertex[5]=50;
	Sort();
	m_l1 = new Uint16[SIZE];
	m_l2 = new Uint16[SIZE];
	m_l3 = new Uint16[SIZE];
}
Triangle::Triangle(Uint16 *t,Uint16 *l1,Uint16 *l2,Uint16 *l3): m_l1(l1),
	m_l2(l2),m_l3(l3),m_default(false) {
	for (Uint8 i=0;i<6;i++) 
		m_vertex[i]=t[i]; 
	Sort(); 
}
Triangle::~Triangle() {
	if (m_default) {
		delete [] m_l1;
		delete [] m_l2;
		delete [] m_l3;
	}
}
void Triangle::SetPoint(Uint16 *t,Uint16 *l1,Uint16 *l2,Uint16 *l3) {	
	m_l1=l1;
	m_l2=l2;
	m_l3=l3;
	m_default=false;
	for (Uint8 i=0;i<6;i++) 
		m_vertex[i]=t[i]; 
	Sort();  
}
void Triangle::Draw() const {
	Uint16 i,j,xmin,xmax;
	static bool once=true;
	memset(m_l1,INF16,SIZE*sizeof(Uint16));
	memset(m_l2,INF16,SIZE*sizeof(Uint16));
	memset(m_l3,INF16,SIZE*sizeof(Uint16));

	this->Line(m_vertex[0],m_vertex[1],m_vertex[4],m_vertex[5],m_l1);
	this->Line(m_vertex[0],m_vertex[1],m_vertex[2],m_vertex[3],m_l2);
	this->Line(m_vertex[2],m_vertex[3],m_vertex[4],m_vertex[5],m_l3);

	for (j=m_vertex[1];j<=m_vertex[3];j++) {
		if (m_l1[j]!=INF16 && m_l2[j]!=INF16) {
			glBegin(GL_LINES);
			glVertex2i(m_l1[j],j);
			glVertex2i(m_l2[j],j);
			glEnd();
		}
	}
	for (j=m_vertex[3]+1;j<=m_vertex[5];j++) {
		if (m_l1[j]!=INF16 && m_l3[j]!=INF16) {
			glBegin(GL_LINES);
			glVertex2i(m_l1[j],j);
			glVertex2i(m_l3[j],j);
			glEnd();
		}
	}
}
// le premier est sommet est le plus proche du coin supérieur gauche et les deux
// autres sont rangés par hauteur croissante.
void Triangle::Sort() {
	Uint16 k=0,i,xmin=m_vertex[0],ymin=m_vertex[1];
	for (i = k; i < 3; i++) 
		if (m_vertex[2*i+1]<ymin) {
			xmin=m_vertex[2*i];
			ymin=m_vertex[2*i+1];
			k=i;
		}
	this->Swap(0,k);
	if (m_vertex[3]>m_vertex[5])
		Swap(1,2);
}
void Triangle::Line(Uint16 xi,Uint16 yi,Uint16 xf,Uint16 yf,Uint16 *px) const {
	Sint16 dx,dy,cumul,x,y,xinc,yinc,i;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	px[y]=x;
	if ( dx > dy ) {
		cumul = dx / 2;
		glBegin(GL_POINTS);
		for (i = 0; i < dx; i++) {
			x += xinc;
			cumul += dy;
			if (cumul >= dx) {
				cumul -= dx;
				y += yinc;
			}
			px[y] = x;
			glVertex2i(x,y);
		} 
		glEnd();
		return;
	}
	if (dx < dy) {
		cumul = dy / 2;
		glBegin(GL_POINTS);
		for (i = 0; i < dy; i++) {
			y += yinc;
			cumul += dx;
			if (cumul > dy) {
				cumul -= dy;
				x += xinc; 
			}
			px[y] = x;
			glVertex2i(x,y);
		} 
		glEnd();
	}
}
// Swap point p1 with p2, given by a number between 0 and 2
void Triangle::Swap(Uint8 p1,Uint8 p2) {
	Uint16 tx=m_vertex[2*p1];
	Uint16 ty=m_vertex[2*p1+1];
	m_vertex[2*p1]=m_vertex[2*p2];
	m_vertex[2*p1+1]=m_vertex[2*p2+1];
	m_vertex[2*p2]=tx;
	m_vertex[2*p2+1]=ty;
}
