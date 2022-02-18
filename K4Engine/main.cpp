#include "Director.hpp"
#include "HelloWorld.hpp"

int main(){
	auto scene = new HelloWorld;
	K4::Director::Run(scene);
	return 0;
}