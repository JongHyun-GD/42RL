#include "Input.hpp"
using namespace K4;

int Input::GetKeyDown(KeyCode keycode)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[keycode])
		return 1;
	else
		return 0;
}

int Input::GetKeyUp(KeyCode keycode)
{
	throw std::logic_error("NotImplemented!!");
}

int Input::GetMultiKeyDown(KeyCode keycode1, KeyCode keycode2)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[keycode1] && state[keycode2])
		return 1;
	else
		return 0;
}

int Input::GetMultiKeyUp(KeyCode keycode1, KeyCode keycode2)
{
	throw std::logic_error("NotImplemented!!");
}

int Input::GetDoubleKeyDown(KeyCode keycode)
{
	throw std::logic_error("NotImplemented!!");
}
