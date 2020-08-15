#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class person
{
public:
	char name[16];
	int age;
};

int main()
{
	ofstream ofs("person.txt",ios::out|ios::binary);
	
	person p = {"zhangsan",18};
	
	ofs.write((const char *)&p,sizeof(p));

	ofs.close();


	ifstream ifs("person.txt",ios::in|ios::binary);
	if(!ifs.is_open())
	{
		cout<<"open file fail!!"<<endl;
		return 0;
	}
	person p2;
	ifs.read((char*)&p2,sizeof(p2));

	cout<<"name = "<<p2.name<<" --- "<<"age == "<<p2.age<<endl;

	ifs.close();
	return 0;
}
