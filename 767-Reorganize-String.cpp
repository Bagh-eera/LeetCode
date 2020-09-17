class Solution {
public:
    
    struct compare{
        bool operator()(const pair<int,char> k, const pair<int,char> l){
            return k.first < l.first;
        }
    };
    
    string reorganizeString(string S) {
        int n = S.size();
        string ans = "";
        
        priority_queue<pair<int, char>, vector<pair<int,char>>, compare>pq;
        vector<int> hash(26, 0);
        for(char c : S){
            hash[c- 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(hash[i] > (n+1)/2) 
                return ans;
            pair<int, char> p;
            p.second = (char)('a' + i);
            // cout << p.second << " ";
            p.first = hash[i];
            if(p.first != 0)
                pq.push(p);
        }
        while(pq.size() >= 2){
            pair<int, char> p1, p2;
            p1 = pq.top(); pq.pop();
            p2 = pq.top(); pq.pop();
            ans += p1.second;
            ans += p2.second;
            
            p1.first--;
            p2.first--;
            if(p1.first > 0) pq.push(p1);
            if(p2.first > 0) pq.push(p2);
        }
        if(pq.size() > 0)
            ans += pq.top().second;        
        return ans;
    }
};
