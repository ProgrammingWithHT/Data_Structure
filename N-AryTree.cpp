
// N-Ary Tree
// the is the most simple form of tree.
// it's called N-Ary because a parent node can have N number of childs

#include<iostream>
#include<vector>
using namespace std ;
vector<vector<int>> Vec;

void dfs(int data){
    cout << data << " ";
    for(const int& node: Vec[data]){
        dfs(node);
    }
}


int main(){
    
    int u,v,NumberOfNODE,NumberOfEdges;
    cin>>NumberOfNODE>>NumberOfEdges;
    Vec.resize(NumberOfNODE+1);
    while (NumberOfEdges--) //when 0 break automatically whlle loop
    {
        cin >> u >> v;
        Vec[u].push_back(v);
    }
    dfs(1);

    return 0 ;
}