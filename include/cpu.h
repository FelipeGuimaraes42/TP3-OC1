#ifndef CPU_H
#define CPU_H

#include <fstream>

    class CPU{
    private:
        std::ifstream input;
        std::ofstream output;
    public:
        CPU(char const *file);
        ~CPU();
        void run();
        void print();
    };

#endif