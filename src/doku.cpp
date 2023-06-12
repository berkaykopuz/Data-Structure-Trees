/**
* file doku.cpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/
#include "doku.hpp"


Doku::Doku() {
    head = NULL;
    size = 0;
}

DokuNode* Doku::FindPrevByPosition(int index) {
    if (index < 0 || index > size)throw "No Such Element";
    DokuNode *prv = head;
    int i = 1;
    for (DokuNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

DokuNode* Doku::FindPosition(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    return this->FindPrevByPosition(index + 1);

}

Hucre*& Doku::first(){
    if (isEmpty()) throw "No Such Element";
    return head->hucre;
}

Hucre*& Doku::last(){
    if (isEmpty()) throw "No Such Element";
    return FindPrevByPosition(size)->hucre;
}


int Doku::Count()const {
    return size;
}

bool Doku::isEmpty()const {
    return size == 0;
}

void Doku::add(Hucre*& hucre) {
    insert(size, hucre);
}

void Doku::insert(int index, Hucre*& hucre) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new DokuNode(hucre, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        DokuNode *prv = FindPrevByPosition(index);
        prv->next = new DokuNode(hucre, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}



int Doku::indexOf(Hucre*& hucre) {
    int index = 0;
    for (DokuNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->hucre == hucre) return index;
        index++;
    }
    throw "No Such Element";
}

void Doku::remove(Hucre*& hucre) {
    int index = indexOf(hucre);
    removeAt(index);
}


void Doku::removeAt(int index) {
    if (index < 0 || index >= size) throw "Index out of Range";
    DokuNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        DokuNode *prv = FindPrevByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

void Doku::moveNode(int from, int to){
    if (from < 0 || from >= size) throw "index out of bound";
    DokuNode *del;
    if (from == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        DokuNode *prv = FindPrevByPosition(from);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    if (to < 0 || to > size) throw "Index out of Range";
    if (to == 0) {

        del->next = head;
        del->prev = NULL;
        head = del;
        if (head->next != NULL) head->next->prev = head;
    } else {
        DokuNode *prv = FindPrevByPosition(to);

        del->next = prv->next;
        del->prev = prv;
        prv->next = del;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

bool Doku::find(Hucre*& item) {
    for (DokuNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->hucre == item) return true;
    }
    return false;
}

void Doku::reverse() {
    for (DokuNode *itr = head; itr != NULL;) {
        DokuNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL) {
            head = itr;
            break;
        }
        itr = tmp;
    }
}



Hucre*& Doku::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->hucre;
    return FindPrevByPosition(index)->next->hucre;
}

void Doku::clear() {
    while (!isEmpty()){
        removeAt(0);
    }
        
}



