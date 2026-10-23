#include <iostream>
using namespace std;

int main() {
    int score1, score2, score3, total;
    float average;

    cout << "Enter quiz 1 score:";
    cin >> score1;
    cout << "Enter quiz 2 score:";
    cin >> score2;
    cout << "Enter quiz 3 score:";
    cin >> score3;

    total = score1 + score2 + score3;
    average = total / 3.0;

    cout << "Total score:" << total << endl;
    cout << "Average:" << average; 

    return 0;
    

}
