/*
 * graph.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<bool> v){
	vector<bool>::iterator it;
	cout<<"Printing vector...";
	for(it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout<<endl;
}

class Graph{
	int m_v;
	list<int> *m_adj;

public:
	Graph(int v): m_v(v){
		m_adj = new list<int>[v];
	}
	~Graph(){
		delete[] m_adj;
	}
	void addEdge(int src, int dest){
		m_adj[src].push_back(dest);
	}
	void doDFS(int v, vector<bool> &visited){
		visited[v] = true;
		list<int>::iterator i;
		for(i = m_adj[v].begin(); i != m_adj[v].end(); i++){
			if(!visited[*i])
				doDFS(*i, visited);
		}

	}
	Graph getTranspose(){
		Graph gt(m_v);
		for(int v = 0; v < m_v; v++){
			list<int>::iterator it;
			for(it = m_adj[v].begin(); it != m_adj[v].end(); it++){
				gt.m_adj[*it].push_back(v);
			}
		}
		return gt;
	}
	bool isSC(){
		vector<bool> isVisited(m_v, false);
		doDFS(0, isVisited);
		printVector(isVisited);
		vector<bool>::iterator it = find(isVisited.begin(), isVisited.end(), false);
		if(it != isVisited.end()) // false exists
			return false;
		// get transpose and traverse again
		Graph gt = getTranspose();
		vector<bool> visited(m_v, false);
		gt.doDFS(0, visited);
		printVector(visited);
		it = find(visited.begin(), visited.end(), false);
		if(it != visited.end()) // false exists
			return false;
		return true;
	}
	void printNoOfVertices();
	void printAdjacency(int v);
	void findRouteBwNodes(int a, int b);
	void printDFSPath(int v, int u, vector<bool> &path);
};

int main(){
	/*Graph g(5);
	g.printNoOfVertices();
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	g.addEdge(3,4);
	g.printAdjacency(2);
	g.isSC() ? cout<<"The graph is strongly connected"<<endl:
			cout<<"The graph is not strongly connected"<<endl;

	g.findRouteBwNodes(0, 3);*/

	Graph g(5);
	g.printNoOfVertices();
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	g.addEdge(3,4);
}

void Graph::printDFSPath(int v, int u, vector<bool> &path){
	path[v] = true;
	if(v == u){
		cout<<v;
		return;
	} else
		cout<<v <<"->";
	list<int>::iterator i;
	for(i = m_adj[v].begin(); i != m_adj[v].end(); i++){
		if(!path[*i])
			printDFSPath(*i, u, path);
	}
	cout<<endl;
}
void Graph::findRouteBwNodes(int v, int u){
	// check if source exists
	if(v < m_v && u < m_v){
		vector<bool> visit(m_v, false);
		doDFS(v, visit);
		if(visit[u]){
			vector<bool> path(m_v, false);
			printDFSPath(v, u, path);
		} else
			cout<<"Route doesn't exist!"<<endl;

	} else
		cout <<"Source not found!"<<endl;
}
void Graph::printNoOfVertices(){
	cout << "Number of vertices :" << m_v << endl;
}
void Graph::printAdjacency(int v){
	list<int>::iterator i;
	cout << "Printing adjacency list of " << v << ": ";
	for(i = m_adj[v].begin(); i != m_adj[v].end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}
