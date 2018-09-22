#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h
#include "AdjacentList.h"
#include <iostream>
using namespace std;
template<typename Type>
class DynamicQueue{
private:
  Node<Type> *front, *back;
public:
  DynamicQueue();

  Node<Type> * getFront(){
    return front;
  }
  void setFront(Node<Type> * front){
    this->frete = front;
  }
  Node<Type> * getBack(){
    return back;
  }
  void setBack(Node<Type> * back){
    this->back = back;
  }
  bool emptyQueue();
  void enqueue(Type);
  void dequeue();
  void showQueue();
};

template<typename Type>
bool DynamicQueue<Type>::emptyQueue(){
  return front == back;
}
template<typename Type>
DynamicQueue<Type>::DynamicQueue(){
  front = new Node<Type>();
  front->next = NULL;
  back = front;
}

template<typename Type>
void DynamicQueue <Type>::enqueue(Type x){
  back->next = new Node<Type>();
  back = back->next;
  back->item = x;
  back->next = NULL;
}

template<typename Type>
void DynamicQueue <Type>::dequeue(){
  Node<Type> * aux  = front;
  Type x;
  if(front!=back){
    front = front->next;
    x = front->item;
    delete aux;
  }else cout << "Fila Vazia" << endl;
}

template<typename Type>
void DynamicQueue <Type>::showQueue(){
  Node<Type> * i  =  front->next;
  while(i!=NULL){
    cout << i->item << endl;
    i = i->next;
  }
}

template<typename Type>
class BFS{
private:
  Graph<Type> * g;
  int * prevVertexArray;
  string * colorArray;
  int  distanceToSource;

public:
  BFS(int);
  void bfs(Graph<Type> *,int);
  void bfsMap(Graph<Type> *);

  Graph<Type> * getG(){
    return g;
  }
  void setG(Graph<Type> * g){
    this->g = g;
  }
  int * getPrevVertexArray(){
    return prevVertexArray;
  }
  void setPrevVertexArray(int * prevVertexArray){
    this->prevVertexArray = prevVertexArray;
  }
  string * getColorArray(){
    return colorArray;
  }
  void setColorArray(string * colorArray){
    this->colorArray = colorArray;
  }
  int getDistanceToSource(){
    return distanceToSource;
  }
  void setDistanceToSource(int distanceToSource){
    this->distanceToSource = distanceToSource;
  }
};

template<typename Type>
BFS<Type>::BFS(int order){
  g = new Graph<Type>(order);
  prevVertexArray = new int[g->getOrder()+1];
  colorArray = new string[g->getOrder()+1];
  distanceToSource = 0;
}

template<typename Type>
void BFS<Type>::bfs(Graph<Type> * g, int s){
  DynamicQueue<int> * q = new DynamicQueue<int>();
  for(int i = 1; i <= g->getOrder(); i++) colorArray[i] = "White";
  colorArray[s] = "Grey";
  distanceToSource = 0;
  q->enqueue(s);
  int u ;
  while(!q->emptyQueue()){
    u = q->getFront()->getNext()->getItem();
    Node<int> * i= g->getVertex()[u].getIndexAdjVertex()->getFirst()->getNext();
    q->dequeue();
    while(i != NULL){
      int aux = i->getItem();
      if(colorArray[aux] == "White"){
        colorArray[aux] = "Grey";
        distanceToSource++;
        prevVertexArray[aux] = u;
        q->enqueue(aux);
      }
      i = i->getNext();
    }
    colorArray[u] = "Black";
  }
}

template<typename Type>
void BFS<Type>::bfsMap(Graph<Type> * g){
  cout << "<<Breadth First Search(BFS) >>" << endl;
  cout << "Previous = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << prevVertexArray[i] << " ";
  cout << "]"<<endl;
  cout << "Colors = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << colorArray[i] << " ";
  cout << "]"<<endl;
  cout << "Distance to Source = [ "<< distanceToSource << " ]" << endl;

}
#endif
