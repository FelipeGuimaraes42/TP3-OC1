#include <iostream>

#include "include/cpu.h"

int main(int argc, char const *argv[]){

    if(argc> 1){
        CPU *cpu = new CPU(argv[1]);
        cpu->run();
        cpu->print();
        delete cpu;
    }else{
        std::cout << "No input file provided" << std::endl;
    }
    return 0;

}