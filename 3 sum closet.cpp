class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        const int len=nums.size();
        if(len<3)   return 0;
        sort(begin(nums), end(nums));
        int res;
        bool find=false;
        for(int i=0; i<len-2; ++i){
            if(i>0 && nums[i-1]==nums[i])
                continue;
            int j=i+1, k=len-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(!find){
                    res=sum;
                    find=true;
                }else if(abs(sum-target)<abs(res-target))
                    res=sum;
                if(sum==target){
                    return sum;
                }else if(sum>target){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        return res;
    }
};

