#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
//#include <cstring>

using namespace std;
 ofstream out ("duom/rez3.txt");

struct mokiniai{
    string vardas;
    float pazymys;
};

void kiekis(int &kiekMok, const char byla1[]);
void skaitymas(mokiniai duomenys[], int kiekis, const char byla[]);
void vidurkis(mokiniai duomenys[], int kiekis, float &vidurk);
void rikiavimas (mokiniai duomenys[], int kiekis); //??
void rasymas(mokiniai Masyvas[], int kiek, float grupesVidurkis, string textas);

int main()
{
    int kiekMokiniu1, kiekMokiniu2, kiekMokiniu3, kiekMokiniu4, sk;
    float vid1, vid2, vid3, vid4;

    const char duomenysMokiniai1[] = "duom/duom3_1.txt";
    const char duomenysMokiniai2[] = "duom/duom3_2.txt";
    const char duomenysMokiniai3[] = "duom/duom3_3.txt";
    const char duomenysMokiniai4[] = "duom/duom3_4.txt";

    kiekis(kiekMokiniu1, duomenysMokiniai1);
    kiekis(kiekMokiniu2, duomenysMokiniai2);
    kiekis(kiekMokiniu3, duomenysMokiniai3);
    kiekis(kiekMokiniu4, duomenysMokiniai4);

    mokiniai klase_1[kiekMokiniu1], klase_2[kiekMokiniu2], klase_3[kiekMokiniu3], klase_4[kiekMokiniu4];

    skaitymas(klase_1, kiekMokiniu1, duomenysMokiniai1);
    skaitymas(klase_2, kiekMokiniu2, duomenysMokiniai2);
    skaitymas(klase_3, kiekMokiniu3, duomenysMokiniai3);
    skaitymas(klase_4, kiekMokiniu4, duomenysMokiniai4);

    vidurkis(klase_1, kiekMokiniu1, vid1);
    vidurkis(klase_2, kiekMokiniu2, vid2);
    vidurkis(klase_3, kiekMokiniu3, vid3);
    vidurkis(klase_4, kiekMokiniu4, vid4);
    cout<<vid1<<endl<<vid2<<endl<<vid3<<endl<<vid4<<endl;

    rikiavimas(klase_1,kiekMokiniu1);
    rikiavimas(klase_2,kiekMokiniu2);
    rikiavimas(klase_3,kiekMokiniu3);
    rikiavimas(klase_4,kiekMokiniu4);

    rasymas(klase_1,kiekMokiniu1,vid1, "Klase 1: ");
    rasymas(klase_2,kiekMokiniu2,vid2, "Klase 2: ");
    rasymas(klase_3,kiekMokiniu3,vid3, "Klase 3: ");
    rasymas(klase_4,kiekMokiniu4,vid4, "Klase 4: ");




    //skaitymas("duom/duom3_1.txt", sk);


    return 0;
}

void kiekis(int &kiekMok, const char byla1[]){
    ifstream in (byla1);
    mokiniai LaikStruktura[1];
    kiekMok=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].pazymys;
        kiekMok++;
    }
    in.seekg(0);
    in.close();
}


void skaitymas(mokiniai duomenys[], int kiekis, const char byla[]){
    ifstream in(byla);
    for (int i=0; i<kiekis; i++){
        in>>duomenys[i].vardas>>duomenys[i].pazymys;
    }
    in.close();
}


void vidurkis (mokiniai duomenys[], int kiekis, float &vidurk){
    float suma=0;

    for (int i=0; i<kiekis; i++){
        suma+=duomenys[i].pazymys;
        }
        vidurk = float(suma)/float(kiekis);
}

void rikiavimas(mokiniai duomenys[], int kiekis){

      float laikinas;
      string laikVardas;

    for(int i=0; i<kiekis; i++){
        for(int j=1; j<kiekis-1; j++){
            if (duomenys[j-1].pazymys<=duomenys[j].pazymys){
                laikinas=duomenys[j].pazymys;
                laikVardas=duomenys[j].vardas;

                duomenys[j].pazymys=duomenys[j-1].pazymys;
                duomenys[j].vardas=duomenys[j-1].vardas;
                duomenys[j-1].pazymys=laikinas;
                duomenys[j-1].vardas=laikVardas;
            }
        }
    }
}

void rasymas(mokiniai duomenys[], int kiek, float grupesVidurkis, string textas){
out<<textas<<endl;
    for(int i=0; i<kiek; i++){
            if(duomenys[i].pazymys>grupesVidurkis)

        out<<duomenys[i].vardas<<duomenys[i].pazymys<<endl;
    }
}
