#include <iostream>
#include <string.h>
#include "playlist_ll.h"

int main(){
    Playlist<std::string>* head = CreateNewSong(std::string("ITZY - Mr.Vampire"));
    Playlist<std::string>* second = CreateNewSong(std::string("ITZY - DALLA DALLA"));
    Playlist<std::string>* third = CreateNewSong(std::string("ITZY - LOCO"));
    Playlist<std::string>* fourth = CreateNewSong(std::string("ITZY - In The Morning"));
    Playlist<std::string>* fifth = CreateNewSong(std::string("ITZY - Icy"));
    
    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    //to make it circular or loop to first
    fifth->next = head;
    head->prev = fifth;
    


    //traversal
    std::cout <<"Testing Playlist Traversal: "<< std::endl;
    playlistTraverse(head);


    //insert end
    std::cout << "Testing Insert song:" << std::endl;
    playlistInsertEnd(std::string("Silent Sanctuary - Rebound"), head);
    playlistTraverse(head);
    playlistInsertEnd(std::string("Soapdish - Tensionado"), head);
    playlistTraverse(head);


    //delete node
    std::cout << "Testing Delete song:" << std::endl;
    playlistDeleteNode(std::string("ITZY - Mr.Vampire"), &head);
    playlistTraverse(head);


    // Next song
    std::cout << "Testing Next song:" << std::endl;
    head = playlistNext(head);
    std::cout << "Now Playing: " << head->data << std::endl;
   


    // Previous song
    std::cout << "Testing Previous song:" << std::endl;
    head = playlistPrev(head);
    std::cout << "Now Playing: " << head->data << std::endl;
    

}


 
