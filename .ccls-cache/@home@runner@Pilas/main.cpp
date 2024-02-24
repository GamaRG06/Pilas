#include <iostream>
using namespace std;
class Vertex{
public:
  int value;
  Vertex* next;
  Vertex(){next = nullptr;} 

};
class Stack{
public:
  Stack();
  void pop();
  void push(int value);
  void peek();
  void print();
private:
  Vertex* head,*tail;  
};

Stack::Stack(){
  head = nullptr;
  tail = nullptr;
}
void Stack::push(int value){
  Vertex* vtx = new Vertex();
  vtx->value = value;
  if(head != nullptr){
    vtx->next=head;
    head = vtx;
  }else{  
    tail = vtx;
    head = vtx;
  }
};

void Stack::print(){
  Vertex* v = head;
  cout<<"Los valores de la pila son:"<<endl;
  cout<<"___"<<endl;
  while(v != nullptr){
    cout<<"|"<<v->value<<"|\n";
    v = v->next; 
  }
  cout<<"---"<<endl;
}

void Stack::pop(){
  if(head != nullptr){
    Vertex* vtx = head;
    head = head->next;
    delete vtx;
  }
}

void Stack::peek(){
  if(head != nullptr){
    Vertex* v = head;
    v = v->next;
    cout<<"La siguiente es: "<<v->value<<endl;
  }
  cout<<endl;
}

int main() {
  Stack lista;
  lista.push(5);
  lista.push(6);
  lista.push(7);
  lista.push(8);
  lista.push(9);
  lista.print();
  lista.pop();
  lista.print();
  lista.peek();
  lista.push(12);
  lista.print();
  lista.peek();
  lista.pop();
  lista.print();
}