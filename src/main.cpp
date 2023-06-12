/**
* file main.cpp
* @description organizma yazdiran uygulama.
* @course 2A
* @assignment 2
* date 12/21/2022
* author berkaykopuz
*/

#include <iostream>
#include "doku.hpp"
#include "DosyaOkuyucu.hpp"
#include "hucre.hpp"
#include "hucreNode.hpp"
#include "queue.hpp"
#include "radix.hpp"
#include "bst.hpp"
using namespace std;



int main(){
    DosyaOkuyucu *dosyaOkuyucu = new DosyaOkuyucu("veri.txt");
    Doku *doku = dosyaOkuyucu->FillDoku(); //hazır doku
    Radix *radix; //radix
    int dokuSayisi=dosyaOkuyucu->lineCount();

    BST *organ = new BST();
    char cevap;


    system("CLS");
    cout << "ORGANIZMA(NORMAL)";
    
    ///////// BALİK YAZDİRİYOR ///////////
    for(int i=0; i<dokuSayisi; i++ ){ //her döngü sonunda sıfırdan organ oluşturup o anda if ile avlye bakacak ve # vesaire yazdıracak
            if(i%20==0){
                if(organ->Check()==0){
                    cout << "#";
                }
                else{
                    cout << " ";
                }

                organ->Clear();
            }
            if(i%2000==0){
                cout << endl;
            }

            int dizi[doku->elementAt(i)->elemanSayisi()];
            doku->elementAt(i); 

            for(int j=0; j<doku->elementAt(i)->elemanSayisi(); j++){
                dizi[j] = doku->elementAt(i)->elementAt(j);
            }

            radix = new Radix(dizi,doku->elementAt(i)->elemanSayisi());
            int *sirali = radix->Sort();
            

            organ->Add(sirali[(doku->elementAt(i)->elemanSayisi()+1)/2-1]); 
            
        }

    
        

    /////////////// MUTASYONA UGRAYIP DEVAM ETME //////////// 
    
    cout << endl << "Mutasyona ugratmak icin rastgele bir karaktere basip enterlayabilirsiniz." << endl;
    cin>>cevap;
    
    system("CLS");

    cout << "ORGANIZMA (MUTASYONA UGRADI)" << endl;
        for(int i=0; i<dokuSayisi; i++ ){ //her döngü sonunda sıfırdan organ oluşturup o anda if ile avlye bakacak ve # vesaire yazdıracak
        
        
        
        if(i%20==0){

            if(organ->firstOfRoot()%50==0){ //organın kök değeri 50'ye bölünüyorsa
            
            organ->Clear();
            for(int a=i-20; a<i; a++){
                for(int j=0; j<doku->elementAt(a)->elemanSayisi(); j++){
                    if(doku->elementAt(a)->elementAt(j)%2==0)
                     doku->elementAt(a)->DivideHalf();
                }
                

                int dizi[doku->elementAt(a)->elemanSayisi()];

                for(int j=0; j<doku->elementAt(a)->elemanSayisi(); j++){
                dizi[j] = doku->elementAt(a)->elementAt(j);
                }

                
                radix = new Radix(dizi,doku->elementAt(a)->elemanSayisi());
                int *sirali = radix->Sort();
                
                organ->Add(sirali[(doku->elementAt(a)->elemanSayisi()+1)/2-1]); 
            }

            


            }
            if(organ->Check()==0){
                cout << "#";
            }
            else{
                cout << " ";
            }

            organ->Clear();
        }
        if(i%2000==0){
            cout << endl;
        }

        int dizi[doku->elementAt(i)->elemanSayisi()];
        

        for(int j=0; j<doku->elementAt(i)->elemanSayisi(); j++){
            dizi[j] = doku->elementAt(i)->elementAt(j);
        }

        radix = new Radix(dizi,doku->elementAt(i)->elemanSayisi());
        int *sirali = radix->Sort();
        
       
        
        

        organ->Add(sirali[(doku->elementAt(i)->elemanSayisi()+1)/2-1]); 
        
        }
        
    
    

    



}