class Solution {
public:
    /**
     * ����������ζ����Ʊ��λ����ͬ������
     * 
     * @param m ����m
     * @param n ����n
     * @return ����
     */
    int countBitDiff(int m, int n) {
        int diff = m^n;
        int count = 0;
        while(diff!=0)
        {
           diff&=(diff-1);
           count++;
        }
        return count;
    }
};