/*---------------------------
 * File name: FlyBehavior.cpp
 * Author: Vu Nguyen
 * Date: 27/6/2018
 * -------------------------*/

#include <iostream>

// Flybehavior interface
class FlyBehavior{
public:
	virtual void fly() = 0;
};

class FlyWithWing : public FlyBehavior {
public:
	void fly(){
		std::cout << "I'm flying" << std::endl;
	}
};

class FlyNoWay : public FlyBehavior{
public:
	void fly(){
		std::cout << "I cannot fly" <<std::endl;
	}
};



