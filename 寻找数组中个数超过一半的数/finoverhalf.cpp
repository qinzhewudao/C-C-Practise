#include<iostream>
using namespace std;

int findoverhalf(int *a,int len)
{
    int count1 = 0;
    int current;
    for(int i=0;i<len;i++)
    {
        if(count1==0)
        {
            current = a[i];
            count1++;
        }
        else
        {
            if(a[i]==current)count1++;
            else count1--;

        }
    }
    return current;
}
int main()
{
    int a[6]={1,2,4,2,2,3};
    cout<<findoverhalf(a,6);
    return 0;
}
