class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty())  return 0;
        vector<int> left(prices.size(), 0);
        int minPrice=prices[0];
        for(int i=1; i<prices.size(); ++i){
            minPrice=min(minPrice, prices[i]);
            left[i]=max(left[i-1], prices[i]-minPrice);
        }
        int maxPrice=prices.back(), maxRight=0;
        int res=0;
        for(int i=prices.size()-1; i>0; --i){
            maxPrice=max(maxPrice, prices[i]);
            maxRight=max(maxRight, maxPrice-prices[i]);
            res=max(res, left[i]+maxRight);
        }
        return res;
    }
};
