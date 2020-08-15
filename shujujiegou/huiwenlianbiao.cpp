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
		struct Node * slow;
		struct Node * quick;
		int tmp;
		cin>>tmp;
		struct Node * head = new Node(tmp);
		struct Node * p = head;
		for(int i = 1;i<n;i++)
		{
			cin >> tmp;
			p->next = new Node(tmp);
			p = p->next;
		}
		slow = head;
		quick = head;
		stack<int> s;
		while(quick->next != NULL && quick->next->next != NULL)
		{
			quick = quick->next->next;
			s.push(slow->data);
			slow = slow->next;
		}
		int flag = 1;
		//jishu
		if(quick->next == NULL)	
		{
			slow = slow->next;
			while(slow)
			{
				if(slow->data != s.top())
				{
					flag = 0;
					break;
				}
				s.pop();
				slow = slow->next;
			}
		}
		else
		{
			s.push(slow->data);
			slow = slow->next;
			while(slow)
			{
				if(slow->data != s.top())
				{
					flag = 0;
					break;
				}
				slow = slow->next;
				s.pop();
			}

		}
		if(flag)
			cout<<"is huiwen lianbiao"<<endl;
		else
			cout<<"is not  huiwen lianbiao"<<endl;
	}
	return 0;
}
