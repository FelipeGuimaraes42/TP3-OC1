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
   std::stringstream sStream;
   std::string binaryAddress;
   int size = 32;
   while (intAdress > 0){
       char bit = char(intAdress % 2) + '0';
       sStream << bit;
       intAdress = std::floor(intAdress / 2);
       size--;
   }
   while(size > 0){
       sStream << '0';
       size--;
   }
   binaryAddress = sStream.str();
   std::reverse(binaryAddress.begin(), binaryAddress.end());
   return binaryAddress;
}

int CPU::binaryToInt(std::string strAdress){
   int intAdress = 0;
   int base = 1;
   for(int i = strAdress.size() - 1; i >= 0; i--){
       intAdress += int(strAdress[i] - 48) * base;
        base *= 2;
   }
   return intAdress;
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
   this->output << "MISS RATE: " << missRate << std::endl;

    for(std::vector<std::string>::iterator it = history.begin(); it!= history.end(); it++)
        this->output << *it;

}