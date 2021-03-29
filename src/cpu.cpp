#include "../include/cpu.h"

CPU::CPU(char const* file){
    this->input.open(file);
    this->output.open("./output/result.txt");
    this->cache = new Cache();
}

CPU::~CPU(){
    this->input.close();
    this->output.close();
    delete this->cache;
}

std::string CPU::intToBinary(int intAdress){
    std::string binaryAddress = std::bitset<32>(intAdress).to_string();
   return binaryAddress;
}

int CPU::binaryToInt(std::string strAdress){
   return std::stoi(strAdress, nullptr, 2);
}

void CPU::run(){

    while(!(this->input.eof())){
        std::stringstream sStream("");
        int address;
        bool write;
        input >> address >> write;

        if(write){
            this->numWrites++;
            std::string line;
            input >> line;
            this->cache->write(address, line);
            sStream << address << ' ' << 1 << ' ' << line << " W" << std::endl;

        }else{
            this->numReads++;
            bool hit = this->cache->find(address);
            sStream << address << ' ' << 0 << ' ' << (hit ? " HIT" : " MISS") << std::endl;
            hit ? this->numHits++ : numMisses++;
        }
        this->history.push_back(sStream.str());
    }

}

void CPU::print(){
    
   double hitRate = (double) this->numHits / (double) (this->numMisses + this->numHits);
   double missRate = (double) this->numMisses / (double) (this->numMisses + this->numHits);

   this->output << "READS: " << this->numReads << std::endl;
   this->output << "WRITES: " << this->numWrites << std::endl;
   this->output << "HITS: " << this->numHits << std::endl;
   this->output << "MISSES: " << this->numMisses << std::endl;
   this->output << "HIT RATE: " << hitRate << std::endl;
   this->output << "MISS RATE: " << missRate << std::endl << std::endl;

    for(std::vector<std::string>::iterator it = history.begin(); it!= history.end(); it++)
        this->output << *it;

}