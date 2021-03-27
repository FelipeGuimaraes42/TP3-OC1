#ifndef CPU_H
#define CPU_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

    class CPU{
    private:
        std::ifstream input;
        std::ofstream output;
        int numWrites= 0;
        int numReads= 0;
        int numMisses= 0;
        int numHits= 0;
        std::vector<std::string> history;
    public:
        CPU(char const *file);
        ~CPU();
        void run();
        void print();
    };

#endif