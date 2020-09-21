class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ap;
        vector<vector<string>> ans;
        if(strs.size() == 0)
            return ans;
        
        for(string st : strs){
            string temp = st;
            sort(st.begin(), st.end());
            ap[st].push_back(temp);
        }
        
        
        for(auto k: ap){
            ans.push_back(k.second);
        }
        return ans;
    }
};
