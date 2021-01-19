/*-----------------------------------------
 * File name: Subject.cpp
 * Author: Vu Nguyen
 * Date: 01/07/2018
 *----------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

class Subject {
public:
	Subject(){};
	virtual ~Subject(){};
	virtual void registerObserver(Observer& ob) const = 0;
	virtual void removeObserver(Observer& ob) const = 0;
	virtual void notifyObserver() const = 0;
};
