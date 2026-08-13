#include <iostream>
#include "queueAR.h"

int main(){

    //creating an object
    queueArr<int> q(5);

    std::cout<<"Is array empty? " << q.Empty() << std::endl;
    q.Enqueue(1);
    std::cout<< "Front: " << q.Front() << std::endl;
    std::cout<< "Back: " << q.Back() << std::endl;
    std::cout<< "Size: " << q.Size() << std::endl;
   

    q.Enqueue(2);
    q.Enqueue(3);
    std::cout<< "Front: " << q.Front() << std::endl;
    std::cout<< "Back: " << q.Back() << std::endl;
    std::cout<< "Size: " << q.Size() << std::endl;



    q.Enqueue(4);
    std::cout<< "Front: " << q.Front() << std::endl;
    std::cout<< "Back: " << q.Back() << std::endl;
    std::cout<< "Size: " << q.Size() << std::endl;

    q.Enqueue(5);
    std::cout<< "Front: " << q.Front() << std::endl;
    std::cout<< "Back: " << q.Back() << std::endl;
    std::cout<< "Size: " << q.Size() << std::endl;

    q.Enqueue(6);
    
    std::cout<< "Removed: " << q.Dequeue() << std::endl;
   

    std::cout<<"Is array Full? " << q.Full() << std::endl;

    std::cout<<"---Testing clear---" << std::endl;
    q.Clear();
    std::cout<<"Is array Empty? " << q.Empty() << std::endl;




    return 0;

}
