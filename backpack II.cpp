class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        if(A.empty())   return 0;
        vector<int> res(m+1,0);
        for(int i=A[0]; i<m+1; ++i)
            res[i]=V[0];
        for(int i=1; i<A.size(); ++i)
            for(int j=m; j>=A[i]; --j){
                res[j]=max(res[j], V[i]+res[j-A[i]]);
                if(i==A.size()-1)   break;
            }
        return res.back();
    }
};
