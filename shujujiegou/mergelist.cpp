#include <iostream>
#include <stack>

using namespace std;

struct Node{
	struct Node * next;
	int data;
	Node(int x):next(NULL),data(x){};
};

struct Node * mergelist(struct Node * head1,struct Node *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;
	if(head1->data > head2->data)
	{
		head2->next = mergelist(head2->next,head1);
		return head2;
	}
	else
	{
		head1->next = mergelist(head1->next,head2);
		return head1;
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		int tmp;
		cin>>tmp;
		struct Node  *head1 =  new Node(tmp);
		struct Node *p = head1;
		for(int i = 1;i<n;i++)
		{
			cin>>tmp;
			p->next = new Node(tmp);
			p = p->next;
		}
		cin>>n;
		cin>>tmp;
		struct Node *head2 =  new Node(tmp);
		struct Node *pp = head2;
		for(int i = 1;i<n;i++)
		{
			cin>>tmp;
			pp->next = new Node(tmp);
			pp = pp->next;
		}
		head1 = mergelist(head1,head2);
		while(head1)
		{
			cout<<head1->data<<" ";
			head1 = head1->next;
		}
		cout<<endl;
	}

	return 0;
}
