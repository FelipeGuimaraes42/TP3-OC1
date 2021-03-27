#include "../include/cacheBlock.h"
#include <string>
#include <vector>

bool CacheBlock::isValid () {
    return this->valid;
}
bool CacheBlock::isDirty () {
    return this->dirty;
}
int  CacheBlock::getTag () {
    return this->tag;
}
std::string CacheBlock::getData (int offset) {
    return this->data[offset];
}
 
void CacheBlock::setValid (bool valid) {
    this->valid = valid;
}
void CacheBlock::setDirty (bool dirty) {
    this->dirty = dirty;
}
void CacheBlock::setTag (int tag) {
    this->tag = tag;
}
void CacheBlock::setData (std::string data, int offset) { // acessing data, a private attribute
    this->data[offset] = data;
}

std::vector<std::string> CacheBlock::toVector () {
    std::vector<std::string> dataBlock (BLOCK_SIZE) ;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        dataBlock[i] = this->data[i];
    }
    return dataBlock;
}