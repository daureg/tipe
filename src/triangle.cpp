#include "triangle.h"
Triangle::Triangle():m_default(true) {
	m_vertex[0]=300;m_vertex[1]=250;
	m_vertex[2]=380;m_vertex[3]=150;
	m_vertex[4]=200;m_vertex[5]=50;
	Sort();
	m_l1 = new Uint16[SCREEN_SIZE];
	m_l2 = new Uint16[SCREEN_SIZE];
	m_l3 = new Uint16[SCREEN_SIZE];
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
void Triangle::DrawGL() const {
	glColor3f(m_colors[0](1),m_colors[0](2),m_colors[0](3));
	glBegin(GL_TRIANGLES);
	glVertex2i(m_vertex[0],m_vertex[1]);
	glColor3f(m_colors[1](1),m_colors[1](2),m_colors[1](3));
	glVertex2i(m_vertex[2],m_vertex[3]);
	glColor3f(m_colors[2](1),m_colors[2](2),m_colors[2](3));
	glVertex2i(m_vertex[4],m_vertex[5]);
	glEnd();
}
void Triangle::Draw() const {
	Uint16 j,xmin,xmax;

	memset(m_l1,INF16,SCREEN_SIZE*sizeof(Uint16));
	memset(m_l2,INF16,SCREEN_SIZE*sizeof(Uint16));
	memset(m_l3,INF16,SCREEN_SIZE*sizeof(Uint16));

	Line(m_vertex[0],m_vertex[1],m_vertex[4],m_vertex[5],m_l1);
	Line(m_vertex[0],m_vertex[1],m_vertex[2],m_vertex[3],m_l2);
	Line(m_vertex[2],m_vertex[3],m_vertex[4],m_vertex[5],m_l3);

	for (j=m_vertex[1];j<=m_vertex[3];j++) {
		if (m_l1[j]!=INF16 && m_l2[j]!=INF16) {
			///*
			xmin = (m_l1[j] < m_l2[j]) ? m_l1[j] : m_l2[j];
			xmax = (m_l1[j] > m_l2[j]) ? m_l1[j] : m_l2[j];
			DrawSegment(xmin,xmax,j);
			//*/
			/*
			glBegin(GL_LINES);
			glVertex2i(m_l1[j],j);
			glVertex2i(m_l2[j],j);
			glEnd();
			*/
		}
	}
	for (j=m_vertex[3]+1;j<=m_vertex[5];j++) {
		if (m_l1[j]!=INF16 && m_l3[j]!=INF16) {
			///*
			xmin = (m_l1[j] < m_l3[j]) ? m_l1[j] : m_l3[j];
			xmax = (m_l1[j] > m_l3[j]) ? m_l1[j] : m_l3[j];
			DrawSegment(xmin,xmax,j);
			//*/
			/*
			glBegin(GL_LINES);
			glVertex2i(m_l1[j],j);
			glVertex2i(m_l3[j],j);
			glEnd();
			*/
		}
	}
}
void Triangle::DrawSegment(Uint16 xmin, Uint16 xmax, Uint16 j) const {	
	Uint16 i,f,g;
	Sint16 x,y;
	float a,b,t1,t2,tmp;
	Color cd,cm;
	f=m_vertex[0];
	g=m_vertex[1];
	b=float(m_vertex[5] - g)/float(m_vertex[4] - f);
	for (i=xmin;i<=xmax;i++) {
		a=(m_vertex[3] - j)/float(m_vertex[2] - i);
		tmp=(m_vertex[3]-g - a*(m_vertex[2]-f))/float(b - a);
		x=Uint16(tmp+f);
		y=Uint16(b*tmp+g);
		t1=Distance(x,y,f,g)/m_d1;
		t2=Distance(i,j,x,y)/Distance(x,y,m_vertex[2],m_vertex[3]);
		cd=m_colors[0]*(1-t1) + m_colors[2]*t1;
		cm=cd*(1-t2) + m_colors[1]*t2;
		glColor3f(cm(1),cm(2),cm(3));
		glBegin(GL_POINTS);
		glVertex2i(i,j);
		glEnd();
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
	Swap(0,k);
	if (m_vertex[3]>m_vertex[5])
		Swap(1,2);
	m_d1=Distance(m_vertex[0],m_vertex[1],m_vertex[4],m_vertex[5]);
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
	px[y]=x;
	if ( dx > dy ) {
		cumul = dx / 2;
		for (i = 0; i < dx; i++) {
			x += xinc;
			cumul += dy;
			if (cumul >= dx) {
				cumul -= dx;
				y += yinc;
			}
			px[y] = x;
		} 
		return;
	}
	if (dx < dy) {
		cumul = dy / 2;
		for (i = 0; i < dy; i++) {
			y += yinc;
			cumul += dx;
			if (cumul > dy) {
				cumul -= dy;
				x += xinc; 
			}
			px[y] = x;
		} 
		return;
	}
	if (dx==dy)
		for (i = xi; i <= xf; i++)
			px[i]=i;
}
// Swap point p1 with p2, given by a number between 0 and 2
void Triangle::Swap(Uint8 p1,Uint8 p2) {
	Uint16 tx=m_vertex[2*p1];
	Uint16 ty=m_vertex[2*p1+1];
	Color tc=m_colors[p1];
	m_vertex[2*p1]=m_vertex[2*p2];
	m_vertex[2*p1+1]=m_vertex[2*p2+1];
	m_vertex[2*p2]=tx;
	m_vertex[2*p2+1]=ty;
	m_colors[p1]=m_colors[p2];
	m_colors[p2]=tc;
}
void Triangle::SetColors(Color *c1, Color *c2, Color *c3) {
	m_colors[0]=*c1;
	m_colors[1]=*c2;
	m_colors[2]=*c3;
}
void Triangle::Print() const {
	printf("Point %d : (%d,%d), ",1,m_vertex[2*0],m_vertex[2*0+1]);m_colors[0].Print();
	printf("Point %d : (%d,%d), ",2,m_vertex[2*1],m_vertex[2*1+1]);m_colors[1].Print();
	printf("Point %d : (%d,%d), ",3,m_vertex[2*2],m_vertex[2*2+1]);m_colors[2].Print();
}
float Triangle::Distance(Sint16 a,Sint16 b,Sint16 x,Sint16 y) const {
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
