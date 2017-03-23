/*小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，
各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？*/


#include<iostream>
#include<string>
using namespace std;
int main2()
{
    string s;
    while(cin>>s)
    {
        for(int i=0;i<s.size()-1;i++)
        for(int j=0;j<s.size()-1-i;j++)
        if((s[j]>='A'&&s[j]<='Z')&&(s[j+1]<'A'||s[j+1]>'Z'))
                {
                    cout<<s[j]<<" "<<s[j+1]<<endl;
                    char c=s[j];
                    s[j]=s[j+1];
                    s[j+1]=c;
                }
        cout<<s<<endl;
    }
}
