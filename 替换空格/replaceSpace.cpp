/*��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��*/
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
            oldnumber--;//���������滻��if�����oldnumber--�ͻᷢ����һ���ո�ľ�������������hello world ��ת����hello%20 world��Ϊ����if�����--��else����ִ�г�������ɡ�
        }
        return;
	}
};