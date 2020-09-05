/*--------------------------------------------------------------------
* Tarea 1: Timer.h 
* Fecha: 03-Ene-2019
* Autor: 
*           A01703455 Luis Jesus Moarales Juarez
*--------------------------------------------------------------------*/

#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <sstream>

class Timer {
private:
	int hours, minutes;

public:
	Timer();
	Timer(int, int);
	Timer(const Timer&);

	int getHours() const;
	int getMinutes() const;
	std::string toString() const;

	void operator= (const Timer&);
	void operator+= (const Timer&);
};

Timer::Timer() : hours(0), minutes(0) {
	
}

Timer::Timer(int hh, int mm) {
	if(mm>59){
		int mintp=mm%60;
		minutes=mintp;
		mintp=mm/60;
		if(hh>=24){
			hh=hh-24;
			hours=mintp+hh;
		}
		hours=mintp+hh;
		
	}else{
	hours=hh;
	minutes=mm;}
}

Timer::Timer(const Timer &t) {
	hours=t.getHours();
	minutes=t.getMinutes();
}

int Timer::getHours() const {
	return hours;
}

int Timer::getMinutes() const {
	return minutes;
}

std::string Timer::toString() const {
	 std::stringstream aux;

	 if (hours < 10) {
		 aux << "0";
	 }
	 aux << hours << ":";
	 if (minutes < 10) {
		 aux << "0";
	 }
	 aux << minutes;
	 return aux.str();
}

void Timer::operator= (const Timer &right) {;
	int h = right.getHours();
	int m = right.getMinutes();
	hours=h;
	minutes=m;
	//return hours;
}

void Timer::operator+= (const Timer &right) {
	int h = right.getHours();
	int m = right.getMinutes();//Supuesto caso para trabajar
	hours=hours+h; // Son 25
	if(hours>=24)
	{
		hours=hours%24;//Sobra 1 por lo tanto en hh:xx seria 01:XX
	}
	minutes=minutes+m; // Son 61 por lo tanto deberian ser las 26:01 == 02:01
	if (minutes>59)
	{
		int temp=minutes/60; //Esto me dara las horas excedentes
		hours=hours+temp; //Se suman a las horas el temporal excedente
		minutes=minutes%60;
	}
	
		
}

bool operator== (const Timer &left, const Timer &right) {
	if ((left.getHours() == right.getHours()) && (left.getMinutes() == right.getMinutes())){
		return true;
		
	}
	else{
		return false;
	}
}
bool operator> (const Timer &left, const Timer &right) {
	if (left.getHours()<right.getHours())
	{
		return false;
	}
	if(left.getHours()==right.getHours())
	{
		if(left.getMinutes()>right.getMinutes())
		{
			return true;
		}
		return false;
	}
	return true;
}

#endif /* TIMER_H_ */
