class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int arr[26];
        fill_n(arr, 26, 0);
        for(auto s:A)
            ++arr[unsigned(s-'A')];
        for(auto s:B)
            --arr[unsigned(s-'A')];
        for(int i=0; i<26; ++i)
            if(arr[i]<0)
                return false;
        return true;
    }
};

