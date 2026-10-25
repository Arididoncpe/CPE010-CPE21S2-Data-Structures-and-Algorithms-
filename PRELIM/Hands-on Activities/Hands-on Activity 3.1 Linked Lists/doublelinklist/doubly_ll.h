#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;


};

template <typename T>
DoubleList<T>* CreateNewNode(T newData){
    DoubleList<T> *CreateNewNode = new DoubleList<T>();

    CreateNewNode->data = newData;
    CreateNewNode->next = nullptr;
    CreateNewNode->prev = nullptr;

    return CreateNewNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode) {
    DoubleList<T> *tail = nullptr;

    if (currentNode == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout<<"Forward: \n";
    //move forward
    while(currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;

}
    //add a next line
        std::cout << "\n";


    std::cout<<"Backward: \n";
    //move backward
    while(tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;


    }
    std::cout << "\n\n";
}

//insert at the head
template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = CreateNewNode(newData);


    newNode->next = *currentHead;

    //current head should point back to the newNode
    (*currentHead)->prev = newNode;

    //update the ptr head
    *currentHead = newNode;


}

template<typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead) {
    DoubleList<T>* newNode = CreateNewNode(newData);

    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }


    currentHead->next = newNode;


    newNode->prev = currentHead;

}

// general insert
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode) {
    
    // Check if it is the head node (previous node is null)
    if(prevNode == nullptr){
        std::cout << "Previous value cannot be null\n";
        return;
    }
    // Allocate a new node
    DoubleList<T>* newNode = new DoubleList<T>;

    // Store data in the new node
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Link new node's next to previous node's next
    newNode->next = prevNode->next;

    // Link previous node's next to new node
    prevNode->next = newNode;

    // Link new node's prev to previous node
    newNode->prev = prevNode;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }

}

// delete node
template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** currentHead){
    
    //if nothing to delete?
    if (*currentHead == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    // Start searching from the head
    DoubleList<T>* currNode = *currentHead;


    // searching the node: 1. node doesnt exist + we found data
    while(currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }
   
    //if data not found currNode == nullptr in the while loop:
    if(currNode == nullptr) {
        std::cout << "data is not found \n";
        return;
    }
   // connect previous node
    if(currNode->prev != nullptr)
    {
        currNode->prev->next = currNode->next;
    }
    else
    {
    // deleting head
        *currentHead = currNode->next;
    }


    // connect next node
    if(currNode->next != nullptr)
    {
        currNode->next->prev = currNode->prev;
    }


    delete currNode;
}


#endif