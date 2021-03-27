#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>
#include <map>

    class Memory{
    private:
        // Map address to word
        std::map<int, std::string> data;
    public:
        Memory();
        void write(int address, std::string);
        void writeBlock(int address, std::vector<std::string>);
        std::string getWord(int address);
        std::vector<std::string> getBlock(int address);
    };

#endif