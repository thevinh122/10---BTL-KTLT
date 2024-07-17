#include<iostream>
#include<string>
#include "date.h"
#include<ctime>
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

//Ham tinh so ngay nam vien
int Date::songay(const Date& ngay) {
	struct tm a = { 0, 0, 0, day, month - 1, year - 1900 };
	struct tm b = { 0, 0, 0, ngay.day, ngay.month - 1, ngay.year - 1900 };
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	double difference = difftime(y, x) / (60 * 60 * 24);
	return static_cast <int>(difference);
}


//Ham nhap, xuat ngay
void Date::input() {
	cout << "Nhap ngay sinh: ";
	cin >> day >> month >> year;
}

void Date::display() {
	cout << "Ngay sinh:\t" << day << "-" << month << "-" << year << endl;
}