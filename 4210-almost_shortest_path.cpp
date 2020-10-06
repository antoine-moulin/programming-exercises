// source :
// https://www.40tude.fr/blog/algorithme-de-dijkstra-en-c/

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

const int MAX_WEIGHT = 1e3 + 1;

auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {return a.second > b.second; };


int Dijkstra(int NbNodes, int NbEdges, int u_nodes[], int v_nodes[], int weights[], int StartNode, int EndNode) {

	vector<vector<pair<int, int>>> G(NbNodes);
	for (auto i = 0; i != NbEdges; ++i) {
		if (weights[i] != MAX_WEIGHT) { G[u_nodes[i]].push_back(make_pair(v_nodes[i], weights[i])); }
	}

	vector<int> Distances(NbNodes, numeric_limits<int>::max());

	Distances[StartNode] = 0;

	vector<int> Parents(NbNodes, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);
	Q.push(make_pair(StartNode, 0));

	while (!Q.empty()) {
		int v = Q.top().first;
		int w = Q.top().second;
		Q.pop();

		if (w <= Distances[v]) {

			for (const auto& i : G[v]) { 
				auto v2 = i.first;
				auto w2 = i.second;

				if ((Distances[v] + w2 < Distances[v2]) && (w2 != MAX_WEIGHT)) {
					Distances[v2] = Distances[v] + w2;
					Parents[v2] = v;
					Q.push(make_pair(v2, Distances[v2]));
				}
			}
		}
	}

	for (auto p = EndNode; p != -1; p = Parents[p]) {
		for (int k = 0; k<NbEdges; k++)
			if ((v_nodes[k] == p) && (u_nodes[k] == Parents[p])) { weights[k] = MAX_WEIGHT; }
	}

	return Distances[EndNode];
}

int main() {

	int NbNodes, NbEdges;
	int StartNode, EndNode;

	while(true) {

		// input ---------------------------------------------------------------------------------------------------------
		cin >> NbNodes >> NbEdges; 
		if ((NbNodes == 0) && (NbEdges == 0)) return 0;

		cin >> StartNode >> EndNode;


		int u_nodes[NbEdges], v_nodes[NbEdges], weights[NbEdges];

		for (auto i = 0; i != NbEdges; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			u_nodes[i] = u;
			v_nodes[i] = v;
			weights[i] = w;
		}


		// resolution -------------------------------------------------------------------------------------------------------
	 	int almost_shortest_distance = Dijkstra(NbNodes, NbEdges, u_nodes, v_nodes, weights, StartNode, EndNode);
		int tmp = almost_shortest_distance;

		while (tmp == (almost_shortest_distance = Dijkstra(NbNodes, NbEdges, u_nodes, v_nodes, weights, StartNode, EndNode)))
			tmp = almost_shortest_distance;

		if (almost_shortest_distance == numeric_limits<int>::max())
			almost_shortest_distance = -1;

		cout << almost_shortest_distance << endl;

	}
	return 0;
}