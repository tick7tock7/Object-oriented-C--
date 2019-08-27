void DFS(int v, bool visited[], list<int> *adj){
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) {
            DFS(*i, visited, adj);
        }
    }
}
