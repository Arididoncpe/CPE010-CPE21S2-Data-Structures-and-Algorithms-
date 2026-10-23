#include<iostream>
#include<cstdlib>
#include<string>
#include "sortingAlgo.h"
#include "searchingAlgo.h"
#include <ctime>

const int maxSize = 100;
const int num_candidates = 5;

void displayArr(int arr[]);

int main() {
    std::string candidates[num_candidates] = {
        "Candidate 1",
        "Candidate 2",
        "Candidate 3",
        "Candidate 4",
        "Candidate 5" };

// create an array with unsorted list
    int votes[maxSize];


// use time (0) as seed
    srand(time(0));

    for(int i = 0; i < maxSize; i++){
        votes[i] = (rand()% 5) + 1;
    }

    std::cout << "Unsorted Votes: \n";
    displayArr(votes);

    std::cout << "Sorted Votes: \n";
    insertionSort(votes, maxSize);
    displayArr(votes);

    std::cout << std::endl;

    //-----------------linear search------------- 
    std::cout << "---- Election Results ---- " << std::endl;

    int voteCount[num_candidates] = {};

    for(int i = 0; i < num_candidates; i++) {

        voteCount[i] = linearSearchCount(maxSize, i + 1, votes);   // i+1 makes it count 1-5 not 0-5
    }

    int maxVotes = -1;
    int winner = -1;
    for(int i = 0; i < num_candidates; i++) {
        std::cout << candidates[i] << ": " << voteCount[i] << " votes" <<  std::endl;
    
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winner = i;
        }
    }
    std::cout << std::endl;
    std::cout << "WINNER: " << candidates[winner] << " with " << maxVotes << " votes!\n";

    return 0;
}
    

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
        
        // Print a new line every 20 numbers so it fits on screen
        if ((i + 1) % 20 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}