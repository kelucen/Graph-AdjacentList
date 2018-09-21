#ifndef AdjacentList_h
#define AdjacentList_h
#include <iostream>
using namespace std;

template <typename Type>
class Node{
public:
  Type item;
  Node<Type> * next;

  Node(){
    next = NULL;
  }
  Node(Type item){
    this->item = item;
    next = NULL;
  }

  Node<Type> * getNext(){
    return next;
  }
  void setNext(Node<Type> * next){
    this->next = next;
  }
  Type getItem(){
    return item;
  }
  void setItem(Type item){
    this->item = item;
  }

};

template<typename Type>
class LinkedList{
private:
  Node<Type> * first,*  last;
  int sizeList;
public:
  LinkedList();

  Node<Type> * getFirst(){
    return first;
  }
  void setPrim(Node<Type> * first){
    this->first = first;
  }
  Node<Type> * getLast(){
    return last;
  }
  void setLast(Node<Type> * last){
    this->last = last;
  }
  int getSizeList(){
    return sizeList;
  }
  void setSizeList(int sizeList){
    this->sizeList = sizeList;
  }

  void insert(Type);
  Node<Type>* previous(Node<Type>*);
  bool empty();
  Node<Type>* search(Type);
  void remove(Node<Type>*);
  void destroy();
  void print();
};

template <typename Type>
LinkedList<Type>::LinkedList() {
    first = new Node<Type>();
    first->next = NULL;
    last = first;
    sizeList = 0;
}


template <typename Type>
void LinkedList<Type>::insert(Type x){
  last->next = new Node<Type>();
  last = last->next;
  last->next = NULL;
  last->item = x;
  sizeList++;
}

template<typename Type>
Node<Type> * LinkedList<Type>::previous(Node<Type> * r){
    Node<Type>* p = first;
    while (p->next != r) p = p->next;
    return p;
}

template<typename Type>
bool LinkedList<Type>::empty(){
  return first == last;
}

template<typename Type>
Node<Type> * LinkedList<Type>::search(Type x){
  Node<Type> * p = first->next;
  while(p != NULL && p->item != x) p = p->next;

  return p;
}

template<typename Type>
void LinkedList<Type>::remove(Node<Type> * r){
  if(empty() || r == NULL || r == first)  cout << "Impossível Remover" << endl;
  else{
    Node<Type> * p = previous(r);
    p->next = r->next;
    if(p->next == NULL) last = p;
    delete r;
  }
}

template<typename Type>
void LinkedList<Type>::print(){
  Node<Type> * p = first->next;
  while(p!=NULL){
    cout << " -> ["<< p->item << "]";
    p = p->next;
  }
  cout << endl;
}



template <typename Type>
void LinkedList<Type>::destroy(){
  Node<Type> * aux;
  aux = first;
  while(aux != NULL){
    delete aux;
    aux = aux->getNext();
  }
}

template<typename Type>
class Vertex{
private:
  LinkedList<int> * indexAdjVertex;
  Type itemVertex;
  int index;
public:
  Vertex();  
  int getIndex(){
    return index;
  }
  void setIndex(int index){
    this->index = index;
  }
  LinkedList<int> * getIndexAdjVertex(){
    return indexAdjVertex;
  }
  void setIndexAdjVertex(LinkedList<Type> * indexAdjVertex){
    this->indexAdjVertex = indexAdjVertex;
  }
  Type getItemVertex(){
    return itemVertex;
  }
  void setItemVertex(Type itemVertex){
    this->itemVertex = itemVertex;
  }
};

template<typename Type>
Vertex<Type>::Vertex(){
  indexAdjVertex = new LinkedList<int>();
}



template <typename Type>
class Graph{
private:
  Vertex<Type> * vertex;
  int order,sizeGraph;

  void destroy();
public:
  Graph();
  Graph(int);
  void insertEdge(int, int);
  void initialize(int);
  void printGraph();
  void destroyGraph();

  Vertex<Type> * getVertex(){
    return vertex;
  }
  void setVertex(Vertex<Type> * vertex){
    this->vertex = vertex;
  }
  int getOrder(){
    return order;
  }
  void setOrder(int order){
    this->order = order;
  }
  int getSizeGraph(){
    return sizeGraph;
  }
  void setSizeGraph(int sizeGraph){
    this->sizeGraph = sizeGraph;
  }
};
template<typename Type>
Graph<Type>::Graph(){
  int order = 0;
  sizeGraph = 0;
  initialize(order);
}
template <typename Type>
Graph<Type>::Graph(int order){
  this->order = 0;
  sizeGraph = 0;
  initialize(order);
}

template <typename Type>
void Graph<Type>::initialize(int order){
  if(this->order != 0)  destroyGraph();
  this->order = order;
  vertex = new Vertex<Type>[order+1];
}

template <typename Type>
void Graph<Type>::insertEdge(int u, int v){
  vertex[u].setIndex(u);
  vertex[v].setIndex(v);
  vertex[u].getIndexAdjVertex()->insert(v);
  vertex[v].getIndexAdjVertex()->insert(u);
  sizeGraph++;
}

template <typename Type>
void Graph<Type>::printGraph(){
  cout << "<<Adjacent List>>" << endl;
  for(int i = 1; i<= getOrder(); i++){
    cout << "Vertex[" << i << "]" ;
    vertex[i].getIndexAdjVertex()->print();
  }
}

template <typename Type>
void Graph<Type>::destroyGraph(){
  for(int i = 0 ; i <= getOrder(); i++){
    vertex[i].getIndexAdjVertex()->destroy();
  }
  delete [] vertex;
  order = 0;
  sizeGraph = 0;
}

#endif
