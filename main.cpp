#include <iostream>

#include "include/cpu.h"

int main(int argc, char const *argv[]){

    if(argc> 1){
        CPU *Cpu = new CPU(argv[1]);
        Cpu->run();
        Cpu->print();
        delete Cpu;
    }else{
        std::cout << "No input file provided" << std::endl;
    }
    return 0;

}