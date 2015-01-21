class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<int> convert(vector<int> &ones){
        vector<int> res;
        for(int i=0; i<ones.size(); ++i)
            if(ones[i])
                res.push_back(i+1);
        return move(res);
    }
     
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        if(k==0)    return res;
        vector<int> ones(k, 1);
        for(int i=0; i<n-k; ++i)    ones.push_back(0);
        do{
            res.push_back(convert(ones));
        }while(prev_permutation(begin(ones), end(ones)));
        return res;
    }
};
