#ifndef CACHE_H
#define CACHE_H

#include "memory.h"
#include "cacheBlock.h"

#include <string>
#include <vector>

#define CACHE_SIZE 64 // Must change to 256

    class Cache{
    private:
        Memory memory;
        CacheBlock blocks[CACHE_SIZE];
    public:
        Cache();
        ~Cache();
        bool hit(int); // tagging hits and misses
        bool search(int address);
        int getIndex(int);
        int getOffset(int);
        int getTag(int);
        void write(int, std::string); 
        void change(int, std::string);
        void replace(int, std::vector<std::string>);
        bool find(int);
    };

#endif