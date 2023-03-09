#include <bits/stdc++.h>
using namespace std;
const int max_node = 1000;
vector<int> graph[max_node];              //store graph's adjacency list
vector<int> transpose_graph[max_node];    //store transpose graph's adjacency list
bool vis[max_node];                       //store node visit stat for dfs
vector<int> node_order;     //store nodes in order of their finish time in dfs
void dfs(int n){
    if(vis[n]) return;  //if node is already visited
    int len= graph[n].size();
    vis[n]= true;
    for(int i= 0; i<len; i++)dfs(graph[n][i]);
    node_order.push_back(n);
}
void dfs_print(int n){
    if(vis[n] == true) return;  //if node is already visited
    cout<< n <<" ";
    int len= transpose_graph[n].size();
    vis[n]= true;
    for(int i= 0; i<len; i++)dfs_print(transpose_graph[n][i]);
}
int kosarajuSCC(int n){
    int scc_count= 0;   //keep count of strongly connected components
    for(int i= 1; i<=n; i++)if(vis[i] == false)dfs(i);
    for(int i= 1; i<=n; i++)vis[i]= false;
    for(int i= node_order.size()-1; i>= 1; i--){
        if(vis[node_order[i]] == false){
            dfs_print(node_order[i]);
            scc_count++;
            cout<<endl;
        }
    }
    node_order.clear();
    return scc_count;
}
int main(void){

    int n,m,u,v;
    cin>>n;
    for(int i=0;i<n;i++)cin>>u;
    for(int i= 0; i<= n; i++){
        vis[i]= false;
        graph[i].clear();
        transpose_graph[i].clear();
    }
    cin>>m;
    for(int i= 0; i<m; i++){
        cin>>u>>v;     //edge u -> v
        u;
        v;
        graph[u].push_back(v);
        transpose_graph[v].push_back(u);
    }
    int components= kosarajuSCC(n);
    cout<< "Components: "<< components <<endl;
}
