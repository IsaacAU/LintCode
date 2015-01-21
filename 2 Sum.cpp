class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    // O(n) space, O(n) time
    vector<int> twoSum1(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            if(m.count(target-nums[i])){
                res.push_back(m[target-nums[i]]);
                res.push_back(i+1);
                break;
            }else{
                m[nums[i]]=i+1;
            }
        }
        return res;
    }
    // O(n) space, O(nlogn) time
    vector<int> twoSum2(vector<int> &nums, int target){
        const int len=nums.size();
        vector<int> idx;    idx.reserve(len);
        for(int i=0; i<len; ++i)
            idx.push_back(i);
        sort(begin(idx), end(idx), [&nums](int x, int y){ return nums[x]<nums[y]; });
        int i=0, j=len-1;
        vector<int> res;
        while(i<j){
            int sum=nums[idx[i]]+nums[idx[j]];
            if(sum==target){
                if(idx[i]<idx[j]){
                    res.push_back(idx[i]+1);
                    res.push_back(idx[j]+1);
                }else{
                    res.push_back(idx[j]+1);
                    res.push_back(idx[i]+1);
                }
                break;
            }else if(sum>target){
                --j;
            }else{
                ++i;
            }
        }
        return res;
    }
};

