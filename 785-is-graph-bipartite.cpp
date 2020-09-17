class Solution {
public:
    vector<int> color;
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        color.assign(nodes, -1);
        
        for(int start = 0; start < nodes; start++){
            
            
            if(color[start] == -1){
                queue<int> q;
                q.push(start);
                color[start] = 0;
                
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();

                    for(int neighbour : graph[cur]){
                        if(color[neighbour] == -1){
                            q.push(neighbour);
                            color[neighbour] = 1 ^ color[cur];
                        }
                        else if(color[neighbour] == color[cur]){
                            return false;
                        }
                    }
                }
            }
        }        
        return true;
        
    }
};
