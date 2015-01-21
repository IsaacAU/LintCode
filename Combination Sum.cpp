class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    void search(vector<int>::iterator b, vector<int>::iterator e, int target, vector<int> &path, vector<vector<int>> &res){
        if(target==0){
            res.push_back(path);
            return;
        }
        if(b==e)
            return;
        for(int i=0; i<=target/(*b); ++i){
            for(int j=0; j<i; ++j)  path.push_back(*b);
            search(next(b), e, target-*b*i, path, res);
            for(int j=0; j<i; ++j)  path.pop_back();
        }
    }
     
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        if(candidates.empty())  return res;
        sort(begin(candidates), end(candidates));
        vector<int> path;
        search(begin(candidates), end(candidates), target, path, res);
        return res;
    }
};
