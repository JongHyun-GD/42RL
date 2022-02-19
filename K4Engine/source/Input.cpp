#include "Input.hpp"

namespace K4{

	Input::Input()
		: _currentTime(0), _updateInterval(500){
		memset(_keyState, 0, sizeof(KeyState) * SDL_NUM_SCANCODES);
	}

	Input::~Input(){

	}

	int Input::GetKeyDown(KeyCode keycode)
	{

		if (!GetKeyState(keycode).lastState && GetKeyState(keycode).currentState)
			return 1;
		return 0;
	}

	int Input::GetKey(KeyCode keycode){
		if (GetKeyState(keycode).currentState)
			return 1;
		return 0;
	}

	int Input::GetKeyUp(KeyCode keycode)
	{
		if (GetKeyState(keycode).lastState && !GetKeyState(keycode).currentState)
			return 1;
		return 0;
	}

	int Input::GetMultiKeyDown(KeyCode keycode1, KeyCode keycode2)
	{
		if ((GetKey(keycode1) && GetKeyDown(keycode2)) 
		 || (GetKeyDown(keycode1) && GetKey(keycode2)))
			return 1;
		return 0;
	}

	// 일정 시간 안에 같은 키를 두번 누르면 1 반환
	int Input::GetDoubleKeyDown(KeyCode keycode)
	{
		auto input = Input::GetInstance();
		auto lastUpTime = GetKeyState(keycode).lastUpTime;
		if (GetKeyDown(keycode) && lastUpTime && input->_currentTime - lastUpTime < input->_updateInterval){
			input->_keyState[(uint)keycode].isDoubleDown = true;
			return 1;
		}
		return 0;
	}

	void Input::UpdateKeyState(uint currentTime)
	{
		_currentTime = currentTime;
		const Uint8 *state = SDL_GetKeyboardState(nullptr);
		for (int i = 0;i < SDL_NUM_SCANCODES;++i){
			_keyState[i].lastState = _keyState[i].currentState;
			_keyState[i].currentState = state[i];
			if (_keyState[i].lastState && !_keyState[i].currentState){
				_keyState[i].lastUpTime = _keyState[i].isDoubleDown ? 0 : _currentTime;
				_keyState[i].isDoubleDown = false;
			}
		}

	}

	KeyState const &Input::GetKeyState(KeyCode keycode)
	{
		return Input::GetInstance()->_keyState[(uint)keycode];
	}

}