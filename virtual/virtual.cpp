#include <iostream>

using namespace std;

class father
{
public:
	father()
	{
		cout<<"i am father"<<endl;
	}
	
	virtual void show()
	{
		cout<<"father show"<<endl;
	}
	
	virtual ~father()
	{
		cout<<"~father"<<endl;
	}
};
class child : public father 
{
public:
	child()
	{
		cout<<"i am child"<<endl;
	}

	virtual void show()
	{
		cout<<"child show"<<endl;
	}
	~child()
	{
		cout<<"~child"<<endl;
	}
};

int main()
{
	
	child c;
	father &f = c;
	f.show();
	
	return 0;
}
