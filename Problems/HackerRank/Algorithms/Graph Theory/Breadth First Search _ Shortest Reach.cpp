#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define maxNum 1001
using namespace std;
vector<int> ways[maxNum];
int line[maxNum];
int n, m, a, b, i, v, u, strt;
queue<int> holder;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        memset(line, -1, sizeof(line));
        
        
        for (i = 0 ; i < m ; ++i) {
            cin >> a >> b;
            ways[a].push_back(b);
            ways[b].push_back(a);
        }
        
        cin >> strt;
        
        line[strt] = 0;
        holder.push(strt);
        
        while (!holder.empty()) {
            
            u = holder.front();
            
            for (int i = 0 ; i < ways[u].size() ; ++i) {
                v = ways[u][i];
                if (line[v] == -1) {
                    //cout << v << " ";
                    line[v] = line[u] + 1;
                    holder.push(v);
                }
            }
            
            holder.pop();
            
        }
        
        // We will print how far is the nodes to the start point
        for (i = 1; i <= n ; ++i){
            if(line[i] == 0)continue;
            else if(line[i] == -1)cout << line[i] << " ";
            else cout << line[i]*6 << " ";
        }
        cout << endl;
        
        for (i = 0 ; i < n ; ++i){
            
            line[i] = -1;
            ways[i].clear();
            
        }
        
    }
}
