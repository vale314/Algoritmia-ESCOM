// #include <bits/stdc++.h>

#include <utility>
#include <queue>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector < pair <int, int> > dir = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

int lines, cols;

bool isValid(pair<int,int> pos){
	if(pos.first < 0 || pos.first >= lines)
		return false;
	if(pos.second < 0 || pos.second >= cols)
		return false;
	return true;
}

void bfs(pair<int,int> inicio, pair<int,int> destino, vector<string> &mapa){
	map<pair<int,int>, bool> visited;
	queue<pair<int,int> > q;

	visited[inicio] = true;
	q.push(inicio);

	while(!q.empty()){
		auto ahora = q.front();
		q.pop();
		cout << ahora.first << ", " << ahora.second << endl;

		if(ahora == destino){
			cout << "ya llegue!" << endl;
		}

		for(auto d:dir){
			auto vecino = ahora;
			vecino.first += d.first;
			vecino.second += d.second;

			if(isValid(vecino) && !visited[vecino] && mapa[vecino.first][vecino.second] != '#'){
				visited[vecino] = true;
				q.push(vecino);
			}
		}
	}

	return;
}

int main(){
	cin >> lines >> cols;
	vector<string> mapa(lines);
	for(auto &line:mapa) cin >> line;

	pair<int,int> inicio, destino;
	for(int l=0; l<lines; l++){
		for(int c=0; c<cols; c++){
			if(mapa[l][c] == 'E'){
				inicio = make_pair(l,c);
			}
			if(mapa[l][c] == 'S'){
				destino = make_pair(l,c);
			}
		}
	}

	for(auto line:mapa)
		cout << line << endl;

	bfs(inicio, destino, mapa);

	return 0;
}