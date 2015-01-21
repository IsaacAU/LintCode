class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size()<2) return 0;
        int res=0, minPrice=prices[0];
        for(int i=1; i<prices.size(); ++i){
            res=max(res, prices[i]-minPrice);
            minPrice=min(minPrice, prices[i]);
        }
        return res;
    }
};

