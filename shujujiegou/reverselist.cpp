#include <iostream>
#include <stack>

using namespace std;

struct Node{
	struct Node * next;
	int data;
	Node(int x):next(NULL),data(x){};
};

int main()
{
	int n;
	while(cin>>n)
	{
		int tmp;
		cin>>tmp;
		struct Node * head = new Node(tmp);
		struct Node * p = head;
		for(int i = 1;i<n;i++)
		{
			cin>>tmp;
			p->next = new Node(tmp);
			p = p->next;
		}
		
		struct Node * former = nullptr;
		struct Node * cur = head;
		struct Node * nn = head->next != nullptr ?head->next:nullptr;
		



	

		
	}

	return 0;
}
