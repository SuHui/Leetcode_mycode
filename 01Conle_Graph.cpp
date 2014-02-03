// Conle_Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <queue>

struct Node
{
	std::vector<Node *> neighbors;
};

typedef std::unordered_map<Node *,Node *>Map;
Map map;

typedef std::queue<Node *>queue;
queue q;

Node* clone(Node *graph){
	if (!graph)
	{
		return NULL;
	}
	Node *graphcopy = new Node();
	map[graph] = graphcopy;
	q.push(graph);
	
	while(!q.empty())
	{
		Node *node=q.front();
		q.pop();
		int n = node->neighbors.size();
		for (int i = 0; i < n; i++)
		{
			Node *neighbor = new Node();
			neighbor = node->neighbors[i];
			//no copy exists
			if (map.find(neighbor) == map.end())
			{
				Node *p = new Node();
				map[node]->neighbors.push_back(p);
				map[neighbor] = p;
				q.push(neighbor);
			}
			else
			{
				map[node]->neighbors.push_back(map[neighbor]);
			}
		}
	
	
	}
	return graphcopy;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *n1 = new Node();
	Node *n2 = new Node();
	Node *n3 = new Node();
	n1->neighbors.push_back(n2);
	n1->neighbors.push_back(n3);
	n2->neighbors.push_back(n3);
	Node *copy =new Node();
	copy = clone(n1);
	
	return 0;
}

