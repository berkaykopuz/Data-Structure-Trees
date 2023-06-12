#ifndef DOKU_HPP
#define DOKU_HPP



#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include "hucre.hpp"
#include "dokuNode.hpp"

class Doku{
	private:
	
    DokuNode *head;
    int size;
    DokuNode* FindPrevByPosition(int index);
    DokuNode* FindPosition(int index);
	
	public:
	//işlevsel fonksiyonlar
	Doku();
	int Count()const;
	Hucre*& first();
    Hucre*& last();
    bool isEmpty()const;
    void add(Hucre*& item);
    void insert(int index, Hucre*& item);
    int indexOf(Hucre*& item);
    void remove(Hucre*& item);
    void randomRemoveAtHucre(int index, int inlineIndex);
    void calculateAveragee(int index);
    int randomGenerator(int index);
    void removeAt(int index);
    int generateRandom(int index);
    void moveNode(int from, int to);
    bool find(Hucre*& item);
    void reverse();
    Hucre*& elementAt(int index);
    void clear();
    void printIndex(int index, int x, int y);
    ~Doku();
    
};



#endif
