#include "../include/cpu.h"

CPU::CPU(char const* file){
    this->input.open(file);
    this->output.open("./output/result.txt");
}

CPU::~CPU(){
    this->input.close();
    this->output.close();
}

void CPU::run(){

    while(!(this->input.eof())){
        std::stringstream sStream;
        int add;
        bool wrt;
        input >> add >> wrt;

        if(wrt){
            this->numWrites++;
            std::string line;
            input >> line;
            //TODO
        }else{
            this->numReads++;
            //TODO
            bool hit;
            hit ? this->numHits++ : numMisses++;
        }
        this->history.push_back(sStream.str());
    }
    
}

void CPU::print(){
    
   double hitRate = (double) this->numHits / (double) this->numMisses + this->numHits;
   double missRate = (double) this->numMisses / (double) this->numMisses + this->numHits;

   this->output << "READS: " << this->numReads << std::endl;
   this->output << "WRITES: " << this->numWrites << std::endl;
   this->output << "HITS: " << this->numHits << std::endl;
   this->output << "MISSES: " << this->numMisses << std::endl;
   this->output << "HIT RATE: " << hitRate << std::endl;
   this->output << "MISS RATE: " << missRate << std::endl;

    for(std::vector<std::string>::iterator it = history.begin(); it!= history.end(); it++)
        this->output << *it;

}