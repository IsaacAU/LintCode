class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n<3) return n;
        int x=1,y=2;
        for(int i=3; i<=n; ++i){
            swap(x,y);
            y+=x;
        }
        return y;
    }
};

