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
	int n; cin >> n;
	vector<vector<int>> graph(n);

	for(int i=0; i<n; i++){
		int cant, v; cin >> cant;
		while(cant--){
			cin >> v;
			v--;
			graph[i].push_back(v);
		}
	}

	imprimir(graph);

	return 0;
}