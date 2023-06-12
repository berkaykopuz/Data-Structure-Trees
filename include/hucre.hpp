/* 
 * File:   hucre.hpp
 * Author: Berkay Kopuz
 *
 * Created on November 10, 2022, 6:26 PM
 */
 
#ifndef HUCRE_HPP
#define HUCRE_HPP

#include "hucreNode.hpp"



class Hucre{
	private:
		HucreNode *head;
		int size; 
		HucreNode* FindPrevByPosition(int position);
	
	
	public:
		Hucre();
		bool isEmpty()const;
		int Count()const;
		int IndexOf(const int& dna);
		void Add(const int& dna);
		void Insert(const int& dna, int index);
		const int& FindFirst();
		const int& FindLast();
		void Remove(const int& dna);
		void RemoveAt(int index);
		void Reverse();
		const int& elementAt(int index);
		int elemanSayisi();
		void DivideHalf();
		
	
};

#endif