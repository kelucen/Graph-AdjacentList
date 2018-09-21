#include<iostream>
#include "AdjacentList.h"
#include "DepthFirstSearch.h"
using namespace std;

int main(){
  Graph<int> * g = new Graph<int>(5);
  g->insertEdge(1, 2);
  g->insertEdge(2, 3);
  g->insertEdge(3, 4);
  g->insertEdge(4, 5);
  g->insertEdge(5, 1);
  g->insertEdge(5, 2);
  g->insertEdge(2, 4);
  g->printGraph();
  cout << g->getOrder() << " " << g->getSizeGraph() << endl;
  //
  cout << endl;
  DFS<int> * h = new DFS<int>(5);
  h->dfs(g);
  h->dfsMap(g);
  cout << endl;
  h->topologicalSort(g);
  cout << endl;
  h->dfsMap(g);
  g->destroyGraph();

  delete g;
  delete h;
  return 0;
}
