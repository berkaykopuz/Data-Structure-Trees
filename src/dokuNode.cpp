/**
* file dokunode.cpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/
#include "dokuNode.hpp"


DokuNode::DokuNode(Hucre* data, DokuNode *next , DokuNode *prev) {
    hucre = data;
    this->next = next;
    this->prev = prev;
    
}

DokuNode::DokuNode(Hucre* data, DokuNode *next) {
    hucre = data;
    this->next = next;
    this->prev = prev;
    
}

DokuNode::DokuNode(Hucre* data) {
    hucre = data;
    this->next = next;
    this->prev = prev;
    
}

