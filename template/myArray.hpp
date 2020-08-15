#pragma once 
#include <iostream>
using namespace std;

template<class T>
class myArray
{
private:
	T * paddress;
	int m_cap;
	int m_size;

public:
	myArray(int cap)
	{
		cout<<"you can gouzao"<<endl;
		this->m_cap = cap;
		this->m_size = 0;
		this->paddress = new T[this->m_cap];
	}

	myArray(const myArray& arr)
	{
		cout<<"copy gouzao"<<endl;
		this->m_cap = arr.m_cap;
		this->m_size = arr.m_size;

		paddress = new T[arr.m_cap];
		for(int i = 0;i<this->m_size;i++)
			paddress[i] = arr.paddress[i];
	}
	
	T& operator[](int index)
	{
		return this->paddress[index];
	}
	
	T& operator=(const myArray &arr)
	{
		cout<<" == gouzao"<<endl;
		if(this->paddress != NULL)
		{
			delete [] paddress;
			this->m_cap = 0;
			this->m_size = 0;
		}
		this->m_cap = arr.m_cap;
		this->m_size = arr.m_size;
		this->paddress = new T[this->m_cap];
		for(int i = 0;i<this->m_size;i++)
			paddress[i] = arr.paddress[i];
	}
	
	void Mypush(const T & arr)
	{
		if(this->m_size < this->m_cap)
		{
			paddress[this->m_size] = arr;
			this->m_size++;
		}
		return ;
	}
	
	void mypop()
	{
		if(this->m_size == 0)
			return ;
		this->m_size--;
	}
	
	int getCap()
	{
		return this->m_cap;
	}

	int getSize()
	{
		return this->m_size;
	}


	~myArray()
	{
		cout<<"xigou"<<endl;
		delete [] paddress;
		this->m_cap = 0;
		this->m_size = 0;
	}
};
