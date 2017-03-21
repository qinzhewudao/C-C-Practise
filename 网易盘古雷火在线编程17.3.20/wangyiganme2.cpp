
#include <iostream>
using namespace std;
int main()
{
    while(1)//注意while处理多个case
    {

        double dp[3][3];
        int i =0;
        for(i;i<3;i++)
        {
                       int j= 0;
               for(j;j<3;j++)
               {
                  cin>>dp[i][j];
               }
        }

        double a,b;
        cin>>a>>b;
        int j=0;
        int k=0;
        if(a>dp[0][0]&&a>dp[1][0]&&a>dp[2][0])
            {
            cout<<-1<<endl;
        }
        else if(b>dp[0][1]&&b>dp[1][1]&&b>dp[2][1])
        {
            cout<<-1<<endl;
        }
        else{
            double a1 = 0,a2;
        double b1 = 0,b2;
        for(j;j<3;j++)
        {
            if(a1<dp[j][0])
            {
                a1=dp[j][0];
                a2=dp[j][2];
            }
        }
            j=0;
           for(j;j<3;j++)
                {
                if(b1<dp[j][1])
                {
                    b1=dp[j][1];
                    b2=dp[j][2];
                }
          }
          cout<<a2*a+b2*b<<endl;
        }
    }
    return 0;
}
