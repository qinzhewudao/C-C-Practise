/*ͷ����2017У�п�ʼ�ˣ�Ϊ�����У�У�������֯��һ����ģ���ĳ����Ŷӡ�ÿ�������˶�����һЩ��Ȥ����Ŀ�����������������Щ��Ŀ��ϳ����ɳ����Գ�������ѡ��֮ǰ�����Ƕ���Ŀ������ä�󣬲�������ÿ������Ѷ�ϵ����һ�����԰���3����������Ŀ���������ǵ��Ѷȴ�С����ֱ�Ϊa, b, c������ϣ����3��������������������

a��= b��= c
b - a��= 10
c - b��= 10

���г�����һ������n����������Ŀ���������������n����ֲ������ɳ������У�1����ೡ��ÿ���ⶼ����ʹ����ֻ����һ�Σ���Ȼ�������������������ƣ�������һЩ����û���չ�3���⣬��˳����˾���Ҫ���һЩ�ʵ��Ѷȵ���Ŀ����ÿ�����Զ��ﵽҪ��Ȼ�����ǳ����Ѿ����ú����ˣ����ܼ�����������ٻ���Ҫ�ٳ���������


								

����

����ĵ�һ�а���һ������n����ʾĿǰ�Ѿ����õ���Ŀ������

�ڶ��и���ÿ����Ŀ���Ѷ�ϵ�� d1, d2, ��, dn��

	
��������

4

20 35 23 40

���

���ֻ����һ�У�������Ĵ𰸡�

	
�������

2
*/




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int num;
  while(cin>>num)
  {
    vector<int> problem;
    for(int i=0;i<num;++i)
    {
      int var1;
      cin>>var1;
      problem.push_back(var1);
    }
    sort(problem.begin(),problem.end());
    int count1=0;
    for(int i=0;i<problem.size();++i)
    {
      if(i+1>=problem.size())
         {
           count1+=2;
           break;
         }
      if(problem[i+1]-problem[i]<=10)
      {
         if(i+2>=problem.size())
         {
          count1++;
          break;
         }
         if(problem[i+2]-problem[i+1]<=10)i+=2;
         else if(problem[i+2]-problem[i+1]>10)
         {
           count1++;
           i+=1;
         }
      }
      else
      {
       count1+=2;
      }
    }
    cout<<count1<<endl;
  }
  return 0;

}
