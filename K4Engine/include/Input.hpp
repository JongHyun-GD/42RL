// Input interface (Singleton)
#ifndef INPUT_HPP
#define INPUT_HPP

#include "KeyCode.hpp"
#include "Singleton.hpp"
#include <stdexcept>

namespace K4
{
	class Input : public Singleton<Input>
	{
	public:
		static int GetKeyDown(KeyCode keycode);
		static int GetKeyUp(KeyCode keycode);
		static int GetMultiKeyDown(KeyCode keycode1, KeyCode keycode2);
		static int GetMultiKeyUp(KeyCode keycode1, KeyCode keycode2);
		static int GetDoubleKeyDown(KeyCode keyCode);
	private:
		Input(){};
		~Input(){};
	};
}

#endif
