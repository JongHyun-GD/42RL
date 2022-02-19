#include <iostream>
#include <SDL2/SDL.h>
#include "Input.hpp"
#include "Director.hpp"
#include "HelloWorld.hpp"
using namespace std;
using namespace K4;

int main(){
	Director::Init(1920, 1080);
	Director::Run(new HelloWorld);
	return 0;
}
