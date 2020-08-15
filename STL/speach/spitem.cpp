#include <iostream>
using namespace std;
#include "speach.h"
#include <stdio.h>
#include <map>
#include <vector>


int main()
{
	speach s;

//	for(map<int,speak>::iterator it = s.m.begin();it!=s.m.end();it++)
//		cout<<it->first<<"--"<<it->second.name<<endl;
	s.loadrecorde();

	int choice = 0;
	while(true)
	{
		s.showMenu();		
		cin>>choice;

		switch(choice)
		{
			case 1:		
				s.startspeach();
			break;
			case 2:
				s.showrecorde();
			break;
			case 3:
				s.clearrecorde();
			break;
			case 0:
				system("clear");
				cout<<"exit system"<<endl;
				cout<<"please input any key continue!"<<endl;
				getchar();
				getchar();
			return 0;
		}
	}
	return 0;
}
