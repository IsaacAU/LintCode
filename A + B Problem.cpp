class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    // recursion
    int aplusb1(int a, int b) {
        // Just submit this code, then you will get accepted!
        if(a&b)
            return aplusb((a&b)<<1, a^b);
        else
            return a^b;
    }
    // iterative
    int aplusb2(int a, int b){
        while(a&b){
            int tmp=a;
            a=(a&b)<<1;
            b=tmp^b;
        }
        return a^b;
    }
};
