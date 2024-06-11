#pragma once
#include<iostream>
#include<string>
#include"date.h"
using namespace std;

class Benhnhan :public Date{
	long id;
	string name;
	long long telnumber;
	string quequan;
public:
	Benhnhan(long _id = 0, string _name = "", string _quequan ="" , long long _tel = 0, int _d = 0, int _m = 0, int _y = 0);
	long getId();
	void setId(long _id);
	string getName();
	void setName(string _name);
	string getQuequan();
	void setQuequan(string _quequan);
	long long getTel();
	void setTel(long long _tel);
	

	void input();
	void display();
};