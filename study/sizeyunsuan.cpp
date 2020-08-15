#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{

    
    string str;
    while(cin >> str)
    {
        stack<char> oper;//记录操作符
        vector<int> number;//记录数字的位数
        string s;//记录后缀表达式
        //中缀表达式转换后缀表达式
        for(int i = 0;i<str.size();i++)
        {
            if(str[i]>='0' && str[i] <='9')
            {
                int tmp = 0;
                while(i<str.size()&&str[i]>='0' && str[i] <='9')
                {
                    s+= str[i];
                    i++;
                    tmp++;
                }
                i--;
                number.push_back(tmp);
            }
            else if(str[i] == '-' || str[i] == '+')
            {
                if(i >0 && str[i]=='-' && (str[i-1] == '(' || str[i-1]=='[' || str[i-1]=='{'))
                {
                    s += '0';
                    number.push_back(1);
                }
                while(!oper.empty() && (oper.top() == '*' || oper.top() == '/' || oper.top() == '+'||oper.top() == '-'))
                {
                    s += oper.top();
                    oper.pop();
                }
                oper.push(str[i]);
            }
            else if(str[i] == '*' || str[i] == '/')
            {
                while(!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
                {
                    s+=oper.top();
                    oper.pop();
                }
                oper.push(str[i]);
            }
            else if(str[i] == '(' || str[i] == '[' || str[i] == '{')
                oper.push(str[i]);
            else if(str[i] == ')')
            {
                while(oper.top()!='(')
                {
                    s+=oper.top();
                    oper.pop();
                }
                oper.pop();
            }
            else if(str[i] == ']')
            {
                while(oper.top()!='[')
                {
                    s+=oper.top();
                    oper.pop();
                }
                oper.pop();
            }
            else if(str[i] == '}')
            {
                while(oper.top()!='{')
                {
                    s+=oper.top();
                    oper.pop();
                }
                oper.pop();
            }
            else 
            {
                cout<<"invalid operation"<<endl;
            }
        }
        while(!oper.empty())
        {
            s += oper.top();
            oper.pop();
        }
        //处理后缀表达式，并进行计算
        int tmp = 0;
        stack<int> res; 
        for(int i =0;i<s.size();i++)
        {
            if(s[i] >= '0' && s[i] <='9')
            {
                int num = 0;
                while(number[tmp]--)
                    num = num*10 + (s[i++] - '0');
                i--;
                tmp++;
                res.push(num);
            }
            else{
                int num1 = res.top();
                res.pop();
                int num2 = res.top();
                res.pop();
                
                if(s[i] == '+')
                    res.push(num2+num1);
                else if(s[i] == '-')
                    res.push(num2-num1);
                else if(s[i] == '*')
                    res.push(num2*num1);
                else if(s[i] == '/')
                    res.push(num2/num1);
            }
        }
        cout<<res.top()<<endl;
    }
    return 0;
}
