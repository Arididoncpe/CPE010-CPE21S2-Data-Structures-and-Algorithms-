#include<iostream>
#include<queue>

//display
    void display(std::queue<char> copyQ) {
    
        //loop until empty
        std::cout << "myQ: ";
        while(!copyQ.empty()) {
            //display front
            std::cout << copyQ.front() << " ";
             //dq the front
            copyQ.pop();

        }
        std::cout << std::endl;
        
    }

int main(){

    //create an object:
    std::queue<char> myQ;

    //use the enqueue
    myQ.push('G');
    myQ.push('A');
    myQ.push('B');
    
    std::cout << "Current Front is: " << myQ.front() << std::endl;
    std::cout << "Current Back is: " << myQ.back() << std::endl; 
    display(myQ);
    
    //dequeue
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);

    //empty checker
    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;
    


    return 0;

}




