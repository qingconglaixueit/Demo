#include "speach.h"
#include <algorithm>
#include <time.h>
#include <functional>
#include <deque>
#include <numeric>
#include <fstream>

speach::speach()
{
	initspeach();
}

speach::~speach()
{

}
void speach::showMenu()
{

	cout<<"==============================="<<endl<<
		  "=======1-enter system=========="<<endl<<
		  "=======2-show records=========="<<endl<<
		  "=======3-clear records========="<<endl<<
		  "=======0-exit system==========="<<endl;
}

void speach::initspeach()
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m.clear();
	this->m_index =1;
	string name = "ABCDEFGHIJKL";
	
	string tmp = "suanshou";
	
	for(int i = 0;i<name.size();i++)
	{
		this->v1.push_back(i+10001);
		this->m.insert(pair<int,speak>(i+10001,speak(tmp+name[i])));
	}
}
void speach::startspeach()
{
//kaishi chouqian
	this->speachdraw();
	this->speachcontest();
	this->showspeachresult();

	this->m_index ++;
	
	this->speachdraw();
	this->speachcontest();
	this->showspeachresult();

	this->saverecorde();
	
//chongzhi
	this->initspeach();
	this->loadrecorde();

}

void speach::speachdraw()
{

	srand((unsigned int)time(NULL));
	
	if(this->m_index == 1)
	{
		
		random_shuffle(this->v1.begin(),this->v1.end());
		cout<<"di "<<this->m_index<<" lun chou qian shunxu ruxia:"<<endl;
		  for(auto a:this->v1)
			  cout<<a<<" ";
		  cout<<endl;
	}
	else
	{
		random_shuffle(this->v2.begin(),this->v2.end());
		cout<<"di "<<this->m_index<<" lun chou qian shunxu ruxia:"<<endl;
		  for(auto a:this->v2)
			  cout<<a<<" ";
		  cout<<endl;
	}
}

void speach::speachcontest()
{
	cout<<"start speach contest "<<this->m_index<<endl;
	
	vector<int> bisai;
	if(this->m_index == 1)
		bisai = v1;
	else
		bisai = v2;

	//pingwei dafen

	int num = 0;
	multimap<double,int,greater<double>> tmpscro;
	for(vector<int>::iterator it=bisai.begin();it !=bisai.end();it++)
	{
		num++;
		deque<double> de;
		for(int i = 0;i<10;i++)
		{
			de.push_back((rand()%401 + 600)/10.0f);
		}
		
		sort(de.begin(),de.end(),greater<double>());
		de.pop_front();
		de.pop_back();
		
		double sum = accumulate(de.begin(),de.end(),0.0f);
		double avg = sum/(double)de.size();
		
		//cout<<"bianhao - "<<*it<<"   name - "<<this->m.find(*it)->second.name<<"  avg == "<<avg<<endl;
			
		this->m.find(*it)->second.m_scroce[this->m_index-1] = avg;
		
		tmpscro.insert(make_pair(avg,*it));
		
		if(num%6 == 0)
		{
			cout<<"--------di "<<num/6<<" zu  xuanshou bi sai shuju--------"<<endl;
			for(multimap<double,int,greater<double>>::iterator it = tmpscro.begin();it!=tmpscro.end();it++)
			{
				cout<<"binahao "<<it->second<<"---avg == "<<it->first<<endl;
			}

			int count = 0;
			for(multimap<double,int,greater<double>>::iterator it = tmpscro.begin();it!=tmpscro.end() && count < 3;it++)
			{
				if(this->m_index ==1)
					this->v2.push_back((*it).second);
				else
					this->v3.push_back((*it).second);
				count++;
			}
			tmpscro.clear();
		}
		
	}

	cout<<"-------di "<<this->m_index<<" lun contest wan bi -----------"<<endl;
}


void speach::showspeachresult()
{
	cout<<"---- di "<<this->m_index<<" lun jingji xuanshou ruxia ------"<<endl;
	
	vector<int>  v;
	if(this->m_index == 1)
		v = v2;
	else
		v = v3;

	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout<<"bianhao --"<<*it<<" name = "<<this->m.find(*it)->second.name<<"  avg = "<<this->m.find(*it)->second.m_scroce[this->m_index-1]<<endl;

	}
}

void speach::saverecorde()
{
	fstream fs;
	fs.open("speach.cvs",ios::out|ios::app);
	for(vector<int>::iterator it = v3.begin();it!=v3.end();it++)
		fs<<*it<<","<<this->m.find(*it)->second.m_scroce[1]<<",";
	fs<<endl;
	
	fs.close();
	this->fileempty = false;
	cout<<"------save recorde success!!------"<<endl;
	cout<<"------contest over!!------"<<endl;
}

void speach::loadrecorde()
{
	fstream inf("speach.cvs",ios::in);
	if(!inf.is_open())
	{
		cout<<"file is not exsit"<<endl;
		inf.close();
		return ;
	}
	
	char ch;
	inf>>ch;
	if(inf.eof())
	{
		this->fileempty = true;
		cout<<"file is empty"<<endl;
		inf.close();
		return ;
	}
	
	inf.putback(ch);
	
	this->fileempty = false;
	string data;
	int index = 0;
	while(inf>>data)
	{
		//cout<<data<<endl;
		int pos = -1;
		int start = 0;
		vector<string> v;
		while(start != data.size())
		{
			pos = data.find(",",start);
			if(pos == -1) break;
//			cout<<data.substr(start,pos-start)<<endl;
			v.push_back(data.substr(start,pos-start));
			start = pos+1;
		}


		index++;
		this->m_res.insert(make_pair(index,v));
	}
	inf.close();
}
void speach::showrecorde()
{
	if(this->fileempty) 
	{
		cout<<"recorde is null"<<endl;
		return ;
	}

	if(this->m_res.size() == 0)	return ;
	for(map<int,vector<string>>::iterator it = this->m_res.begin();it != this->m_res.end();it++)
	{
		cout<<"di "<<it->first<<" jie jingji mingdan"<<endl;
		cout<<"guanjun bianhao-"<<it->second[0]<<" -- avg =="<<it->second[1]<<endl;
		cout<<"yajun bianhao-"<<it->second[2]<<" -- avg =="<<it->second[3]<<endl;
		cout<<"jijun bianhao-"<<it->second[4]<<" -- avg =="<<it->second[5]<<endl;
		cout<<endl;
	}

} 
void speach::clearrecorde()
{
	cout<<"==== is clear recorde sure? ====="<<endl;
	cout<<"1 -- sure"<<endl;
	cout<<"2 -- cancle"<<endl;
	int select;
	cin>>select;
	if(select == 1)
	{
		ofstream tfs("speach.cvs",ios::trunc);
		tfs.close();
		
		this->initspeach();
		this->loadrecorde();
		cout<<"clear record success!!"<<endl;
	}
}
