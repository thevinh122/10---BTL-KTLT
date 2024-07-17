//#include<iostream>
//#include<string>

#include<bits/stdc++.h>
#include"bangdichvu.h"

using namespace std;

Banggia::Banggia(string _serviceType, string _roomType, long long _tienTamung, long long _tongtien, long long _priceservice, long long _priceroom) {
	serviceType = _serviceType;
	roomType = _roomType;
	tienTamung = _tienTamung;
	tongtien = _tongtien;
	priceservice = _priceservice;
	priceroom = _priceroom;
}

//Dinh nghia cho ham lay, gan dich vu
string Banggia::getServiceType() {
	return serviceType;
}
void Banggia::setServiceType(string _serviceType) {
	serviceType = _serviceType;
}

//Dinh nghia ham lay, gan loai phong
string Banggia::getRoomType() {
	return roomType;
}
void Banggia::setRoomType(string _roomType) {
	roomType = _roomType;
}

//Dinh nghia ham lay, gan gia dich vu
long long Banggia::getPrice() {
	return price;
}
void Banggia::setPrice(long long _price) {
	price = _price;
}

//Ham nhap
void Banggia::input() {
	cout << "Nhap loai dich vu (1. Kham dich vu\n 2. Cap cuu\n 3. Kham benh co BHYT\n 4. Kham benh thuong\n 5. Khac";
	cin >> serviceType;
	cout << "Nhap gia dich vu: "; cin >> priceservice;

	cout << "Nhap loai phong (1. Phong dich vu\n2. Phong thuong: "; 
	cin >> roomType;
	cout << "Nhap gia phong: "; 
	cin >> priceroom;
	
	cout << "Nhap ngay vao vien (ngay - thang - nam): "; cin >> ngayNhapvien.input();
	cout << "Nhap ngay ra vien (ngay - thang - nam) "; cin >> ngayXuatvien.input();
	cout << "Nhap so tien da tam ung(dong truoc): "; cin >> tienTamung;

}

void Banggia::display() {
	cout << "Loai dich vu: ";
	switch (serviceType)
	{
	case 1: cout << "Kham dich vu." << endl; break;
	case 2: cout << "Cap cuu." << endl; break;
	case 3: cout << "Kham co BHYT." << endl; break;
	case 4: cout << "Kham benh thuong." << endl; break;
	case 5: cout << "Khac." << endl; break;
	default:
		break;
	}

	cout << "Loai phong su dung: ";
	switch (roomType)
	{
	case 1: cout << "Phong dich vu" << endl; break;
	case 2: cout << "Phong thuong" << endl; break;
	default:
		break;
	}
	cout << "Gia phong su dung: " << price;

	cout << "Ngay nhap vien: " << ngayNhapvien.display();
	cout << "Ngay xuat vien: " << ngayXuatvien.display();
	int songay1 = ngayNhapvien.songay(ngayXuatvien);
	cout << "So ngay nam vien: " << songay1;

	cout << "So tien da tam ung truoc: " << tienTamung << endl;
	cout << "So tien con phai thanh toan(du kien): " << songay1 * (priceroom + priceservice) - tienTamung << "VND" << endl;
}

//Dinh nghia ham doi dich vu
void Banggia::changeService(string _serviceType, long long _priceservice) {
	serviceType = _serviceType;
	priceservice = _priceservice;
}

void Banggia::changeRoom(string _roomType, long long _priceroom) {
	roomType = _roomType;
	priceroom = _priceroom;
}