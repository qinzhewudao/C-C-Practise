#include <iostream>
using namespace std;
int main() {
    int N,M,j=0;
    while(cin >> N >> M)//注意while处理多个case
    {
        int A[N];
        for(j;j<N;j++)
        {
          A[j]=0;
        }
        int i = 0;
        int min1,max1;
        for(i;i<M;i++)
        {
            cin>>min1>>max1;
            int z=min1;
            for(z;z<=max1;z++)
            {
                A[z-1]++;
                A[z-1]%=2;
            }
        }
        int k = 0;
        for(k;k<N;k++)
        {
        cout<<A[k];
        }
    }

    return 0;
}
