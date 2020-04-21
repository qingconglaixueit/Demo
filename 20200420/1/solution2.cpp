#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(0);
        ListNode* curr = result;
        ListNode * a = l1;
        ListNode * b = l2;
        int t = 0;
        while(a != NULL || b != NULL)
        {
            int tmpa= 0,tmpb=0;
            if(a != NULL) tmpa = a->val;
            if(b != NULL) tmpb = b->val;
            t = tmpa + tmpb + t;
            curr->next = new ListNode(t%10);
            curr = curr->next;
            if(a != NULL) a = a->next;
            if(b != NULL) b = b->next;
            t = t/10;
        }
        if(t > 0)
        {
            curr->next = new ListNode(t);
        }
        return result->next;	
    }
};

int main(int argc,char *argv[])
{

	ListNode * Head = new ListNode(1);
	ListNode * Head2 = new ListNode(3);
	ListNode * pHead = Head;
	ListNode * pHead2 = Head2;

	//create node
	for (int i = 2;i<=3;i++)
	{
		ListNode * p = new ListNode(i);
		pHead->next = p;
		pHead = p;
	}

	for (int i = 2;i>0;i--)
	{
		ListNode * p = new ListNode(i);
		pHead2->next = p;
		pHead2 = p;
	}
	
	Solution ll;
	ll.addTwoNumbers(Head,Head2);


	return 0;
}
