class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	void search(vector<int>::iterator b, vector<int>::iterator e, int target, vector<int> &path, vector<vector<int>> &res){
	    if(target==0){
	        res.push_back(path);
	        return;
	    }
	    if(b==e)    return;
	    int cnt=1;
	    while(next(b)!=e && *b==*next(b)){
	        advance(b,1);
	        ++cnt;
	    }
	    for(int i=0; i<=cnt; ++i){
	        if(*b*i>target) break;
	        for(int j=0; j<i; ++j)  path.push_back(*b);
	        search(next(b), e, target-*b*i, path, res);
	        for(int j=0; j<i; ++j)  path.pop_back();
	    }
	}
	 
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> res;
        if(num.empty()) return res;
        vector<int> path;
        sort(begin(num), end(num));
        search(begin(num), end(num), target, path, res);
        return res;
    }
};
