/* 
 * File:   Hucre.hpp
 * Author: Berkay Kopuz
 *
 * Created on November 10, 2022, 6:26 PM
 */
 
 #include <iostream>
 #include "hucre.hpp"

 
 using namespace std;
 
 Hucre :: Hucre(){
	 head = NULL;
	 size = 0;
 }		
 bool Hucre :: isEmpty()const{
	 return size == 0;
 } 
 int Hucre :: Count()const{
	return size;
 }
 const int& Hucre :: FindFirst(){
	 if(isEmpty()) throw "Node is empty.";
	 return head->dna;
 }
 const int& Hucre ::  FindLast(){
	 if(isEmpty()) throw "Node is empty.";
	 return FindPrevByPosition(size)->dna;
 }
 HucreNode* Hucre ::  FindPrevByPosition(int position){
	 if(position<0 || position>size) throw "Index out of Range";
			int index=1;
			for(HucreNode *tmp = head; tmp!=NULL; tmp=tmp->next,index++){
				if(position == index) return tmp;
			}
			return NULL;
 }
 void Hucre :: RemoveAt(int index){
	 if(index<0 || index>size) throw "Out of range";
	 HucreNode *del;
	 if(index==0){
		 del = head;
		 head = head->next;
		 if(head != NULL) head->prev = NULL;
		 
		 
	 }
	 else{
		 HucreNode *prv = FindPrevByPosition(index);
		 del= prv->next;
		 prv->next = del->next;
		 if(del->next!=NULL) del->next->prev = prv;
	 }
	 size--;
	 delete del;
 }
 void Hucre :: Add(const int& dna){
	 Insert(dna,size);
 }
 void Hucre ::  Insert(const int& dna, int index){
	 if(index<0 || index > size) throw "Index out of range";
	 if(index==0){
		 head= new HucreNode(dna,head);
		 if(head->next != NULL){
			 head->next->prev = head;
		 }
	 }
	 else{
		 HucreNode *prv = FindPrevByPosition(index);
		 prv->next=new HucreNode(dna, prv->next, prv);
		 if(prv->next->next != NULL) prv->next->next->prev= prv->next;
	 }
	 size++;
	 
 }
 void Hucre :: Reverse(){
	 for(HucreNode *itr =head; itr!=NULL;){
		 HucreNode *tmp = itr->next;
		 itr->next = itr->prev;
		 itr->prev = tmp;
		 if(tmp==NULL){
			 head = itr;
			 break;
		 }
		 itr = tmp;
	} 
 }
 const int& Hucre::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->dna;
    return FindPrevByPosition(index)->next->dna;
}
void Hucre :: DivideHalf(){
	for(HucreNode *itr = head; itr!=NULL; itr = itr->next)
	itr->dna /= 2;
}
int Hucre::elemanSayisi(){
	int sayac = 0;
	for(HucreNode *hucreNode=this->head; hucreNode!=NULL; hucreNode=hucreNode->next) sayac++;

	return sayac;
}
 
 


 

