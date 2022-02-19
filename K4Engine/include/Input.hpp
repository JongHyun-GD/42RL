// Input interface (Singleton)
#ifndef INPUT_HPP
#define INPUT_HPP

#include "Singleton.hpp"
#include "SDL2/SDL.h"
#include <stdexcept>
#include <vector>

namespace K4
{
	enum KeyCode
	{
		KEY_SPACE = SDL_SCANCODE_SPACE,
		KEY_UP = SDL_SCANCODE_UP,
		KEY_DOWN = SDL_SCANCODE_DOWN,
		KEY_LEFT = SDL_SCANCODE_LEFT,
		KEY_RIGHT = SDL_SCANCODE_RIGHT,
		KEY_A = SDL_SCANCODE_A,
		KEY_B = SDL_SCANCODE_B,
		KEY_C = SDL_SCANCODE_C,
		KEY_D = SDL_SCANCODE_D,
		KEY_E = SDL_SCANCODE_E,
		KEY_F = SDL_SCANCODE_F,
		KEY_G = SDL_SCANCODE_G,
		KEY_H = SDL_SCANCODE_H,
		KEY_I = SDL_SCANCODE_I,
		KEY_J = SDL_SCANCODE_J,
		KEY_K = SDL_SCANCODE_K,
		KEY_L = SDL_SCANCODE_L,
		KEY_M = SDL_SCANCODE_M,
		KEY_N = SDL_SCANCODE_N,
		KEY_O = SDL_SCANCODE_O,
		KEY_P = SDL_SCANCODE_P,
		KEY_Q = SDL_SCANCODE_Q,
		KEY_R = SDL_SCANCODE_R,
		KEY_S = SDL_SCANCODE_S,
		KEY_T = SDL_SCANCODE_T,
		KEY_U = SDL_SCANCODE_U,
		KEY_W = SDL_SCANCODE_W,
		KEY_X = SDL_SCANCODE_X,
		KEY_Y = SDL_SCANCODE_Y,
		KEY_Z = SDL_SCANCODE_Z,
		KEY_LCTRL = SDL_SCANCODE_LCTRL,
		KEY_RCTRL = SDL_SCANCODE_RCTRL,
		KEY_LSHIFT = SDL_SCANCODE_LSHIFT,
		KEY_RSHIFT = SDL_SCANCODE_RSHIFT
	};

	class Input : public Singleton<Input>
	{
		friend class Singleton<Input>;
		friend class Director;
	public:
		static int GetKeyDown(KeyCode keycode);
		static int GetKeyUp(KeyCode keycode);
		static int GetMultiKeyDown(KeyCode keycode1, KeyCode keycode2);
		static int GetMultiKeyUp(KeyCode keycode1, KeyCode keycode2);
		static int GetDoubleKeyDown(KeyCode keyCode);
		static std::vector<int> const &GetCachedState();
	private:

		std::vector<int> cachedState;

		Input()
		{
			cachedState = std::vector<int>(1024, 0);
			lastUpdatedTime = -2000;
			updateInterval = 1000;
		};
		~Input(){};
		void UpdateKeyState(int currentTime);

		unsigned int lastUpdatedTime;
		unsigned int updateInterval;
	};
}

#endif
