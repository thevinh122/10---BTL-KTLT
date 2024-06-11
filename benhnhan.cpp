#include<iostream>
#include<string>
#include<iomanip>
#include "benhnhan.h"
using namespace std;


Benhnhan::Benhnhan(long _id, string _name, string _quequan, long long _tel, int _d, int _m, int _y) : Date(_d, _m, _y) {
	id = _id;
	name = _name;
	quequan = _quequan;
	telnumber = _tel;
}

long Benhnhan::getId() { return id; }
void Benhnhan::setId(long _id) {
	id = _id;
} 

string Benhnhan::getName() { return name; }
void Benhnhan::setName(string _name) {
	name = _name;
}

string Benhnhan::getQuequan() { return quequan; }
void Benhnhan::setQuequan(string _quequan) {
	quequan = _quequan;
}

long long Benhnhan::getTel() {
	return telnumber;
}
void Benhnhan::setTel(long long _tel) {
	telnumber = _tel;
}
void Benhnhan::input() {
	cout << "====================================" << endl;
	cout << "Nhap thong tin benh nhan: " << endl;
	cout << "Ho va ten benh nhan: ";
	getline(cin, name);
	Date::input();
	cout << "Nhap ma so benh nhan: ";
	cin >> id;
	cout << "Dien thoai lien he: ";
	cin >> telnumber;
	cin.ignore();
	cout << "Que quan: ";
	getline(cin, quequan);

}

void Benhnhan::display() {
	cout << endl;
	cout << "Thong tin benh nhan la: " << endl;
	cout << "Ho ten:\t\t" << name << endl;
	Date::display();
	cout << "Ma so benh nhan:\t\t" << id << endl;
	cout << "Que quan:\t" << quequan << endl;
	cout << "Dien thoai lien he:\t" << telnumber<<endl;
}