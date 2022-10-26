//FOLLOWING IS A CODE FOR DIJKSTRA'S ALGORITHM IN C++
#include <climits>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {

  // create adj list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges; i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  vector<int> dist(vertices);
  for (int i = 0; i < vertices; i++) {
    dist[i] = INT_MAX;
  }
  set<pair<int, int>> s;

  dist[source] = 0;
  s.insert(make_pair(0, source));

  while (!s.empty()) {
    // fetch top record
    auto top = *(s.begin());

    int nodeDist = top.first;
    int topNode = top.second;

    // remove top record
    s.erase(s.begin());

    // traverse on neighbours
    for (auto neighbour : adj[topNode]) {
      if (nodeDist + neighbour.second < dist[neighbour.first]) {
        auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));
        // if record found,then erase it
        if (record != s.end()) {
          s.erase(record);
        }
        // distance update
        dist[neighbour.first] = nodeDist + neighbour.second;
        // record push in set
        s.insert(make_pair(dist[neighbour.first], neighbour.first));
      }
    }
  }
  return dist;
}

int main() {

  vector<vector<int>> edges = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3},
                               {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};
  vector<int> ans = dijkstra(edges, 5, 7, 0);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
