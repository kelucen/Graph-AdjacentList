#include<iostream>
#include "AdjacentList.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
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
  cout << endl;

  DFS<int> * d = new DFS<int>(5);
  d->dfs(g);
  d->dfsMap(g);
  cout << endl;
  d->topologicalSort(g);
  cout << endl;
  d->dfsMap(g);


  cout << endl;
  BFS<int> * b = new BFS<int>(5);
  b->bfs(g,1);
  b->bfsMap(g);
  g->destroyGraph();

  delete g,d,b;
  return 0;
}
