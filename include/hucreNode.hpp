#ifndef HUCRENODE_HPP
#define HUCRENODE_HPP


#include <iostream>
using namespace std;

class HucreNode {
public:
    int dna;
    HucreNode *next;
    HucreNode *prev;

    HucreNode(int dna, HucreNode *next, HucreNode *prev);
    HucreNode(int dna, HucreNode *next);
    HucreNode(int dna);
};




#endif 