#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <utility>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <tr1/unordered_map>
#include <climits>

using namespace std;

typedef pair<string, int> VertexDistance;
typedef pair<int, string> QDistances;
typedef vector<VertexDistance> VertexAdjacency;
typedef tr1::unordered_map<string, VertexAdjacency> AdjacencyList;
typedef AdjacencyList Graph;
typedef tr1::unordered_map<string, int> Distances;
typedef tr1::unordered_map<string, string> Parents;
Graph G;

void runDijkstras(string, string, int);

int main(int argc, char *argv[])
{
	string filename = argv[1];
	ifstream fin(filename.c_str());
	string edge;
	string fromNode, toNode, weight;
	int nodes, edges;
	if(fin.is_open()) {
		getline(fin, edge);
		istringstream iss(edge);
		iss>>nodes>>edges;
		//cout<<nodes<<" "<<edges<<endl;
		while(getline(fin, edge)) {
			istringstream iss(edge);
			if(!(iss>>fromNode>>toNode>>weight)) {
				perror("Invalid input graph format");
				exit(0);
			}
			int cost = atoi(weight.c_str());
			//cout<<fromNode<<" "<<toNode<<" "<<weight<<endl;
			if(G.count(fromNode) == 0) {
				VertexAdjacency neighbor;
				neighbor.push_back(make_pair(toNode, cost));
				G.insert(make_pair(fromNode, neighbor));
			} else 
				G[fromNode].push_back(make_pair(toNode, cost));
			
		}
		fin.close();
	} else {
		perror("File not opened");
		exit(0);
	}

	//Display the Adjacency List here
	//DisplayGraph();		

	string startNode = argv[2];
	string endNode = argv[3];
	runDijkstras(startNode, endNode,  nodes);
	
	return(0);
}	


void initializeDistances(Distances &D, int V) {
	Graph::iterator it;
	for(it = G.begin(); it != G.end(); ++it)
		D.insert(make_pair(it->first, INT_MAX));	
}

void initializeParents(Parents &P, int V) {
	Graph::iterator it;
        for(it = G.begin(); it != G.end(); ++it)
                P.insert(make_pair(it->first, "None"));
}

void runDijkstras(string startNode, string endNode, int V) {

	set<QDistances> Q;
	Distances D;
	Parents P;
	initializeDistances(D, V);
	initializeParents(P, V);

	D[startNode] = 0;
	Q.insert(make_pair(0, startNode));
	
	while(!Q.empty()) {
		//EXTRACT-MIN
		QDistances node = *Q.begin();
		Q.erase(Q.begin());

		string v = node.second; int d = node.first;

		VertexAdjacency::iterator it;
		for(it = G[v].begin(); it != G[v].end(); ++it) {
                	string v2 = it->first; int cost = it->second;
			if(D[v2] > D[v] + cost) {
				if(D[v2] != INT_MAX)
					Q.erase(Q.find(make_pair(D[v2], v2)));
				D[v2] = D[v] + cost;
				Q.insert(make_pair(D[v2], v2));
				P[v2] = v;
			}
		}
	}

	if(D[endNode] == INT_MAX) {
		cout<<"No route from "<<startNode<<" to destination node "<<endNode<<":"<<endl;
		return;
	}
	cout<<"Path from source "<<startNode<<" to destination node "<<endNode<<":"<<endl;
	string temp_nodes[V];
	int length = 0;
	temp_nodes[length++] = endNode;
	string v = endNode;
	while(P[v].compare(startNode) != 0) {
		temp_nodes[length++] = P[v];
		v = P[v];
	}
	temp_nodes[length] = startNode;
	string path;
	for(int i = length; i >= 0; i--) {
		path.append(temp_nodes[i]);
		path.append(",");
	}
	path.erase(path.end()-1);
	cout<<path<<endl;

}	

void DisplayGraph() {
	VertexAdjacency::iterator it;
        Graph::iterator git;
        for(git = G.begin(); git != G.end(); ++git) {
        	cout<<"Adjacency list of "<<git->first<<": ";
                VertexAdjacency neighbor = git->second;
                for(it = neighbor.begin(); it != neighbor.end(); ++it) {
                	string v2 = it->first; int cost = it->second;
                        cout<<v2<<","<<cost<<"; ";
                }
                cout<<endl;
        }
}					
