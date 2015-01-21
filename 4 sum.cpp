class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int>> res;
        const int len=nums.size();
        if(len<4)   return res;
        sort(begin(nums), end(nums));
        for(int i=0; i<len-3; ++i){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1; j<len-2; ++j){
                if(j>i+1 && nums[j-1]==nums[j])
                    continue;
                int m=j+1, n=len-1;
                while(m<n){
                    int sum=nums[i]+nums[j]+nums[m]+nums[n];
                    if(sum==target){
                        res.push_back(vector<int>{nums[i], nums[j], nums[m], nums[n]});
                        ++m;
                        --n;
                    }else if(sum>target){
                        --n;
                    }else{
                        ++m;
                    }
                    while(m>j+1 && nums[m-1]==nums[m])  ++m;
                    while(n<len-1 && nums[n+1]==nums[n])--n;
                }
            }
        }
        return res;
    }
};

