#include<iostream>
#include "queueAR.h"

int main(){
    //create object
    Printer officePrinter(3);
    

    std::cout << "=== Adding Print Jobs to Queue ===\n";
    officePrinter.Addjob(Job(101, "Parker ", 15));
    std::cout << "Parker submitted a printing job\n";
    officePrinter.Addjob(Job(102, "Reily", 23));
     std::cout << "Reily submitted a printing job\n";
    officePrinter.Addjob(Job(103, "Watts", 5));
     std::cout << "Watts submitted a printing job\n";

    std::cout << "\n=== Processing First 3 Jobs ===\n";
    officePrinter.PrintJob();
    officePrinter.PrintJob();
    officePrinter.PrintJob();


    std::cout << "\n=== Adding More Jobs ===\n";
    officePrinter.Addjob(Job(104, "White", 15));
    std::cout << "White submitted a printing job\n";
    officePrinter.Addjob(Job(105, "Castle", 3));
    std::cout << "Castle submitted a printing job\n";
    officePrinter.Addjob(Job(106, "Banner", 10));
    std::cout << "Banner submitted a printing job\n";
    officePrinter.Addjob(Job(107, "Doe", 20));

    officePrinter.PrintAll();

    return 0;
}