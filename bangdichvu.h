#pragma once
#include<string>
#include<iostream>
#include"date.h"
using namespace std;

class Banggia {
	string serviceType;
	string roomType;
	Date ngayNhapvien;
	Date ngayXuatvien;
	long long tienTamung;
	long long tongtien;
	long long priceservice;
	long long priceroom;

	static sophongtrong;
public:
	Banggia(string _serviceType = "",string _roomType = "", long long _tienTamung = 0, long long _tongtien = 0, long long _priceservice = 0, long long _priceroom = 0);

	//ham lay, gan ten dich vu
	string getServiceType();
	void setServiceType(string _serviceType);

	//ham lay, gan loai phong
	string getRoomType();
	void setRoomType(string _roomType);

	//ham lay, gan gia dich vu
	long long getPrice();
	void setPrice(long long _price);

	//ham nhap va hien thi
	void input();
	void display();

	//Ham doi loai dich vu, phong
	void changeService(string _serviceType, long long _priceservice);
	void changeRoom(string _roomType, long long _priceroom);

};