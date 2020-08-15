#pragma once 
#include <iostream>
#include <vector>
#include <map>
#include "speak.h"
using namespace std;

class speach
{
public:
	vector<int> v1;//di yi ci
	vector<int> v2;//di er ci
	vector<int> v3;//jieguo
	
	map<int,speak> m;

	int m_index;

	bool fileempty;
	map<int,vector<string>> m_res;
	speach();
	~speach();
	void showMenu();
	
	void initspeach();

	void startspeach();

	void speachdraw();

	void speachcontest();
	
	void showspeachresult();

	void saverecorde();

	void loadrecorde();

	void showrecorde();

	void clearrecorde();
	
};
