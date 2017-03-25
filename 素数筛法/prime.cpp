#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

void make_prime(bool prime[],int N)  {

     for(int i=3; i<N; i++)
     {
            if(i%2) prime[i]=true;
            else prime[i]=false;
     }
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    for (int i=2;i<N;i++)
      if (prime[i]) {
        for (int k=i*i; k<N; k+=i)
            prime[k]=false;
      }
    return;
}

int main()
{
    bool prime[31700];
    make_prime(prime,31700);
    for(int i = 0;i<31700;i++)
    {
        if(prime[i]==true)
            cout<<i<<endl;
    }
}
