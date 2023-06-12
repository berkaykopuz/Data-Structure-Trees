/**
* file queue.hpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;


class Node{
	public:
		int item;
		Node *next;
		Node(int itm,Node *nxt=NULL){
			item=itm;
			next=nxt;
		}
};


class Queue{
	private:
		Node *front;
		Node *back;
		int length;
		
	public:
		Queue(){
			front=back=NULL;
			length=0;
		}
		void clear(){
			while(!isEmpty()) dequeue();
		}
		int count() const{
			return length;
		}
		bool isEmpty() const {
			return length == 0;
		}
		/// Kuyrukta en öndeki elemanı getirir
		const int& peek() const{
			if(isEmpty()) throw "Queue is empty";
			return front->item;
		}
		void enqueue(const int& item){			
			Node *last = new Node(item);	
			if(isEmpty()) front = back = last;
			else{
				back->next = last;
				back = last;
			}
			length++;
		}
		void dequeue(){
			if(isEmpty()) throw "Queue is empty";			
			Node *eskiOn = front;
			front = front->next;
			delete eskiOn;
			length--;
		}
		~Queue(){
			clear();
		}		
};
#endif