#include <iostream>

//global declarations
#define maxCap 10

int stackArr[maxCap];
int topIndex = -1;
int newData;

//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull(); 
void displayStack();


int main() {
// maindriver
    int choice;

    while(true)
    {
        std::cout << "==============================================" <<std::endl;
        std::cout << "Stack Operation:" << std::endl;
        std::cout <<"1. PUSH 2.  POP  3. TOP  4.isEmpty  5. isFull  6. Display" << std::endl;
        std::cout << "==============================================" <<std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch(choice){
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: Top();
            break;

            case 4: std::cout << "Is stack empty? " << isEmpty() << std::endl; 
            break;

            case 5: std::cout << "Is stack full? " << isFull() << std::endl;
            break;

            case 6: displayStack();
            break;

            default: std::cout << "Invalid Choice" << std::endl;
            break;
        }

    }
   
}

//function definition
bool isEmpty() {
    if(topIndex == -1) return true;
    return false;
}

bool isFull() {
    if(topIndex == maxCap -1) return true;
    return false;
}

    //error checking
void push() {
    if(isFull()){
        std::cout << "Stack overflow" << std::endl;
        return;
    }

    //pushing to the stack
    std::cout << "Enter a new value: ";
    std::cin >> newData;
    stackArr[++topIndex] = newData;
}

void pop() {
    if(isEmpty()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }
    //display the value we are going to pop
    std::cout << "Popping: " << stackArr[topIndex] << std::endl;
    //decrement the top value from the stack
    topIndex--;
    
}
void Top() {
    if(isEmpty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    }
    //check the top value:
    std::cout << "Top element: " << stackArr[topIndex] << std::endl;

}

void displayStack() {
    if(isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    std::cout << "Stack Elements:" << std::endl;
     for (int i = topIndex; i >= 0; i--) {
        std::cout << stackArr[i] << " ";
     }
     std::cout << std::endl;
       
}



