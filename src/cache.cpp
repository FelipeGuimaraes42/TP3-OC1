#include "../include/cache.h"
#include "../include/cpu.h"

// Cache com 256 blocos, log2(256) = 8 bits para o index
// Blocos com 4 palavras, log2(4) = 2 bits para o offset
// Words de 32 bits, então 32-8-2 = 22
   
//     Tag          Idx      offset
// 0000...0000 | 0000 0000 | 00

Cache::Cache(){};

Cache::~Cache(){};

int Cache::getOffset(int address){
   std::string bitAddress = CPU::intToBinary(address);
   return CPU::binaryToInt(bitAddress.substr(bitAddress.size()-2,2));
}

int Cache::getIndex(int address){
   std::string bitAddress = CPU::intToBinary(address);
   return CPU::binaryToInt(bitAddress.substr(bitAddress.size()-10, 8));
}

int Cache::getTag(int address){
   std::string bitAddress = CPU::intToBinary(address);
   return CPU::binaryToInt(bitAddress.substr(0,21));
}

bool Cache::hit(int address){
    int index = Cache::getIndex(address);
    return ((this->blocks[index].isValid()) && (Cache::getTag(address) == this->blocks[index].getTag()));
}

void Cache::replace (int address, std::vector<std::string> data) {
    int index = this->getIndex(address);
    
    if(this->blocks[index].isValid() && this->blocks[index].isDirty()){
        std::vector<std::string> dataBlock = this->blocks[index].toVector();
        this->memory.writeBlock(address, dataBlock);
    }
    
    this->blocks[index].setTag(this->getTag(address));
    this->blocks[index].setDirty(false); // everything went right
    this->blocks[index].setValid(true);

    for(int i = 0; i < 4; i++){ // for every word
        this->blocks[index].setData(data[i], i); // change data
    }
    
}

bool Cache::find (int address) {
    if (hit(address))
        return true;
    else {
        std::vector<std::string> newData = this->memory.getBlock(address);
        replace(address, newData);
        return false;
    }
}

void Cache::change(int address, std::string data){
   int index = Cache::getTag(address);
   int offset = Cache::getOffset(address);
   this->blocks[index].setDirty(true);
   this->blocks[index].setData(data, offset);
}

void Cache::write(int address, std::string data){
    if(this->hit(address))
        this->change(address, data);
    else{
        int offset = Cache::getOffset(address);
        std::vector<std::string> dataBlock = this->memory.getBlock(address);
        dataBlock.at(offset) = data;
        this->replace(address, dataBlock);
    }
}