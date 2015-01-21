class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    // method one: O(n2) time, O(n) space
    bool anagram(const string &s1, const string &s2){
        if(s1.length()!=s2.length())    return false;
        int arr[26];
        fill_n(arr, 26, 0);
        for(int i=0; i<s1.length(); ++i){
            ++arr[unsigned(s1[i]-'a')];
            --arr[unsigned(s2[i]-'a')];
        }
        for(int i=0; i<26; ++i)
            if(arr[i])
                return false;
        return true;
    }
     
    vector<string> anagrams1(vector<string> &strs) {
        // write your code here
        vector<string> res;
        const int len=strs.size();
        bool visit[len];
        fill_n(visit, len, false);
        for(int i=0; i<len-1; ++i){
            if(visit[i])    continue;
            for(int j=i+1; j<len; ++j){
                if(anagram(strs[i], strs[j])){
                    if(!visit[i]){
                        res.push_back(strs[i]);
                        visit[i]=true;
                    }
                    res.push_back(strs[j]);
                    visit[j]=true;
                }
            }
        }
        return res;
    }
    
    // method two: O(n) time, O(n) space
    vector<string> anagrams2(vector<string> &strs){
        unordered_map<string, vector<int>> m;
        for(int i=0; i<strs.size(); ++i){
            string s=strs[i];
            sort(begin(s), end(s));
            m[s].push_back(i);
        }
        vector<string> res;
        for(auto it=begin(m); it!=end(m); ++it){
            if(it->second.size()>1){
                for(auto i:it->second)
                    res.push_back(strs[i]);
            }
        }
        return res;
    }
};

