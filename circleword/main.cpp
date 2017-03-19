#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int main()
{
    int n ;
    cin >>n;
    if(n==0)
    {
     cout <<0;
     return 0;
    }
    float sum =0.0;
    for(int i =1 ; i<=n ; i++)
    {
      sum+= 1.0/i;
    }
    printf("%.4f",sum);

    return 0;
}
