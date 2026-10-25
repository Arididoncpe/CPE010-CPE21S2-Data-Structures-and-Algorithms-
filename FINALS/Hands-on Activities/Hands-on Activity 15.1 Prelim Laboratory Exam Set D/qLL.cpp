#include<iostream>
#include "queueLL.h"


int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "Testing the enqueue operator: \n";
    enqueue('1', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    enqueue('2', &front, &back);    
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    enqueue('3', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;
    enqueue('1', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " <<back->data << std::endl;

    symmetric(&front, &back);
   



    return 0;
}