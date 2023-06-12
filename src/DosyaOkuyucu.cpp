/**
* file dosyaokuyucu.cpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/
#include "DosyaOkuyucu.hpp"




DosyaOkuyucu :: DosyaOkuyucu(string fileName){
	this->fileName = fileName;
	
	int linecount = lineCount();
	
	this->lines = new Hucre*[linecount];
	for(int i=0; i<linecount; i++){
		this->lines[i] = new Hucre();
	}
	
	
}
void DosyaOkuyucu :: readLine(){
	
	ifstream readfile(this->fileName);
	string context;
	string str;
	int index = 0;
	
	
	while(getline(readfile,context)){
		
		istringstream s1(context);
		
		while(getline(s1, str, ' ')){
			this->lines[index]->Add(stoi(str));
			
		}
		
		index++;
	
		
	}
	readfile.close();
}


Doku* DosyaOkuyucu :: FillDoku(){ 
	readLine(); //okuma islemi yapildi tum listedekiler hucre nesnelerine eklendi.
	Doku* tmp = new Doku();
	int linecount = lineCount();
	
	for(int i=0; i<linecount; ++i){
		tmp->add(this->lines[i]);
		
	}
	
	return tmp;  
}


int DosyaOkuyucu ::  lineCount(){
	int count = 0;
	ifstream readfile(this->fileName);
	string context;
	while(getline(readfile, context)){
		++count;
	}
	
	readfile.close();
	
	return count;
}

DosyaOkuyucu :: ~DosyaOkuyucu(){
	if(lines!=0){
		int count = lineCount();
		
		for(int i=0; i<count; i++){
			if(lines[i]!=0) delete lines[i];
		}
	
		
		delete[] lines;
	}
}
	
