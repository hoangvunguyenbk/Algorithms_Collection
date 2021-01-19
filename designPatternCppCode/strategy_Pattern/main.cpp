// Test duck simulator

#include <iostream>
#include "duck_Client.cpp"

using namespace std;

int main(){
	
	Duck* myDuck = new MallardDuck();
	myDuck->display();
	myDuck->swim();
	myDuck->performQuack();
	myDuck->performFly();
	std::cout << "set Quack behavior " << std::endl;
	myDuck->vSetQuackBehavior(new MuteQuack());
	myDuck->performQuack();

	return 0;
}
