class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        const int len=nums.size();
        if(len<3)
            return res;
        sort(begin(nums), end(nums));
        for(int i=0; i<len-2; ++i){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1, k=len-1;
            while(j<k){
                while(j>i+1 && nums[j-1]==nums[j])    ++j;
                while(k<len-1 && nums[k+1]==nums[k])  --k;
                if(j>=k)    break;
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }else if(sum>0){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        return res;
    }
};

