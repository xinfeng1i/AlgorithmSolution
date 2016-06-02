#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

bool DFS(string src, int m, vector<string>& path, vector<vector<string>>& tot_path,
    unordered_map<string, multiset<string>>& adj,
	map<pair<string, string>, int>& visited,
	unordered_map<string, int>& outdeg) {
    //cout << "src = "<< src << "\t m = " << m << endl;
    // base case: current node is sink node
    if (m == 0) {
    	path.push_back(src);
        tot_path.push_back(path);
        path.pop_back();
        return true;
    }
   
    multiset<string> nbrs = adj[src];
    for (auto v : nbrs) { // for each nbr, if the edge src---> nbr is not visited, visit it
    	if (visited[make_pair(src, v)] > 0) {
    		if (m-1 != 0 && outdeg[v] == 0) {
    			continue;
			} else {
                visited[make_pair(src, v)]--;
    		    outdeg[src]--;
			    m--;
			    path.push_back(src); // try a choice
                bool ok = DFS(v, m, path, tot_path, adj, visited, outdeg);
                if (ok) return true;
                visited[make_pair(src, v)]++; // back tracking
    		    outdeg[src]++;
			    m++;
			    path.pop_back();
            }
    	}
       
    }
    return false;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    int m = (int) tickets.size(); // the number of edge
    unordered_map<string, multiset<string>> adj; // adj list
    map<pair<string, string>, int> visited; // mark if the edge is visited or not
	unordered_map<string, int> outdeg;
    for (size_t i = 0; i < tickets.size(); ++i) {
        adj[tickets[i].first].insert(tickets[i].second);
        pair<string, string> temp = tickets[i];
        visited[temp]++;
        outdeg[tickets[i].first]++;
    }
    
    vector<string> path;
    vector<vector<string>> tot_path;
    DFS("JFK", m, path, tot_path, adj, visited, outdeg);
    sort(tot_path.begin(), tot_path.end());
    
	vector<string> ans;
	if (tot_path.size() != 0) {
		ans = tot_path[0];
	}

	return ans;
}

void Test1()
{
	vector<pair<string, string>> v;
	v.push_back(make_pair("MUC", "LHR"));
	v.push_back(make_pair("JFK", "MUC"));
	v.push_back(make_pair("SFO", "SJC"));
	v.push_back(make_pair("LHR", "SFO"));
	vector<string> ans = findItinerary(v);
	for (auto s : ans) cout << " " << s;
	cout << endl;
}

void Test2() {
    vector<pair<string, string>> v;
	v.push_back(make_pair("JFK", "SFO"));
	v.push_back(make_pair("JFK", "ATL"));
	v.push_back(make_pair("SFO", "ATL"));
	v.push_back(make_pair("ATL", "JFK"));
	v.push_back(make_pair("ATL", "SFO"));
	vector<string> ans = findItinerary(v);
	for (auto s : ans) cout << " " << s;
	cout << endl;
}

// [["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],
// ["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
void Test3()
{
    vector<pair<string, string>> v;
	v.push_back(make_pair("EZE", "AXA"));
	v.push_back(make_pair("TIA", "ANU"));
	v.push_back(make_pair("ANU", "JFK"));
	v.push_back(make_pair("JFK", "ANU"));
	v.push_back(make_pair("ANU", "EZE"));
	
	v.push_back(make_pair("TIA", "ANU"));
	v.push_back(make_pair("AXA", "TIA"));
	v.push_back(make_pair("TIA", "JFK"));
	v.push_back(make_pair("ANU", "TIA"));
	v.push_back(make_pair("JFK", "TIA"));
	
	
	vector<string> ans = findItinerary(v);
	cout << "answer : " << endl;
	for (auto s : ans) cout << " " << s;
	cout << endl;
	
}


int main()
{
	//Test1();
	Test3();
	return 0;
}
