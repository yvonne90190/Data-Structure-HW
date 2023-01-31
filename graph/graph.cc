#include<vector>
#include<string>
#include<unordered_map>
#include <iostream>
using namespace std;


class vertex {
public:
	int id;
	string name;
	vector<int> inEdgeIds;
	vector<int> outEdgeIds;
	vertex() : id(-1), name(), inEdgeIds(), outEdgeIds() {};
	vertex(int id, string& name) :
		name(name), id(id), inEdgeIds(), outEdgeIds() {};
};

class edge {
public:
	int id;
	int weight;
	int fromId;
	int toId;
	edge(): id(-1), weight(-1), fromId(-1), toId(-1) {};
	edge(int id, int weight, int fromId, int toId) :
		id(id), weight(weight), fromId(fromId), toId(toId) {};
};

class graph {
public:
	unordered_map<int, vertex> V;
	unordered_map<int, edge> E;
	int maxVertexId;
	int maxEdgeId;

	graph() : V(), E(), maxVertexId(0), maxEdgeId(0){};
	int AddVertex(string name) {
		vertex v(maxVertexId++, name);
		V[v.id] = v; //insert key-value pair (v.id, v)
		return v.id;
	}
	int AddEdge(int weight, int fromId, int toId) {
		edge e(maxEdgeId++, weight, fromId, toId);
		E[e.id] = e;
		vertex& from = V[fromId];
		vertex& to = V[toId];

		from.outEdgeIds.push_back(e.id);
		to.inEdgeIds.push_back(e.id);
		return e.id;
	}
	void PrintEdge(int id) {// (peter -> jane)
		edge e = E[id]; // O(1) time
		vertex from = V[e.fromId]; // O(1) time
		vertex to = V[e.toId]; // O(1) time
		cout << "(" << from.name << " -> " << to.name << ")";
	}

	void PrintVertex(int id) {
		vertex v = V[id]; // O(1) time
		cout << v.name << " (" << v.id << ")\n";
		cout << "    ";
		for (auto eId : v.inEdgeIds) {
			PrintEdge(eId);
			cout << ", ";
		}
		cout << "\n    ";
		for (auto eId : v.outEdgeIds) {
			PrintEdge(eId);
			cout << ", ";
		}
	}

	void Print() {
		for (auto vit : V) {
			PrintVertex(vit.first);
			cout << "\n";
		}
	}
};

int main() {
	graph G;

	int aliceId = G.AddVertex("Alice");
	int bobId = G.AddVertex("Bob");
	int chrisId = G.AddVertex("Chris");
	int davidId = G.AddVertex("David");

	G.AddEdge(10, aliceId, bobId);
	G.AddEdge(20, bobId, chrisId);
	G.AddEdge(30, davidId, chrisId);

	G.Print();

	system("pause");
}
