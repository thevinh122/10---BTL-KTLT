#include<iostream>
#include<string>
#include<iomanip>
#include "benhnhan.h"
using namespace std;

//Dinh nghia benh nhan
Benhnhan::Benhnhan(long _id, string _name, string _quequan, string _tel, int _d, int _m, int _y) : Date(_d, _m, _y) {
	id = _id;
	name = _name;
	quequan = _quequan;
	telnumber = _tel;
}

//dinh nghia ham lay, gan ma benh nhan
long Benhnhan::getId() { return id; }
void Benhnhan::setId(long _id) {
	id = _id;
} 

//dinh nghia ham lay, gan ten benh nhan
string Benhnhan::getName() { return name; }
void Benhnhan::setName(string _name) {
	name = _name;
}


//dinh nghia ham lay, gan que quan benh nhan
string Benhnhan::getQuequan() { return quequan; }
void Benhnhan::setQuequan(string _quequan) {
	quequan = _quequan;
}


//dinh nghia ham lay, gan so dien thoai cho benh nhan
string Benhnhan::getTel() {
	return telnumber;
}
void Benhnhan::setTel(string _tel) {
	telnumber = _tel;
}

//dinh nghia ham nhap, xuat cho benh nhan
void Benhnhan::input() {
	cin.ignore();
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
	cout << "Ma so benh nhan:\t\t" << id << endl;
	cout << "Ho ten:\t\t" << name << endl;
	Date::display();
	cout << "Que quan:\t" << quequan << endl;
	cout << "Dien thoai lien he:\t" << telnumber << endl;
}
	

//dinh nghia ham tim kiem benh nhan
void Benhnhan::timkiembangID(){
	long ma;
	cout << "Nhap ma benh nhan can tra cuu: ";
	cin >> ma;
	if (ma == Benhnhan::id) {
		cout << "Duoi day la thong tin ban can tim: \n";
		 Benhnhan::display();
		 return;
	}
	cout << "Khong the tra cuu! \n";
}

void Benhnhan::timkiembangHT() {
	string ten;
	cout << "Vui long nhap ho ten benh nhan can tra cuu: ";
	getline(cin, ten);
	if (ten == Benhnhan::name) {
		cout << "Day la thong tin ban can tim: \n";
		Benhnhan::display();
		return;
	}
	cout << "Khong the tra cuu! \n";
}

void Benhnhan::timkiembangSDT() {
	string sdt;
	cout << endl;
	cout << "Vui long nhap SDT can tra cuu: ";
	cin >> sdt;
	if (sdt == Benhnhan::telnumber) {
		cout << "Duoi day la thong tin ban can tim: \n";
		Benhnhan::display();
		return;
	}
	cout << "Khong the tra cuu!\n";
}