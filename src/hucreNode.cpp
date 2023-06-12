/**
* file hucrenode.cpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/
#include "hucreNode.hpp"

HucreNode::HucreNode( int dna, HucreNode *next , HucreNode *prev ) {
    this->dna = dna;
    this->next = next;
    this->prev = prev;
}
HucreNode::HucreNode( int dna, HucreNode *next) {
    this->dna = dna;
    this->next = next;
    this->prev = prev;
}
HucreNode::HucreNode( int dna) {
    this->dna = dna;
    this->next = next;
    this->prev = prev;
}