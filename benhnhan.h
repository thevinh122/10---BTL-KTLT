#pragma once
#include<iostream>
#include<string>
#include"date.h"
using namespace std;

class Benhnhan :public Date{
	//Khai bao ma benh nhan, ho ten, sdt, que quan
	long id;
	string name;
	string telnumber;
	string quequan;
	static long long tongsobenhnhan;
public:
	Benhnhan(long _id = 0, string _name = "", string _quequan ="" ,string _tel = "", int _d = 0, int _m = 0, int _y = 0);
	
	//tao ham lay, gan ma benh nhan
	long getId();
	void setId(long _id);

	//tao ham lay, gan ho ten
	string getName();
	void setName(string _name);

	//tao ham lay, gan que quan
	string getQuequan();
	void setQuequan(string _quequan);

	//tao ham lay sdt, gan sdt
	string getTel();
	void setTel(string _tel);

	//tao ham tim kiem
	void timkiembangID();
	void timkiembangHT();
	void timkiembangSDT();


	
	//tao ham nhap, xuat
	void input();
	void display();
};