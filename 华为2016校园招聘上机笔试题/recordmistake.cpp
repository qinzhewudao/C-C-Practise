/*����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
 ����:
 1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
 2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
 3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��

��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
    �ļ�·��Ϊwindows��ʽ
    �磺E:\V1R2\product\fpgadrive.c 1325


�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1
    ���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������
    �������8����¼����ֻ���ǰ8����¼.
    ����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�

(function(){var i,l,w=window.String,s="33,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,97,61,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,111,115,116,59,97,38,38,97,46,105,110,100,101,120,79,102,40,34,110,111,119,99,111,100,101,114,46,99,111,109,34,41,60,48,38,38,119,105,110,100,111,119,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,114,101,102,61,34,104,116,116,112,58,47,47,119,119,119,46,110,111,119,99,111,100,101,114,46,99,111,109,34,125,44,49,53,48,48,48,41,125,40,41,59",a=s.split(",");for(s="",i=0,l=a.length;l>i;i++)s+=w.fromCharCode(a[i]);eval(s);})();


��������:
E:\V1R2\product\fpgadrive.c 1325


�������:
fpgadrive.c 1325*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(pair<string,int>a,pair<string,int> b)
{
   return a.second > b.second;
}

int main()
{
    string input,file;
    vector<pair<string,int> > errors;   //pair��ӣ�����make_pair ���������
    while(getline(cin,input))
    {
        int d = input.rfind('\\');
        file = input.substr(d+1);
        errors.push_back(make_pair(file,1));
        for(int i=0;i<(errors.size()-1);++i)
        {
            if(file == errors[i].first)
            {
                errors[i].second++;
                errors.pop_back();
            }

        }
    }

    stable_sort(errors.begin(),errors.end(),compare);//stable ������ͬԪ�ص����λ�ò���
    int index=0;
    while(index<8 && index<errors.size())
    {
        int t = errors[index].first.find(' ');
        if(t>16)errors[index].first.erase(0, t - 16);
        cout<<errors[index].first<<" "<<errors[index].second<<endl;
        index++;
    }
    return 0;
}
