/*��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и������� */
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int cow = array[0].size();
        int i,j;
        for(i = row-1,j=0;i>=0&&j<cow;)
        {
            if(target == array[i][j])return true;
            else if(target < array[i][j])
            {
                --i;
                continue;
            }
            else 
            {
                ++j;
                continue;
            }
        }
        return false;
    }
};