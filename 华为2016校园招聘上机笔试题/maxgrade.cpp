//...switch(op){case :记得要加break呀，猪头，不然会顺序执行所有的语句的}
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        int grade[N];
        int temp;
        char op;
        for(int i=0;i<N;i++)cin>>grade[i];
        int A,B;

        for(int j=0;j<M;++j)
        {
            cin>>op>>A>>B;
            switch(op)
            {
                case 'Q':
                {
                    if(A>B)swap(A,B);
                    temp=grade[A-1];
                    for(int i=A;i<B;i++)
                    {
                       if(grade[i]>temp)temp=grade[i];
                    }
                    cout<<temp<<endl;
                    break;
                }
                case 'U':
                {
                    grade[A-1]=B;
                    break;
                }
            }
        }
    }
    return 0;
}
