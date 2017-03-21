#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int main() {
    string str1;
    while(cin >> str1)//注意while处理多个case
    {
            map<char,int>hash;
        int len =str1.length(),i=0;
        int count1 = 0;
        for(i;i<len;i++)
        {
            hash[str1[i]]++;
            if(hash[str1[i]]==1)count1++;
            if(hash[str1[i]]>2)count1++;

        }
        i =0;
        for(i;i<len/2;i++)
        {

            if(str1[i]=str1[len-i])hash[str1[i]]--;
            cout<<hash[str1[i]]<<endl;
        }
        i =0;
        int sum = 0;
        for(i;i<32;i++)
        {

            sum+=hash['A'+i];
        }
        cout<<sum<<endl;
    }

    return 0;
}
