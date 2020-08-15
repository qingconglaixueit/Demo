#include <iostream>

using namespace std;

struct ListNode
{
	ListNode *next;
	int key;
	ListNode(int x):key(x),next(NULL){}
};

int main()
{
	int n,key,pre;
	while(cin>>n>>key)
	{
		n--;
		ListNode *head = new ListNode(key);
		while(n--)
		{
			cin>>key>>pre;
			ListNode *p = head;
			while(p->key != pre) p = p->next;
			ListNode *tmp = new ListNode(key); 
			tmp->next = p->next;
			p->next = tmp;
		}
		
		cin>>key;
		ListNode * p = head;
		while(p)
		{
			if(p->key != key)	cout<<p->key<<" ";
			p = p->next;
		}
		cout<<endl;
	}





	return 0;
}
