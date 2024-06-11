#include<iostream>
#include<string>
#include "date.h"

using namespace std;

Date::Date(int _d, int _m, int _y) {
	day = _d;
	month = _m;
	year = _y;
}
void Date::getDate(int& _d, int& _m, int& _y) {
	_d = day; 
	_m = month;
	_y = year;
}

void Date::setDate(int _d, int _m, int _y) {
	day = _d;
	month = _m;
	year = _y;
}

void Date::input() {
	cout << "Nhap ngay sinh: ";
	cin >> day >> month >> year;
}

void Date::display() {
	cout << "Ngay sinh:\t" << day << "-" << month << "-" << year << endl;
}