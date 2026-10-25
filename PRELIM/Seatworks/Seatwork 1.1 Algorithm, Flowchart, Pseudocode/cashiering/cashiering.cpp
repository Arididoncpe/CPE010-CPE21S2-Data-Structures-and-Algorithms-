#include <iostream>
using namespace std;

int main() {
    string item1, item2, item3;
    float price1, price2, price3, total, change, payment; 

    cout << "Enter item 1:" << endl;
    cin >> item1;
    cout << "Enter item 1 price:" << endl;
    cin >> price1;

    cout << "Enter item 2:" << endl;
    cin >> item2;
    cout << "Enter item 1 price:" << endl;
    cin >> price2;

     cout << "Enter item 3:" << endl;
    cin >> item3;
    cout << "Enter item 3 price:" << endl;
    cin >> price3;

    total = price1 + price2 + price3;
    cout << "Total price is:" << total << endl;
    
    cout << "Enter your payment:" << endl;
    cin >> payment;


    if (payment < total) {
    cout << "Insufficient payment"; 
    
    } else {
    change = payment - total;
    cout << "Change:" << change << endl;

    }

    cout << "==========Transaction Receipt==========" << endl;
    cout << "Item 1:" << " " << item1 << "   " << "Price:" << price1 << endl;
    cout << "Item 2:" << " " << item2 << "   " << "Price:" << price2 << endl;
    cout << "Item 3:" << " " << item3 << "   " << "Price:" << price3 << endl;
    cout << "Total:" << total << endl;
    cout << "Payment:" << payment << endl;
    cout << "Change:" << change << endl;
    cout << "Thanks for your transaction!";
    

    return 0;
}