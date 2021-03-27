#include "../include/cpu.h"

CPU::CPU(char const* file){
    this->input.open(file);
    this->output.open("result.txt");
}

CPU::~CPU(){
    this->input.close();
    this->output.close();
}