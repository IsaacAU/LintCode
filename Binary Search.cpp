class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int i=0, j=array.size()-1;
        while(i<j){
            int m=(i+j)/2;
            if(array[m]==target){
                while(m>0 && array[m-1]==target)
                    --m;
                return m;
            }else if(array[m]>target)
                j=m;
            else
                i=m+1;
        }
        return -1;
    }
};
