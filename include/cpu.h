#ifndef CPU_H
#define CPU_H

#include "../include/cache.h"

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>

    class CPU{
    private:
        std::ifstream input;
        std::ofstream output;
        int numWrites= 0; // counters to display correct output
        int numReads= 0;
        int numMisses= 0;
        int numHits= 0;
        Cache *cache = nullptr;
        std::vector<std::string> history;
    public:
        CPU(char const *file);
        ~CPU();
        void run();
        static std::string intToBinary(int);
        static int binaryToInt(std::string);
        void print();
    };

#endif