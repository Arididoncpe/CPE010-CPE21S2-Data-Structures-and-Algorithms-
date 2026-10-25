#include <iostream>
#include "stacklist(modified).h"

int main(){

    std::string expression;

    std::cout << "Enter expression: ";
    getline(std::cin, expression);

    if(balanced<char>(expression))
        std::cout << "Expression is Balanced.\n";
    else
        std::cout << "Expression is NOT Balanced.\n";

    return 0;
}

