#include <iostream>
#include <string.h>

class Fruit {
private:
    std::string* fruitName;
    float* fruitPrice;
    int* fruitQuantity;

public:
    //constructor
    Fruit(std::string newName = "Apple", float newPrice = 10, int newQuantity = 7 ) {
        fruitName = new std::string(newName);
        fruitPrice = new float(newPrice);
        fruitQuantity = new int(newQuantity);
        std::cout << "Constructor called\n";

    }
    //destructor
    ~Fruit() {
        delete fruitName;
        delete fruitPrice;
        delete fruitQuantity;
        std::cout << "Destructor called\n";
    }

    //copy constructor
    Fruit(const Fruit& copyFruit) {
        std::cout << "Copy Constructor called\n";
        fruitName = copyFruit.fruitName;
        fruitPrice = copyFruit.fruitPrice;
        fruitQuantity = copyFruit.fruitQuantity;
    }
    //copy assignment operator
    Fruit& operator=(const Fruit& copyFruit) {
        std::cout << "Copy Assignment Operator called\n";

            if (this != &copyFruit) {

                delete fruitName;
                delete fruitPrice;
                delete fruitQuantity;

                fruitName = new std::string(*copyFruit.fruitName);
                fruitPrice = new float(*copyFruit.fruitPrice);
                fruitQuantity = new int(*copyFruit.fruitQuantity);
            }

        return *this;
    }

    //calculate sum
    float calculateSum() {
        return (*fruitPrice) * (*fruitQuantity);
    }

    //display attributes
    void display() {
        std::cout << *fruitName << " " << "PHP" 
                  << " " << *fruitPrice << " " << "x" 
                  << *fruitQuantity << "\n";
    }
};



class Veggie {
private:
    std::string* veggieName;
    float* veggiePrice;
    int* veggieQuantity;

public:

    //constructor
    Veggie(std::string newName = "Broccoli", float newPrice = 60, int newQuantity = 12 ) {
        veggieName = new std::string(newName);
        veggiePrice = new float(newPrice);
        veggieQuantity = new int(newQuantity);
        std::cout << "Constructor called\n";

    }
    //destructor
    ~Veggie() {
        delete veggieName;
        delete veggiePrice;
        delete veggieQuantity;
        std::cout << "\nDestructor called\n";
    }

    //copy constructor
    Veggie(const Veggie& copyVeggie) {
        std::cout << "Copy Constructor called\n";
        veggieName = copyVeggie.veggieName;
        veggiePrice = copyVeggie.veggiePrice;
        veggieQuantity = copyVeggie.veggieQuantity;
    }
    //copy assignment operator
    Veggie& operator=(const Veggie& copyVeggie) {
        std::cout << "Copy Assignment Operator called\n";

            if (this != &copyVeggie) {

                delete veggieName;
                delete veggiePrice;
                delete veggieQuantity;

                veggieName = new std::string(*copyVeggie.veggieName);
                veggiePrice = new float(*copyVeggie.veggiePrice);
                veggieQuantity = new int(*copyVeggie.veggieQuantity);
            }

        return *this;
    }

//calculate sum
    float calculateSum() {
    return (*veggiePrice) * (*veggieQuantity);
    }

//display attributes
    void display() {
    std::cout << *veggieName << " " << "PHP" 
              << " " << *veggiePrice << " " << "x" 
              << *veggieQuantity << "\n";
    }

};

    //total sum function
    float TotalSum(Fruit* fruit[], int fruitSize, 
        Veggie* veggie[], int veggieSize) {
     
            float total = 0;  
       
        for (int i = 0; i < fruitSize; i++) {
            total = total + fruit[i]->calculateSum();
        }

         for (int i = 0; i < veggieSize; i++) {
            total = total + veggie[i]->calculateSum();
        }

        return total;
}
  

int main() {

//grocery list for fruit and veggie
    Fruit* fruitGroceryList[2];
    Veggie* veggieGroceryList[2];

    fruitGroceryList[0] = new Fruit("Apple",10,7);
    fruitGroceryList[1] = new Fruit("Banana",10,8);

    veggieGroceryList[0] = new Veggie("Broccoli",60,12);
    veggieGroceryList[1] = new Veggie("Lettuce",50,10);

    std::cout << "----Jenna's Grocery List----\n";

    for(int i = 0; i < 2; i++) {
        veggieGroceryList[i]->display();
    }

    for(int i = 0; i < 2; i++) {
        fruitGroceryList[i]->display();
    }
    
    std::cout << "Total: PHP " << TotalSum(fruitGroceryList,2,veggieGroceryList,2);

 // delete Lettuce
    delete veggieGroceryList[1];

// point to nullptr for best practice
    veggieGroceryList[1] = nullptr;

    return 0;
    
}
