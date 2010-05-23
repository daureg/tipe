#include "facet.h"
Facet::Facet() {
	m_points[0]=(Vector4(.0f,.0f,1.0f,1.0f));
	m_points[1]=(Vector4(1.0f,.0f,.0f,1.0f));
	m_points[2]=(Vector4(.0f,1.0f,.0f,1.0f));
}
Facet::Facet(Vector4 p1, Vector4 p2, Vector4 p3, Vector4 norm, Material c1, Material c2,
		Material c3, LearningCam* cam, std::vector<Light*> l, Uint16* l1,
		Uint16* l2, Uint16* l3) : m_normal(norm), m_cam(cam), m_lights_list(l) {
		m_lines[0]=(l1);
		m_lines[1]=(l2);
		m_lines[2]=(l3);
		m_points[0]=(p1);
		m_points[1]=(p2);
		m_points[2]=(p3);
		m_colors[0]=(c1);
		m_colors[1]=(c2);
		m_colors[2]=(c3);
		MakeNormal();
	}

Facet::~Facet() {}
void Facet::Draw(SDL_Surface* s) {
	Color ld=Black, ls=Black, vc=Black;
	Vector4 rs;
	Uint16 x,y;
	Uint16 tr[6]={0};
	// Unit vector pointing to the light
	Vector4 light;
	// Reflection vector
	Vector4 ref;
	// Unit vector pointing to the camera
	Vector4 viewer;
	for (Uint8 i = 0; i < 3; i++) {
		viewer = (m_cam->GetPos() - m_points[i]).Normalize();
		// The first light is supposed to be ambient color
		for (int j = 1; j < m_lights_list.size(); j++) {
			light = (m_lights_list[j]->GetPos() - m_points[i]).Normalize();
			ref = m_normal*2*(m_normal/light)- light;
			ld = ld + m_lights_list[j]->ReceiveFrom(m_points[i])* \
			     Max(m_normal/light,float(0));
			if (m_normal/light > 0)
				ls = ls + m_lights_list[j]->ReceiveFrom(m_points[i])* \
				     pow(Max(ref/viewer,float(0)),m_colors[i].GetSharpness());
		}
		vc = m_colors[i].GetDiffuse()*m_lights_list[0]->ReceiveFrom(m_points[i]) +
			m_colors[i].GetDiffuse()*ld + m_colors[i].GetSpecular()*ls;
		rs=m_cam->Proj(&m_points[i]);
		x=(rs(1)/rs(4)+1)*(RES_X)/2;
		y=(rs(2)/rs(4)+1)*(RES_Y)/2;
		tr[2*i]=x;
		tr[2*i+1]=y;
	}
	m_triangle.SetPoint(tr,m_lines[0],m_lines[1],m_lines[2]);
}
void Facet::Anim(Uint16 elapsed, Input* ui) {}
void Facet::SetCam(LearningCam* c) { m_cam=c; }
void Facet::SetLights(std::vector<Light*> l) { m_lights_list=l; }
void Facet::MakeNormal() { m_normal=(m_points[1]-m_points[0])/(m_points[2]-m_points[0]); }
