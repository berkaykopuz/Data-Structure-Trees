#ifndef DOSYAOKUYUCU_HPP
#define DOSYAOKUYUCU_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "hucre.hpp"
#include "doku.hpp"

using namespace std;

class DosyaOkuyucu{

	private:
	
	string fileName;
	void readLine();
	Hucre **lines;
	
	public:

	int lineCount();
	Doku* FillDoku();
	DosyaOkuyucu(string fileName);
	~DosyaOkuyucu();
	
	
};





#endif