#include "Prislusnik.h"
#include<string.h>
#include<ctime>
#include<iostream>
using namespace std;
void Prislusnik::kontrolacislo(){
    bool check = true;
    string pom;
    control:
    if(check==false)
        cout<<"\nChypny vstup zadej znovu!\n";
    cout<<"Zadej rodne cislo: ";
    cin>>pom;

    if(pom.length() != 11){
        check = false;
        goto control;
    }

    if(pom[6] != '/'){
        check = false;
        goto control;
    }

    for(int i = 0; i < 11; i++){
        if(i != 6){
            if(pom[i] > '9' || pom [i] < '0'){
                check = false;
                goto control;
            }
        }
    }

    rodnecislo = pom;
}

void Prislusnik::kontrolajmeno(){
    bool check = true;
    string pom;
    control:
    if(check==false)
        cout<<"\nChypny vstup zadej znovu!\n";

    cout<<"Zadej jmeno: ";
    cin>>pom;

    if(pom[0] > 'Z' || pom[0] < 'A'){
        check = false;
        goto control;
    }

    for(int i = 1; i < pom.length(); i++){
        if(pom[i] > 'z' || pom[i] < 'a'){
            check = false;
            goto control;
        }
    }

    jmeno = pom;
}

void Prislusnik::kontrolaprijmeni(){
    bool check = true;
    string pom;
    control:
    if(check==false)
        cout<<"\nChypny vstup zadej znovu!\n";

    cout<<"Zadej prijmeni: ";
    cin>>pom;

    if(pom[0] > 'Z' || pom[0] < 'A'){
        check = false;
        goto control;
    }

    for(int i = 1; i < pom.length(); i++){
        if(pom[i] > 'z' || pom[i] < 'a'){
            check = false;
            goto control;
        }
    }

    prijmeni = pom;
}

void Prislusnik::kontroladatumnarozeni(){
    y = stoi(rodnecislo.substr(0, 2));
    m = stoi(rodnecislo.substr(2, 2));
    d = stoi(rodnecislo.substr(4, 2));

    time_t t = time(NULL);
    tm* time = localtime(&t);
    int pom = time->tm_year - 100;

    if(y > pom)
        y = 1900 + y;
    else
        y = 2000 + y;
    
    if(m > 12){
        pohlavi = "Z";
        m = m - 50;
    }
    else
        pohlavi = "M";
}

Prislusnik::Prislusnik(){
    kontrolacislo();
    kontrolajmeno();
    kontrolaprijmeni();
    kontroladatumnarozeni();
    cout<<"\nJmeno: "<<jmeno;
    cout<<"\nPrijmeni: "<<prijmeni;
    cout<<"\nRodne cislo: "<<rodnecislo;
    cout<<"\nDatum narozeni: ";

    if(d < 10)
        cout<<"0"<<d<<"/";
    else
        cout<<d<<"/";

    if(m < 10)
        cout<<"0"<<m<<"/";
    else
        cout<<m<<"/";
    
    cout<<y;

    cout<<"\nPohlavi: "<<pohlavi;
}