class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterlogs;
        vector<string> digitlogs;
        
        for(string &s : logs){
            int i = 0;
            while(s[i] != ' ')
                ++i;
            if(isalpha(s[i+1])) 
                letterlogs.push_back(s.substr(i+1) + " " + s.substr(0, i));
            else
                digitlogs.push_back(s);
        }
        
        sort(letterlogs.begin(), letterlogs.end());
        
        for(string &s : letterlogs){
            int i = s.size() - 1;
            while(s[i] != ' ')
                --i;
            s = s.substr(i+1) + " " + s.substr(0, i);
        }
        
        
        for(string &s : digitlogs){
            letterlogs.push_back(s);
        }
        
        return letterlogs;
        
    }
};
