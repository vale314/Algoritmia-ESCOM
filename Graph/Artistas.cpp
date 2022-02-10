#include <bits/stdc++.h>

using namespace std;

void imprimir(vector<vector<int>> &graph){
	for(int i=0; i<graph.size(); i++){
		cout << i << " -> ";
		for(auto vecino:graph[i]){
			cout << vecino << " ";
		}
		cout << endl;
	}
}

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n);

	int u,v;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	imprimir(graph);

	return 0;
}