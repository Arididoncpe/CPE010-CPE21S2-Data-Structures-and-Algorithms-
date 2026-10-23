#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class SingleList{
    public:
    T data; // this contains data to be stored in the node
    SingleList<T>* next = nullptr;

};


template <typename T>
void ListTraversal(SingleList<T>* head){
    if(head == nullptr) {
        std::cout << "List is empty";
    }
    while(head != nullptr){
        //PRINT data of n
        std::cout <<head->data;

        if(head->next != nullptr){
            std::cout<<"->";
        }
        //GO TO NEXT NODE n: = next
        head = head->next;

    }
    std::cout << std::endl;
}


template <typename T>
void sllinsertHead(T newData, SingleList<T>** currentHead) {
    
    //1. allocate memory for the new node
    SingleList<T>* newNode = new SingleList<T>;

    //2. Put our data to new node
    newNode->data = newData;

    //3. set next of th new node to point to the prv head
    newNode->next = *currentHead;

    //4. reset head to point to the new node
    *currentHead = newNode;




}


template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* prevNode) {
    
    //1. Check if it is the head node (previous node is null)
    if(prevNode == nullptr){
        std::cout << "Previous value cannot be null\n";
        return;
    }
    //3. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    //4. Store data in the new node
    newNode->data = newData;

    //5. Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //6. Point previous node to the new node
    prevNode->next = newNode;
}


template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head) {
    //1. Allocate new node
    SingleList<T>* newNode = new SingleList<T>;

    //2. Dereference to the head node
    SingleList<T>* currentNode = *head;

    //3. Store data in new node
    newNode->data = newData;

    //4. Point next of new node to NULL
    newNode->next = nullptr;

    //5. Traverse the list until next of the node is null
    while(currentNode->next != nullptr) {
        currentNode =  currentNode->next;

    }

    //6. Point the next of the current node to the new node
    currentNode->next = newNode;

}
    
   /*
   1) Find previous node of the node to be deleted.
    2) Change the next of previous node.
    3) Free memory for the node to be deleted*/ 
template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head){
    
    //if nothing to delete?
    if(*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    // searching the node: 1. node doesnt exist + we found data
    while(currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }
   
    //if data not found currNode == nullptr in the while loop:
    if(currNode == nullptr) {
        std::cout << "data is not found \n";
        return;
    }
    // if data was found:
    if(prevNode == nullptr) {
       *head = currNode->next;
    }  
    else { 
        prevNode->next = currNode->next;


    }
    delete currNode;

}

template <typename T>
void sllDeleteList(SingleList<T> **head) {
    SingleList<T>* current = *head;

    while(current != nullptr){
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}


#endif