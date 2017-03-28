/*链接：https://www.nowcoder.com/questionTerminal/97b1f5397e054bf895c82ccf2993fd60
来源：牛客网

给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）
 例如：给定一个长度为8的数组A{1,3,5,2,4,6,7,8}，则其最长的单调递增子序列为{1,2,4,6,7,8}，长度为6. 
  


输入描述:

第一行包含一个整数T，代表测试数据组数。
对于每组测试数据：
N-数组的长度
a1 a2 ... an （需要计算的数组）
保证：
1<=N<=3000,0<=ai<=MAX_INT.
  


输出描述:

对于每组数据，输出一个整数序列，代表最长递增子序列。
若有多组最长上升子序列，输出第一组。
保证：1<=T<=20,1<=N<=3000,0<=ai<=MAX_INT.


(function(){var i,l,w=window.String,s="33,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,97,61,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,111,115,116,59,97,38,38,97,46,105,110,100,101,120,79,102,40,34,110,111,119,99,111,100,101,114,46,99,111,109,34,41,60,48,38,38,119,105,110,100,111,119,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,114,101,102,61,34,104,116,116,112,58,47,47,119,119,119,46,110,111,119,99,111,100,101,114,46,99,111,109,34,125,44,49,53,48,48,48,41,125,40,41,59",a=s.split(",");for(s="",i=0,l=a.length;l>i;i++)s+=w.fromCharCode(a[i]);eval(s);})();


输入例子:
2
7
89 256 78 1 46 78 8
5
6 4 8 2 17


输出例子:
1 46 78
6 8 17*/
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        for(int m=0; m<n; m++)
        {
            int size,max=0,lastpos;
            cin>>size;
            vector<int >array(size);
            for(int j=0; j<size; j++)
            {
                cin>>array[j];

            }
            vector<int > dp(size);
            vector<int > pos(size);
            for(int i=0; i<size; i++)
            {
                dp[i]=1;
                for(int j=0; j<i; j++)
                {
                    if(array[i]>array[j])
                    {
                        if(dp[j]+1>dp[i])
                        {
                            dp[i]=dp[j]+1;
                            pos[i]=j;

                        }
                        if(max<dp[i])
                        {
                            max=dp[i];
                            lastpos=i;
                        }
                    }
                }
            }
            vector<int >ans;
            for(int i=0; i<max; i++)
            {
                ans.push_back(array[lastpos]);
                lastpos=pos[lastpos];

            }
            for(int i=max-1; i>=1; i--)cout<<ans[i]<<' ';
            cout<<ans[0]<<endl;

        }
    }
    return 0;
}
