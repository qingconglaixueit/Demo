#include <iostream>
#include <string>

using namespace std;

int main()
{
    string key,str;
    while(cin>>key>>str)
    {
        int helper[26]={0};
        string table;
        for(auto &c : key)
        {
            c = toupper(c);
            if(!helper[c- 'A'])
            {
                table.push_back(c);
                helper[c - 'A'] = 1;
            }
        }
        
        string tmp = table;
        for(int i = 'A';i<='Z';i++)
        {
            if(string::npos == tmp.find(i))
            {
                table.push_back(i);
            }
        }
        
        for(auto &c : str)
        {
            if(isupper(c))
                c = toupper(table[c-'A']);
            else
                c = tolower(table[c-'a']);
        }
        cout<<str<<endl;
    }
    return 0;
}
