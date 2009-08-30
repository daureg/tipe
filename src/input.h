#ifndef __INPUT
#define __INPUT
#include <SDL.h>
#include <map>
#include <string>

class Input {
	public:
		Input();
		virtual ~Input();
		void ProcessKeyboard(SDL_KeyboardEvent&);
		bool IsPressed(std::string);
	private:
		typedef std::map<SDLKey,bool> KeyStates;
		typedef std::map<std::string,SDLKey> KeyConf;
		KeyStates m_ks;
		KeyConf m_kc;
};
#endif
