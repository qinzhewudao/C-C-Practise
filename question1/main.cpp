#include <iostream>

using namespace std;

int main()
{
    int a[1000],b,c=1,d;
    cin>>b;
    for(int i= 0;i<b;i++)
    {
      cin>>a[i];
    }
    d = a[0];
    for(int i= 0;i<b;i++)
    {
      if(a[i]!=d)
      {
          c++;
          d = a[i];
      }
    }

    cout <<c<< endl;
    return 0;
}
