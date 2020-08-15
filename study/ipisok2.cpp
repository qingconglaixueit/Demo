#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
vector<unsigned> res;
bool ipisok(string & str)
{

	int dot ;
	dot = str.find_first_of('.');
	while(dot!=-1)
	{
		stringstream stream;
		unsigned int num;
		stream<<str.substr(0,dot);
		stream>>num;
		res.push_back(num);
		str = str.substr(dot+1,str.size()-dot);
		dot = str.find_first_of('.');
	}
	stringstream stream;
	unsigned int num;
	stream<<str;
	stream>>num;
	res.push_back(num);
	
	if(res.size()<4)
		return false;
	
	int i;
	for(i=0;i<4;i++)
	{
		if(res[i]<0 || res[i]>255)
			break;
	}

	if(i == 4)
		return true;
	else
		return false;
}



int main()
{

	string str;
	while(cin>>str)
	{
		bool ret = ipisok(str);
		if(ret)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		res.clear();
	}
	return 0;
}
