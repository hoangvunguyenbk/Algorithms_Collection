/*----------------------------------------
 * File name : WeatherData.cpp
 * Author: Vu Nguyen
 * Data : 01/07/2018
 * -------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

class WeatherData : public Subject{
public:
	WeatherData(){};
	virtual ~WeatherData();
	void registerObserver() const override;
	void removeObserver() const override;
	void notifyObserver() const override;

	float getTemperature() const;
	float getHumidity() const;
	float getPressure() const;
	void measurementsChanged() const;

protected:
	std::vector<Observer> m_ObserverArray;
	float m_Temperature;
	float m_Humidity;
	float m_Pressure;
};
WeatherData::WeatherData(){
	
}
WeatherData::~WeatherData(){

}

void WeatherData::registerObserver(Observer& ob) const override{
	m_poObserver.push_back(ob);
}
void WeatherData::removeObserver(Observer& ob) const override{
	std::remove(m_ObserverArray.begin(), m_ObserverArray.end(), ob);
}
void WeatherData::notifyObserver() const override(){
	std::vector<Observer>::iterator iter;
	for(iter=m_ObserverArray.begin(); iter!=m_ObserverArray.end(); iter++){
		*iter->update();
	}
}
void WeatherData::measurementsChanged() const(){
	this->notifyObserver();
}
void WeatherData::vSetMeasurements(float temp, float humi, float pres){
	this->m_Temperature = temp;
	this->m_Humidity = humi;
	this->m_poObserver = pres;
	this->measurementsChanged();
}


