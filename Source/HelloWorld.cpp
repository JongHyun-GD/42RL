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
	if (Input::GetKeyDown(KEY_W))
		std::cout << "W pressed.\n";
	if (Input::GetDoubleKeyDown(KEY_W))
		std::cout << "W dashed.\n";
}
