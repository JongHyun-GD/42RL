#include "HelloWorld.hpp"
#include "Input.hpp"
#include <iostream>

using namespace K4;
using namespace std;

void HelloWorld::Start()
{

}

void HelloWorld::Update()
{
	if (Input::GetKeyDown(KEY_SPACE))
		std::cout << "SPACE down.\n";
	if (Input::GetKeyUp(KEY_SPACE))
		std::cout << "SPACE up.\n";
	if (Input::GetDoubleKeyDown(KEY_SPACE))
		std::cout << "SPACE double down.\n";
	if (Input::GetMultiKeyDown(KEY_SPACE, KEY_LSHIFT))
		std::cout << "SPACE SHIFT down.\n";
}
