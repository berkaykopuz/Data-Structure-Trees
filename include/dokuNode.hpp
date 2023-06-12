#ifndef DOKUNODE_HPP
#define DOKUNODE_HPP


#include "hucre.hpp"

class DokuNode{
public:
    Hucre* hucre;
    DokuNode *next;
    DokuNode *prev;

    DokuNode(Hucre* data, DokuNode *next, DokuNode *prev);
    DokuNode(Hucre* data, DokuNode *next);
    DokuNode(Hucre* data);
    
};



#endif 

