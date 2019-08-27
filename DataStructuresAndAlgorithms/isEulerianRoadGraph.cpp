int isEulerian(list<int> *adj) {
    if(isConnected() == false) {
        return 0;
    }
    int odd = 0;
    for(int i=0; i<V; i++) {
        if(adj[i].size() & 1)
            odd++;
    }
    if(odd>2)
        return 0;
    return (odd)? 1:2;
}
