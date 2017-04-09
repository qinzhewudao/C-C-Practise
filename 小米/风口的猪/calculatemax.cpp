/*���֮�£����ܷɡ������й�����ţ�У����ν����������ꡱ�� ����һ���ع���ʷ�Ļ��ᣬ��֪һ֧��Ʊ����n��ļ۸����ƣ��Գ���Ϊn�����������ʾ�������е�i��Ԫ�أ�prices[i]������ù�Ʊ��i��Ĺɼۡ� ������һ��ʼû�й�Ʊ������������������1�ɶ�������1�ɵĻ��ᣬ��������ǰһ��Ҫ�ȱ�֤����û�й�Ʊ�������ν��׻��ᶼ����������Ϊ0�� ����㷨���������ܻ�õ�������档 ������ֵ��Χ��2<=n<=100,0<=prices[i]<=100
��������:

3,8,5,1,7,8


�������:

12
*/
/*

  ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)�� 
  firstBuy��ʾ��һ�������������棬��Ϊ�ǻ�δ���������Ǽ���ֵ�� 
  firstSell��ʾ��һ��������������棻 
  secondBuy��ʾ�ڶ��������������棬Ϊ�˷�ֹû�����������������Ǹ�ֵ�� 
  secondSell��ʾ�ڶ���������������棻
*/
class Solution {
public:
    /**
     * �������ܻ�õ��������
     * 
     * @param prices Prices[i]����i��Ĺɼ�
     * @return ����
     */
    int calculateMax(vector<int> prices) {
        int firstbuy = INT_MAX;
        int firstsell = 0;
        int secondbuy = INT_MIN;
        int secondsell = 0;
        for(int i=0;i<prices.size();++i)
        {
            firstbuy = min(firstbuy,prices[i]);
            firstsell = max(firstsell,prices[i]-firstbuy);
            secondbuy = max(secondbuy,firstsell-prices[i]);
            secondsell = max(secondsell,secondbuy+prices[i]);
        }
        return secondsell;
    }
};