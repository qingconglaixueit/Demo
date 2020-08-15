#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	#if 0
	ofstream of;
	of.open("info.txt",ios::out);
	
	of<<"zhangsan\t18\tnan"<<endl;
	of<<"lisi\t\t18\tnv"<<endl;
	of<<"wanwger\t\t18\tnan"<<endl;

	of.close();
	#endif

	ifstream ifs;
	ifs.open("info.txt",ios::in);
	if(!ifs.is_open())
	{
		cout<<"open fail!!"<<endl;
		return 0;
	}

	string data;
	//while(ifs>>data)
	while(getline(ifs,data))
	{
		cout<<data<<endl;
	}

	ifs.close();



	return 0;
}
