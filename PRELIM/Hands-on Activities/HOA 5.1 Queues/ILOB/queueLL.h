#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H


// create a class node
template<typename T>
class qNode{
    public:
        T data;
        qNode* next;
};

// new nodecreator
template <typename T>
qNode<T>* new_node(T newData) {
    //allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;

    //store newdata tp the newnode
    newNode -> data = newData;

    //point newNode next to null
    newNode -> next = nullptr;

    return newNode;

}

// enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    //create new node
    qNode<T>* newNode = new_node(newData);

    //check if q is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    

    //if not, insert at the back
    (*backPtr) -> next = newNode;
    (*backPtr) = newNode;
}





//dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    // check if the q is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty"<<std::endl;
        return;
    }


    //create a temp variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;


    //assign the current front to deleteTemp
    deleteTemp = (*frontPtr);


    //check if the q has only 1 item
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        //means only 1 item is inside the q
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return; 

    }
    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;
    // delete node
    delete deleteTemp;

}

//display all
template<typename T>
void qLLTraverse(qNode<T>** front) {
    if((*front) == nullptr) {
        std::cout << "Queue is empty" <<std::endl;
        return;
    }

    while((*front) !=nullptr){
        std::cout << (*front)->data;
        (*front) = (*front)->next;

    }
    std::cout << std::endl;
}



//isEmpty
template<typename T>
bool isEmpty(qNode<T> **front, qNode<T> **back) {
    if((*front) == nullptr && (*back) == nullptr) 
        return true;

        return false;
    

}



#endif