#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct person
	:enable_shared_from_this<person>{
	string str;

	void show()
	{
		cout<<str<<endl;
	}
	
	~person()
	{
		cout<<"~person"<<endl;
	}

	shared_ptr<person> getshared()
	{
		return shared_from_this();
	}

};

int main()
{
	#if 0
	shared_ptr<person> ptr(new person);
	cout<< ptr.use_count()<<endl;
	
	shared_ptr<person> ptr2 = ptr;
	cout<< ptr.use_count()<<endl;

	shared_ptr<person> a = make_shared<person>();
	cout<< a.use_count()<<endl;
	a = ptr2;
	cout<< ptr.use_count()<<endl;


	shared_ptr<person> mm = a->getshared();
	
	#endif

	shared_ptr<person> ptr;
	{
		shared_ptr<person> ptr2(new person);
		ptr2->str = "hello";
		
		ptr = ptr2->getshared();	
		cout<< ptr.use_count()<<endl;
	}
	ptr->show();

	return 0;
}

