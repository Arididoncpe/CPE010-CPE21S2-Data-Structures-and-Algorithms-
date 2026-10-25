#include<iostream>
#include "queueLL.h"


int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "Testing the enqueue operator: \n";
    enqueue('G', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    enqueue('A', &front, &back);    
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    enqueue('B', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;

    std::cout << "Testing the dequeue operator: \n";
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);

    std::cout << "Testing the qllTraverse operator: \n";
    qLLTraverse(&front);

    isEmpty(&front, &back);

    return 0;
}