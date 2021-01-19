/*----------------------------------
 * File name : QuackBehavior.cpp
 * Author: Vu Nguyen
 * Date: 30/06/2018
 * --------------------------------*/

#include <iostream>

// QuackBehavior interface
class QuackBehavior{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior{
public:
	void quack(){
		std::cout << "Quack" << std::endl;
	}

};

class MuteQuack : public QuackBehavior{
public:
	void quack(){
		std::cout << "<<Slince>>" <<std::endl;
	}
};
