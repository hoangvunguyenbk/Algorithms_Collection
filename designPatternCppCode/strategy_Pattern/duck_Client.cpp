/*-------------------------------------------------------
 * File name: duck_Client.cpp
 * Author: Vu Nguyen
 * Date: 26-06-2018
 * -----------------------------------------------------*/
#include <iostream>
#include "FlyBehavior.cpp"
#include "QuackBehavior.cpp"


// Duck base class
class Duck {
public:
	Duck(); // Default constructor
	virtual ~Duck(); 

	virtual	void swim() const = 0;
	virtual void display() const = 0;
	void performQuack() const;
	void performFly() const;

	//Set behaviors dynamically
	virtual void vSetQuackBehavior(QuackBehavior* qb);
	virtual void vSetFlyBehavior(FlyBehavior* fb);

protected:

	FlyBehavior* m_poFlybehavior;
	QuackBehavior* m_poQuackbehavior;
};

Duck::Duck(){
	//Duck base class constructor
}
Duck::~Duck(){
	//Destructor
}

void Duck::vSetQuackBehavior(QuackBehavior* qb){
}

void Duck::vSetFlyBehavior(FlyBehavior* fb){
}
void Duck::performQuack() const {
	m_poQuackbehavior->quack();
}
void Duck::performFly() const {
	m_poFlybehavior->fly();
}

// Inheritage classes
class MallardDuck : public Duck {
public:
	MallardDuck();
	virtual ~MallardDuck();

	void swim() const override;
	void display() const override;
	void vSetQuackBehavior(QuackBehavior* qb);
	void vSetFlyBehavior(FlyBehavior* fb);
private:
	
};

MallardDuck::MallardDuck(){
	m_poFlybehavior = new FlyNoWay();
	m_poQuackbehavior = new Quack();

}
MallardDuck::~MallardDuck(){
	delete m_poFlybehavior;
	delete m_poQuackbehavior;
}

void MallardDuck::vSetQuackBehavior(QuackBehavior* qb){
	this->m_poQuackbehavior = qb; 
}

void MallardDuck::vSetFlyBehavior(FlyBehavior* fb){
	this->m_poFlybehavior = fb;
}

void MallardDuck::swim() const {
	std::cout << " MallarDuck can swim " <<std::endl;
}
void MallardDuck::display() const {
	std::cout <<" I'm an mallar duck " << std::endl;
}

class RubberDuck : public Duck{
public:
	RubberDuck();
	virtual ~RubberDuck();

	void swim() const override;
	void display() const override;
};
RubberDuck::RubberDuck(){
}
RubberDuck::~RubberDuck(){
}

void RubberDuck::swim() const {
	std::cout << " RubberDuck cannot swim, I just flow on water surface" << std::endl;
}
void RubberDuck::display() const{
	std::cout << " I'm a Rubber duck " << std::endl;
}


