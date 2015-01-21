class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if(A.empty())   return 0;
        vector<int> v(m,0);
        for(int i=A[0]-1; i<m; ++i)
            v[i]=A[0];
        for(int i=1; i<A.size(); ++i)
            for(int j=m-1; j>=A[i]; --j)
                v[j]=max(v[j], A[i]+v[j-A[i]]);
        return v.back();
    }
};
