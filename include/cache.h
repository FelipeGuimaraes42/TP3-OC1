#ifndef CACHE_H
#define CACHE_H

#include "memory.h"
#include "cacheBlock.h"

#include <string>
#include <vector>

    class Cache{
    private:
        Memory memory;
        CacheBlock blocks[256];
    public:
        Cache();
        ~Cache();
        bool hit(int); // tagging hits and misses
        static int getIndex(int);
        static int getOffset(int);
        static int getTag(int);
        void write(int, std::string); 
        void change(int, std::string);
        void replace(int, std::vector<std::string>);
        bool find(int);
    };

#endif