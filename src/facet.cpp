#include "facet.h"
Facet::Facet() : m_p1(Vector4(.0f,.0f,1.0f,1.0f)), m_p2(Vector4(1.0f,.0f,.0f,1.0f)), m_p3(Vector4(.0f,1.0f,.0f,1.0f)) {}
Facet::Facet(Vector4 p1, Vector4 p2, Vector4 p3, Vector4 norm, Material c1, Material c2,
	Material c3, Cam* cam, std::vector<Light*> l) : m_p1(p1),m_p2(p2),m_p3(p3),
	m_normal(norm), m_c1(c1),m_c2(c2),m_c3(c3), m_cam(cam), m_lights_list(l) {
		this->MakeNormal();
		//TODO mk triangle
}

Facet::~Facet() {}
void Facet::Draw(SDL_Surface* s) {
	Color ld=Black, ls=Black, vc=Black;
	for (Uint8 i = 0; i < 3; i++) {
	       	for (int j = 0; j < m_lights_list.size(); j++)
			m_lights_list[j]->GetDir().Print();
	}
}
void Facet::Anim(Uint16 time, Input* ui) {}
void Facet::SetCam(Cam* c) { m_cam =c; }
void Facet::SetLights(std::vector<Light*> l) { m_lights_list=l; }
void Facet::MakeNormal() { m_normal=(m_p2-m_p1)/(m_p3-m_p1); }
