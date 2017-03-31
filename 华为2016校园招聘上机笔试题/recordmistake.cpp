/*开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
 处理:
 1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
 2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
 3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
    文件路径为windows格式
    如：E:\V1R2\product\fpgadrive.c 1325


输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1
    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
    如果超过8条记录，则只输出前8条记录.
    如果文件名的长度超过16个字符，则只输出后16个字符

(function(){var i,l,w=window.String,s="33,102,117,110,99,116,105,111,110,40,41,123,118,97,114,32,97,61,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,111,115,116,59,97,38,38,97,46,105,110,100,101,120,79,102,40,34,110,111,119,99,111,100,101,114,46,99,111,109,34,41,60,48,38,38,119,105,110,100,111,119,46,115,101,116,84,105,109,101,111,117,116,40,102,117,110,99,116,105,111,110,40,41,123,119,105,110,100,111,119,46,108,111,99,97,116,105,111,110,46,104,114,101,102,61,34,104,116,116,112,58,47,47,119,119,119,46,110,111,119,99,111,100,101,114,46,99,111,109,34,125,44,49,53,48,48,48,41,125,40,41,59",a=s.split(",");for(s="",i=0,l=a.length;l>i;i++)s+=w.fromCharCode(a[i]);eval(s);})();


输入例子:
E:\V1R2\product\fpgadrive.c 1325


输出例子:
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
    vector<pair<string,int> > errors;   //pair组队，利用make_pair 来生成组队
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

    stable_sort(errors.begin(),errors.end(),compare);//stable 保持相同元素的相对位置不变
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
