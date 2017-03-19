#include <iostream>
#include <set> 
using namespace std;
 
int main()
{
        int n;
        while (cin >> n)
    {
                // 保持有序        
        multiset<int> s;
                
        unsigned long long sum = 0;
                
        while (n--)
        {
                       
             int i, L;
                        
            cin >> i >> L;
                        if (i == 1)
            {
                                s.insert(L);
                                sum += L;
                            
            }
            else
            {
                                if (s.find(L) != s.end())
                {
                                        s.erase(s.find(L));
                                        sum -= L;
                                    
                }            
            }           
             unsigned long long max_len = *(s.rbegin());
                        if (max_len < sum - max_len) cout << "Yes" << endl;
                        else cout << "No" << endl;
                    
        }    
    }    
    return 0;
}

