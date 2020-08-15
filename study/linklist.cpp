#include <iostream>
#include <vector>

using namespace std;


typedef struct ListNode
{
	struct ListNode * next;
	int value;
}LISTNODE,*PLISTNODE;

PLISTNODE createNode(int value)
{
	PLISTNODE node = (PLISTNODE)malloc(sizeof(LISTNODE));
	node->next = NULL;
	node->value = value;
	return node;
}

void printlist(PLISTNODE head)
{

	if(head == NULL)
		return ;

	PLISTNODE p = head;
	while(p)
	{
		cout<<p->value<<" ";
		p = p->next;
	}
	cout<<endl;
	
}

PLISTNODE searchNode(PLISTNODE head,int num)
{
	PLISTNODE p = head ;
	//cout<<"================="<<endl;
	if(p == NULL)
	{
	//	cout<<"==========p = null======="<<endl;
		return NULL;
	}
	while(p)
	{
		
	//	cout<<"while ---- "<<endl;
		if(p->value == num)	
		{
	//		cout<<"p->value == "<<p->value<<"--num== "<<num<<endl;
			break;
		}
		p = p->next;
	}
	return p;
}

void delNode(PLISTNODE head,int num)
{
	if(head == NULL) return ;
	PLISTNODE p = head ;
	if(p->next == NULL && p->value == num)
	{
		cout<<"==="<<endl;
		head = NULL;
		free(head);
		return ;
	}
	if(p->next !=NULL && p->value == num)
	{
		head = head->next;
		p= NULL;
		free(p);
		return ;
	}

	while(p->next != NULL)
	{
		if(p->next->value == num)
		{
			if(p->next->next != NULL)
			{
				PLISTNODE tmp = p->next;
				p->next = p->next->next;
				tmp->next = NULL;
				tmp = NULL;
				free(tmp);
			}
			else
			{
				PLISTNODE tmp = p->next;
				p->next = NULL;
				free(tmp);	
			}
		}
		p = p->next;

	}
}

int main()
{
	
	int linkNum;
	int headnum;
	int v[64][64];
	int delnum;
	while(cin>>linkNum>>headnum)
	{
		PLISTNODE head = createNode(headnum);
		if(head == NULL)		return -1;
		PLISTNODE p = head;
		for(int i = 0;i<linkNum -1;i++)
		{
			for(int j = 0;j<2;j++)
			{
				cin>>v[i][j];
				if(i == 0 && j == 0)
				{
					PLISTNODE tmp = createNode(v[i][j]);
					if(tmp == NULL) return -1;
					p->next = tmp;
					p = tmp;
				}
				if(j == 1 && i != 0)
				{
					if(p->value != v[i][j])  p = searchNode(head,v[i][j]);
					if(p == NULL)	return -1;
					PLISTNODE tmp = createNode(v[i][j-1]);
					if(tmp == NULL) return -1;
					if(p->next == NULL)				
					{
						p->next = tmp;
						p = tmp;
					}
					else
					{
						tmp->next = p->next;
						p->next = tmp;
						p = tmp;
					}
				}
			}
		}
	//	printlist(head);
		
		cin>>delnum;
		cout<<"-------------"<<endl;
		delNode(head,delnum);
		if(head == NULL)
		{
			cout<<"NULL"<<endl;
		}
		else
		{
			printlist(head);
		}
	
		
		free(head);
	}
	return 0;
}
