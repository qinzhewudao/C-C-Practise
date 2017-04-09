/*风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100
输入例子:

3,8,5,1,7,8


输出例子:

12
*/
/*

  时间复杂度O(n), 空间复杂度O(1)。 
  firstBuy表示第一次买入的最大收益，因为是还未买入所以是极大值； 
  firstSell表示第一次卖出的最大收益； 
  secondBuy表示第二次买入的最大收益，为了防止没有买便卖的情况所以是负值； 
  secondSell表示第二次卖出的最大收益；
*/
class Solution {
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
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