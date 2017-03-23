/*请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL||length<0)return;
        int i = 0;
        int oldnumber = 0,newnumber = 0;
        while(str[i]!='\0')
        {
            if(str[i]==' '){newnumber+=2;}
            i++;
        }
        oldnumber = i;
        newnumber += oldnumber;
        if(newnumber>length)return;
        while(oldnumber>=0&&newnumber>oldnumber)
        {
            if(str[oldnumber]==' ')
            {
                str[newnumber--]='0';
                str[newnumber--]='2';
                str[newnumber--]='%';

            }
            else
            {
                str[newnumber--] = str[oldnumber];
            }
            oldnumber--;//如果把这个替换成if里面的oldnumber--就会发生多一个空格的窘境。。。例如hello world 被转成了hello%20 world因为可能if里面的--在else里面执行出了问题吧。
        }
        return;
	}
};