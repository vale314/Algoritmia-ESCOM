#include <bits/stdc++.h>

using namespace std;

void imprimir(vector<vector<int>> &graph){
	for(int i=0; i<graph.size(); i++){
		cout << i+1 << " -> ";
		for(auto vecino:graph[i]){
			cout << vecino+1 << " ";
		}
		cout << endl;
	}
}

bool dfs(int ahora, int padre, int destino, vector<bool> &visited, vector<vector<int>> &graph){
	if(visited[ahora]){
		return false;
	}
	visited[ahora] = true;

	if(ahora == destino){
		return true;
	}

	for(auto vecino:graph[ahora]){
		if(vecino != padre && !visited[vecino] && dfs(vecino, ahora, destino, visited, graph)){
			return true;
		}
	}
	return false;
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

	int inicio, destino; cin >> inicio >> destino;
	inicio--, destino--;
	imprimir(graph);

	vector<bool> visited(n, false);
	cout << "posible: " << dfs(inicio, -1, destino, visited, graph) << endl;

	for(int i=0; i<n; i++){
		cout << "visited[" << i+1 << "]: " << visited[i] << endl;
	}

	return 0;
}
