class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    // method 1
    int digit(int k, int x){
        if(k==0 && x==0)    return 1;
        int res=0;
        while(x){
            if(x%10==k)
                ++res;
            x/=10;
        }
        return res;
    }
     
    int digitCounts1(int k, int n) {
        // write your code here
        int res=0;
        for(int i=0; i<=n; ++i)
            res+=digit(k,i);
        return res;
    }
    
    // method 2
    int digitCounts2(int k, int n){
        int left, right=0, x, cnt=1, res=0;
        while(n){
            left=n/10;
            x=n%10;
            if(x<k){
                res+=left*cnt;
            }else if(x==k){
                res+=left*cnt+right+1;
            }else{
                res+=(left+1)*cnt;
            }
            n=left;
            right+=x*cnt;
            cnt*=10;
        }
        return res;
    }
};
