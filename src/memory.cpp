#include "../include/memory.h"
#include "../include/cpu.h"
#include <iostream>
#include <vector>
#include <map>

Memory::Memory(){
	int size = 4096;
	for(int i = 0; i < size; i++){
		this->data[i] = CPU::intToBinary(0);
	}
}

void Memory::write(int address, std::string word){
	this->data[address] = word;
}

void Memory::writeBlock(int address, std::vector<std::string> words){
	int start = address - (address % 4); // taking out the last 2 bits
	std::vector<std::string> block;
	for(int i = 0; i < 4; i++){
		this->write(start + i, words[i]);
	}
}

std::string Memory::getWord(int address){ // acessing data, a private attribute
	return this->data.find(address)->second; 
}

std::vector<std::string> Memory::getBlock(int address){
	int start = address - (address % 4); // taking out the last 2 bits
	std::vector<std::string> block;
	for(int i = 0; i < 4; i++){
		block.push_back(this->getWord(start + i));
	}
	// std::cout << "BLOCK SIZE ON GETBLOCK: " << block.size() << std::endl;
	return block;
}