#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>


//array-based circ q
template<typename T>
class queueArr{
    private:
        //ptr to dynamically allocate array
        T* q_array;
        //max no of element
        size_t q_capacity;
        //current no of elements
        size_t q_size;
        //index of the front element
        int q_front;
        //index of back element
        int q_back;

    
    public:
        //constructor
        queueArr(size_t cap = 10);

        //copy constructor
        queueArr(const queueArr& other);

        //copy assignment operator
        queueArr& operator=(const queueArr&other);

        //destructor
        ~queueArr();


        //q prototype operations:
        bool Empty();
        bool Full();
        size_t Size();
        void Clear();
        T Front();
        T Back();
        void Enqueue(T value);
        T Dequeue();

};

//constructor
template <typename T>
queueArr<T>::queueArr(size_t cap) {
    q_capacity = cap;
    q_size = 0;
    q_front = 0;
    q_back = -1;

    q_array = new T[q_capacity];
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    //create new array
    q_array = new T[q_capacity];
    
    // copy the elements
    for(size_t i = 0; i < q_capacity; i++)
    {
        q_array[i] = other.q_array[i];
    }
}



//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other) {
    // prevent self assignment
    if(this == &other)
    {
        return *this;
    }


    // delete old memory
    delete[] q_array;


    // copy data
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;


    // allocate new memory
    q_array = new T[q_capacity];


    // copy elements
    for(size_t i = 0; i < q_capacity; i++)
    {
        q_array[i] = other.q_array[i];
    }


    return *this;
}

//destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
}

//Empty()
template <typename T>
bool queueArr<T>::Empty(){
   return q_size == 0;

}

//Full()
template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;

}


//find current size of array
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

//front()
template <typename T>
T queueArr<T>::Front(){
    //check if the q is empty
    if(Empty()) {
        std::cout<<"Queue is Empty\n";
        return T();
    }
    //return thefront
    return q_array[q_front];


}

//back()
template <typename T>
T queueArr<T>::Back(){
    //check if the q is empty
    if(Empty()) {
        std::cout<<"Queue is Empty\n";
        return T();
    }
    //return the back
    return q_array[q_back];


}

//clear()
template <typename T>
void queueArr<T>::Clear(){

    //reset q_size, front, back
    q_size = 0;
    q_front = 0;
    q_back = -1;
    

}

//enqueue
template <typename T>
void queueArr<T>::Enqueue(T value){
    //check if the q is full
    if(Full()) {
        std::cout<<"Queue is Full\n";
        return;
    }

    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;
    
    //store value to the back
    q_array[q_back] = value;

    // increment the q_size
    q_size++;

}


//dequeue
template <typename T>
T queueArr<T>::Dequeue(){
    //check if the q is full
    if(Empty()) {
        std::cout<<"Queue is Empty\n";
        return T();
    }

    //create a temp variable to store front
    T temp = q_array[q_front];
   
    //move  q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // decrement the q_size
    q_size--;

    //reset the indexes if the q become empty
    if (Empty()) Clear();
       
    // return the temp variable
    return temp;
}



#endif