#include <iostream>

struct N {
  N* n;
  int v;
};

N* h = nullptr;

void foo(int x) {
  N* n = new N{h, x};
  h = n;
}

// print the values of v in the list, starting at node n.
void print_list(N* n) {
  // please enter your implementation here
  while(n!=nullptr)
  {
    std::cout<<"List element: "<< n->v <<std::endl;
    n = n->n;
    
  }
}

// print the values of v in the list, starting at node n, in reverse
void print_list_reverse(N* n) {
  // please enter your implementation here
  //Base case:
  if(n==nullptr)
  {
    return;
  }
  //Recursion:
  print_list_reverse(n->n);//nullptr->next
  std::cout<<"List element: "<< n->v <<std::endl;
}

// Let’s write a new class to use in place of our obfuscated code. We’ll implement a subset of the std::list interface: 
// void push_front(int) -- add a value to the front of the list
// int back() -- return the value at the end of the list without changing the list
// void pop_back() -- remove the value at the end of the list and return nothing

template typename <T>
class SinglyLinkedList{
  
  private:
  T m_data;
  SinglyLinkedList<T>* m_next;
  SinglyLinkedList<T>* head;
  SinglyLinkedList<T>* tail;
  
  public:
  SinglyLinkedList(T data):m_data(data),m_next(nullptr){};
  void push_front(T num){
  
    if(head != nullptr)
    {
      SinglyLinkedList<T> node = new SinglyLinkedList<T>(num);
      node->m_next = head;
      head = node;
    }
    
    else
    {
      head = new SinglyLinkedList<T>(num);
      tail = head;
    }
      
  }
  
  T back(){
  
  //quicken my traversal
  // we need to access the last 
  //next ptr is null , 
  // 1:1 --> 2-->3
  // 2:2
  // 3:3
  if(tail!=nullptr)
    return tail->m_data;
  else
    return new T();
  
  }
  
  void pop_back(){
  
    // 2nd last will contain tail's address
    // make 2nd last tail
    //remove last node
    SinglyLinkedList<T>* temp = head;
    while(temp->
  
  
  }
  
  
}

int main(void) {
  foo(3);// n = m1 h=m1 {nullptr,3}
  foo(2);// h = m2  {m1,2}
  foo(1);// h= m3   {m2,1}//
  print_list(h);
  print_list_reverse(h);
  return 0;
}

//1-->2-->3
//m1 m2  m3
//