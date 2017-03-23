#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxlenth = 1000;
int dp[maxlenth][maxlenth];
int lcs(string str1,string str2)
{
    int lenth1 = str1.size();
    int lenth2 = str2.size();
    int i = 0,j= 0;
    for(i;i<lenth1;i++)dp[i][0]=0;
    for(j;i<lenth2;j++)dp[0][j]=0;
    for(int i = 1;i<=lenth1;++i)
    {
        for(int j = 1;j<=lenth2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[lenth1][lenth2];
}

int main1()
{
    string str;
    while(cin>>str)
    {
       int lenth = str.size();
       if (lenth == 1){
            cout << 0 << endl;
            continue;
        }
       string str1 = str;
       reverse(str1.begin(),str1.end());
       int maxlcs = lcs(str,str1);
       cout<<lenth - maxlcs<<endl;
    }
    return 0;

}
