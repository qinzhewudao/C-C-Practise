/*СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬
�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
���ܰ��СQ��*/


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
