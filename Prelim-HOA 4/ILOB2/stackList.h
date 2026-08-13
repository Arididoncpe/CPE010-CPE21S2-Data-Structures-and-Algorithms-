#ifndef STACK_LIST_H
#define STACK_LIST_H

//class node that contains data and the next
template <typename T>
class Node {
public:
    T data;        // VALUE THAT WE NEED STORE
    Node* next;    // POINTER TO THE NEXT NODE
};

//global pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;


//push
template <typename T>
void push(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

//pop
template<typename T>
T pop(){
    if(head<T> == nullptr){
        std::cout << "stack overflow." << std::endl;
    }
    //save current top node
    Node<T>* temp = head<T>;
    //store data
    T tempVal = temp->data;

    //move head to next node
    head<T> = head<T>->next;
    //free the removed node
    delete temp;
    //return the remove value
    return tempVal;
}

//isEmpty
template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

//top
template<typename T>
void Top(){
    if(isEmpty<T>()){
        std::cout<<"Stack underflow"<<std::endl;
        return;
    }
    std::cout<<"Top of Stack: "<<head<T>->data <<std::endl;
}

//displayAll
template <typename T>
void displayAll(){
    if (head<T> == nullptr){
        std::cout << "stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack: \n";
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";
}
#endif
