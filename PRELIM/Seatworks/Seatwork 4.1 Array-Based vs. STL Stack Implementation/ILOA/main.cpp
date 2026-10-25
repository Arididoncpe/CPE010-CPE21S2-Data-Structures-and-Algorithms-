#include <iostream>
#include <stack>

int main() { 
    
    std::stack<int> stack1, stack2;
    std::cout << "Testing the stack STL:" << std::endl;
    
    //isEmpty
    std::cout << "is the stack empty? " << stack1.empty() << std::endl;
    
    std::cout << "=====STACK 1====" << std::endl;
    //push
    stack1.push(10);
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;

    stack1.push(9);
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;

    stack1.push(8);
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;

    stack1.push(7);
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;

    // pop
    std::cout << "Testing pop:" << std::endl;
    stack1.pop();
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;
    

    std::cout << "is the stack empty? " << stack1.empty() << std::endl;

    // stack 1 size
    std::cout << "The size of the stack is " << stack1.size() << std::endl;
    
    //emplace - adds stack to the top
    std::cout << "Testing Emplace: " << std::endl;
    stack1.emplace(67);
    std::cout << "The top of the stack is " << stack1.top() <<std::endl;


    //stack 2 creation
    std::cout << "=====STACK 2====" << std::endl;
    stack2.push(1);
    std::cout << "The top of the stack is " << stack2.top() <<std::endl;

    stack2.push(2);
    std::cout << "The top of the stack is " << stack2.top() <<std::endl;

    stack2.push(3);
    std::cout << "The top of the stack is " << stack2.top() <<std::endl;

    stack2.push(4);
    std::cout << "The top of the stack is " << stack2.top() <<std::endl;

    // stack 2 size
    std::cout << "The size of the stack is " << stack2.size() << std::endl;

    // swap
    std::cout << "Testing swap:" << std::endl;
    stack1.swap(stack2);
  

    //display stack1
    std::cout << "stack1: ";
        while (!stack1.empty()) {
            std::cout << stack1.top() << " ";
            stack1.pop();
    }

    std::cout << std::endl;

    //display stack2
    std::cout << "stack2: ";
        while (!stack2.empty()) {
            std::cout << stack2.top() << " ";
            stack2.pop();
    }



    return 0;

}
