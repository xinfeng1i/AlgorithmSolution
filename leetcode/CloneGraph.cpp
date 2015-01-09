#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct UndirectedGraphNode
{
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};



UndirectedGraphNode* cloneGraphUtil(UndirectedGraphNode* node, map<int, UndirectedGraphNode*>& created)
{
	if (node == NULL) return NULL;

	// clone a node already exist
	if (created.count(node->label) == 1)
	{
		return created[node->label];
	}
	else
	{
		UndirectedGraphNode* pCopyNode = new UndirectedGraphNode(node->label);
		created[node->label] = pCopyNode;
		for (size_t i = 0; i < node->neighbors.size(); ++i)
		{
			UndirectedGraphNode* p = node->neighbors[i];
			pCopyNode->neighbors.push_back(cloneGraphUtil(p, created));
		}

		return pCopyNode;
	}
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	map<int, UndirectedGraphNode*> created;
	UndirectedGraphNode* ans = cloneGraphUtil(node, created);
	return ans;
}

int main()
{
	UndirectedGraphNode* graph;
	UndirectedGraphNode* p0 = new UndirectedGraphNode(0);
	UndirectedGraphNode* p1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* p2 = new UndirectedGraphNode(2);
	p0->neighbors.push_back(p1);
	p0->neighbors.push_back(p2);
	p1->neighbors.push_back(p2);
	p2->neighbors.push_back(p2);
	graph = p0;

	UndirectedGraphNode* newGraph = cloneGraph(graph);

	UndirectedGraphNode* pnew0 = newGraph;
	UndirectedGraphNode* pnew1 = newGraph->neighbors[0];
	UndirectedGraphNode* pnew2 = newGraph->neighbors[1];
	cout << pnew0->label << endl;
	cout << " " << pnew0->neighbors[0]->label << endl;
	cout << " " << pnew0->neighbors[1]->label << endl;

	cout << pnew1->label << endl;
	cout << " " << pnew1->neighbors[0]->label << endl;
	
	cout << pnew2->label << endl;
	cout << " " << pnew2->neighbors[0]->label << endl;

	return 0;
}