#include "input.h"
Input::Input() {
	m_kc["quit"] = SDLK_ESCAPE;
	m_ks[m_kc["quit"]] = false;

	m_kc["screenshot"] = SDLK_F12;
	m_ks[m_kc["screenshot"]] = false;

	m_kc["forward"] = SDLK_z;
	m_ks[m_kc["forward"]] = false;

	m_kc["backward"] = SDLK_s;
	m_ks[m_kc["backward"]] = false;

	m_kc["left"] = SDLK_q;
	m_ks[m_kc["left"]] = false;

	m_kc["right"] = SDLK_d;
	m_ks[m_kc["right"]] = false;

	m_kc["up"] = SDLK_a;
	m_ks[m_kc["up"]] = false;

	m_kc["down"] = SDLK_e;
	m_ks[m_kc["down"]] = false;

	m_kc["look_left"] = SDLK_KP4;
	m_ks[m_kc["look_left"]] = false;

	m_kc["look_right"] = SDLK_KP6;
	m_ks[m_kc["look_right"]] = false;

	m_kc["look_up"] = SDLK_KP8;
	m_ks[m_kc["look_up"]] = false;

	m_kc["look_down"] = SDLK_KP5;
	m_ks[m_kc["look_down"]] = false;
}
Input::~Input() {}
void Input::ProcessKeyboard(SDL_KeyboardEvent &event) {
	for (KeyStates::iterator it=m_ks.begin(); it!=m_ks.end(); it++)
		if (event.keysym.sym == it->first) {
			it->second = (event.type == SDL_KEYDOWN);
			break;
		}
}
bool Input::IsPressed(std::string action) {
	if (action=="quit")
		return m_ks[m_kc["quit"]];
	if (action=="screenshot")
		return m_ks[m_kc["screenshot"]];
	if (action=="forward")
		return m_ks[m_kc["forward"]];
	if (action=="backward")
		return m_ks[m_kc["backward"]];
	if (action=="left")
		return m_ks[m_kc["left"]];
	if (action=="right")
		return m_ks[m_kc["right"]];
	if (action=="up")
		return m_ks[m_kc["up"]];
	if (action=="down")
		return m_ks[m_kc["down"]];
	if (action=="look_left")
		return m_ks[m_kc["look_left"]];
	if (action=="look_right")
		return m_ks[m_kc["look_right"]];
	if (action=="look_up")
		return m_ks[m_kc["look_up"]];
	if (action=="look_down")
		return m_ks[m_kc["look_down"]];
}
