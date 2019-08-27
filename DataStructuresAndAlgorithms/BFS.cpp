void BFS(int s, list<int> *adj) {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i]=false;
    }
    list<int> queue;
    queue.push_back(s);
    visited[s]=true;
    list<int>::iterator i;
    while(!queue.empty()) {
        s=queue.front();
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}
