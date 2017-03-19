# include<iostream>
using namespace std;
int main()
{
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int year;
    int day;
    int count=31;
    int month;
    cin>>year;
    cin>>day;
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
    {
       monthDay[1]=29;
    }
    for(int i=0;i<12,count<day;i++)
    {
        month=i+1;
        count+=monthDay[i+1];

    }
    count-=monthDay[month];
    cout<<month+1<<endl<<day-count;
    return 0;
}
