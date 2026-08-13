#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>

template <typename T>
class Playlist{
public:

    T data;

    Playlist<T>* prev = nullptr;
    Playlist<T>* next = nullptr;

};



// Create new song node
template <typename T>
Playlist<T>* CreateNewSong(T newData){

    Playlist<T>* newNode = new Playlist<T>();

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}



// Traverse playlist
template <typename T>
void playlistTraverse(Playlist<T>* head){

    if(head == nullptr){
        std::cout << "Playlist is empty.\n";
        return;
    }


    Playlist<T>* current = head;
    int songNumber = 1;
    std::cout << "=====PLAYLIST=====\n";

    do{
        std::cout <<"["<< songNumber << "]"<< " " << current->data << std::endl;
        current = current->next;
        songNumber++;

    }while(current != head);

    std::cout << "\nPlaylist finished. Looping back to the first song...\n\n";
    std::cout << "[1]" << " " << head->data << std::endl;


}

// Insert song at end
template <typename T>
void playlistInsertEnd(T newData, Playlist<T>* currentHead){

    Playlist<T>* newNode = CreateNewSong(newData);

    Playlist<T>* tail = currentHead->prev;


    newNode->next = currentHead;
    newNode->prev = tail;

    tail->next = newNode;
    currentHead->prev = newNode;

}


// Delete song
template <typename T>
void playlistDeleteNode(T findData, Playlist<T>** currentHead){


    if(*currentHead == nullptr){

        std::cout << "Playlist is empty.\n";
        return;

    }

    Playlist<T>* currNode = *currentHead;

    do{

        if(currNode->data == findData){


            // Only one song
            if(currNode->next == currNode){
                delete currNode;
                *currentHead = nullptr;

                return;

            }

            // Connect previous node to next node
            currNode->prev->next = currNode->next;

            // Connect next node back to previous node
            currNode->next->prev = currNode->prev;

            // If deleting head
            if(currNode == *currentHead){

                *currentHead = currNode->next;

            }

            delete currNode;

            return;

        }


        currNode = currNode->next;



    }while(currNode != *currentHead);


    std::cout << "Song not found.\n";


}

// Next song
template <typename T>
Playlist<T>* playlistNext(Playlist<T>* current){

    return current->next;
}

// Previous song
template <typename T>
Playlist<T>* playlistPrev(Playlist<T>* current){

    return current->prev;
}

#endif