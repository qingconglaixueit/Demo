#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node{
	T data;
	unique_ptr<Node<T>> next;
	~Node(){
		cout<<"~node"<<endl;
	};
};


template <typename T>
class link{
public:
	void front(const T& data)
	{
		auto node = make_unique<Node<T>>();
		node->data = data;
		node->next = move(head.next);
		head.next = move(node);
	}
	
	void print()
	{
		Node<T> * node = head.next.get();
		while(node)
		{
			cout<<node->data<<" ";
			node = node->next.get();
		}
		cout<<endl;
	}
	
	~link()
	{
		cout<<"~link()"<<endl;
	}

private:
	Node<T> head;

};

int main()
{
	link<int> lk;

	for(int val:{1,2,3,4,5})
	{
		lk.front(val);	
	}

	lk.print();

	return 0;
}

