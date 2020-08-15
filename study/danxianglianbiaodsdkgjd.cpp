#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode * next;
    ListNode(int x):value(x),next(NULL){};
};

int main()
{
    int n;
    while(cin >> n)
    {
        ListNode * head = NULL;
        ListNode * p = head;
        int num;
        for(int i =0;i<n;i++)
        {
            cin >>num;
            if(i == 0)
            {
                ListNode * tmp = new ListNode(num);
                if(tmp == NULL)    return 0;
                head = tmp;
				p = tmp;
            }else
            {
                ListNode * tmp = new ListNode(num);
                if(tmp == NULL)    return 0;
                p->next = tmp;
				p = p->next;
            }
        }
		

        cin>>num;
        if(num == 1 && n == 1)
		{
            cout<<head->value<<endl;
			continue;
		}
        else if(num<1 || num >n){continue;}
        
        int i = 0;
         p = head;
        while( i<(n-num) )
        {
            p = p->next;
            i++;
        }
        cout<<p->value<<endl;

		delete(head);
    }
    return 0;
}


