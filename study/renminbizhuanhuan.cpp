#include <iostream>
#include <string>

using namespace std;

string showlist[11]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾"};

string parsenum(int n)
{
    string res = "";
    int size = to_string(n).size();
    if(size == 1)
    {
        res+= showlist[n];
    }
    else if(size == 2)
    {
        if(n/10 != 1)    res += showlist[n/10]+"拾";
        else    res += "拾";
        
        if(n%10 >0)    res+= showlist[n%10];
    }
    else if(size == 3)
    {
        res += showlist[n/100]+"佰";
        
        if(n%100/10 == 0)    res += showlist[0];
        else    res += showlist[(n%100)/10]+"拾";
        
        if(n%10 > 0)    res+= showlist[n%10];
    }
    else if(size == 4)
    {
        res += showlist[n/1000]+"仟";
        
        if(n%1000/100 == 0 && n%100/100 == 0 && n%10 == 0){}
        else 
        {
            if(n%1000/100 == 0)   
            {
                res += showlist[0];
            }
            else 
            {
                res += showlist[(n%1000)/100]+"佰";
            }
        
            if(n%1000/100 == 0 && n%100/10 == 0){}
            else if(n%100/10 == 0)
            {
                if(n%10 == 0) {}
                else res += showlist[0];
            }
            else
            {
               res += showlist[(n%100)/10]+"拾"; 
            }
           
            if(n%10 > 0)    res+= showlist[n%10];
        }
        
    }
    return res;
}

int main()
{
    double num;
    while(cin>>num)
    {
        if(num < 1e-2)
        {
            cout<<"人民币零元整"<<endl;
            continue;
        }
        
        string res = "人民币";
        int intnum = (int)num;
        if(intnum > 0)//小数点钱的数大于0
        {
            int count = to_string(intnum).size();
            int flag = 0 * (count > 8) + 1 * (count <=8 && count >4) + 2 * (count <= 4);
            switch(flag)
            {
                case 0 : res += parsenum(intnum / 1e8) + "亿";
                case 1 : res += parsenum(intnum % (int)1e8 / 1e4) + "万";
                case 2 : res += parsenum(intnum % (int)1e4) + "元";
            }
        }
        
        if(num - intnum > 1e-7)
        {
            
        }
        else
        {
            res+="整";
        }
      
        cout<<res<<endl;
        
    }
    
    
    
    
    
    
    return 0;
}


