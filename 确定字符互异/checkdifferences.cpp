/*��ʵ��һ���㷨��ȷ��һ���ַ����������ַ��Ƿ�ȫ����ͬ����������Ҫ������ʹ�ö���Ĵ洢�ṹ��
����һ��string iniString���뷵��һ��boolֵ,True���������ַ�ȫ����ͬ��False���������ͬ���ַ�����֤�ַ����е��ַ�ΪASCII�ַ����ַ����ĳ���С�ڵ���3000��
*/
/*
1����ϣ��
����char�����ж��ظ�����hash������㣬ֻ��Ҫ256��bool���ͼ��ɣ�O(n)��ʱ�䣨��ʵֻҪ�ж�ǰ257��������O(1)������ԭ����������ĿҪ����ʹ�ö���Ĵ洢�ṹ����ô�������KO����
 2������
��ôֻ��������forѭ��������ʱ�临�Ӷ�ΪO(n*n)�����Ǹ��ݳ���ԭ��û��Ҫ������N��ֻ��Ҫ������ǰ257�͹��ˣ����N<257�ͱ�����N������ʱ�临�Ӷ���ʵΪO(1)!!!
 3������
��Ȼ��ĿҪ����ʹ�ö���ռ䣬�������б�û��const�����ã���ô�Ϳ��Զ��ַ�������Ȼ�����жϣ���ҪO��nlogn)����Ȼ���ٱ���һ��O(n)����ʵҲû��Ҫȫ������ֻ��ǰ257����ͬ����ԭ��
 4��Parition
���ڿ��������partition�����Ա���������ظ�
��Ҳ����ÿ��partition֮���ж��м�keyԪ��������Ԫ���Ƿ���ͬ����ͬ�򷵻�false����ͬ�ٽ�����һ��partition.ʱ�临�Ӷ�Ҳ��O(nlongn)����Ҫ�������ٶȿ졣
*/
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        int size= iniString.size();
        if(size>256)return false;

        /*bool *isDifferent=new bool[256]();

        for(int i=0;i<size;i++)
            {
            if(isDifferent[iniString[i]])
                return false;
            isDifferent[iniString[i]]=true;
        }
        return true;*/
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
                if(iniString[i]==iniString[j])return false;
        return true;
    }
};
