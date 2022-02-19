#include "Input.hpp"
#include <iostream>
using namespace K4;

int Input::GetKeyDown(KeyCode keycode)
{
	if (GetCachedState()[keycode])
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
	if (GetCachedState()[keycode1] && GetCachedState()[keycode2])
		return 1;
	else
		return 0;
}

int Input::GetMultiKeyUp(KeyCode keycode1, KeyCode keycode2)
{
	throw std::logic_error("NotImplemented!!");
}

// 일정 시간 안에 같은 키를 두번 누르면 1 반환
int Input::GetDoubleKeyDown(KeyCode keycode)
{
	if (GetCachedState()[keycode] >= 2)
		return 1;
	else
		return 0;
}

std::vector<int> const &Input::GetCachedState()
{
	return Input::GetInstance()->cachedState;
}

void Input::UpdateKeyState(int currentTime)
{
	int keyStateSize;
	const Uint8 *state = SDL_GetKeyboardState(&keyStateSize);
	if (currentTime - this->lastUpdatedTime < this->updateInterval)
	{
		// Update
		int i = 0;
		while (this->cachedState[i])
		{
			if (state[i])
				this->cachedState[i]++;
			i++;
		}
	}
	else
	{
		// Make new cache and update
		int i = 0;
		this->cachedState.assign(this->cachedState.size(), 0);
		for (int i=0; i<keyStateSize; ++i)
		{
			if (state[i])
				this->cachedState[i]++;
			i++;
		}
		this->lastUpdatedTime = currentTime;
		std::cout << "Updated\n";
	}

}
