#include <iostream>
#include <deque>

using namespace std;

void printinfo(const deque<int> & d)
{
	for(deque<int>::const_iterator it = d.begin();it!=d.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}
int main()
{
	deque<int> d;
	for(int i = 0;i<10;i++)
		d.push_front(i);
	printinfo(d);
	return 0;
}
