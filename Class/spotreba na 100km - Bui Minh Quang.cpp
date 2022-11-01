#include<iostream>
#include<iomanip>
using namespace std;

class Vozidlo{
    private:
        string Znacka;
        int Ujetokm;
        int Projeto;
        float Spotreba;
    public:
        double calculate(Vozidlo v){
            v.Spotreba = ((double)v.Projeto/(double)v.Ujetokm)*100;
            return v.Spotreba;
        }
        void execute(Vozidlo v, string s, int u, int p){
            v.Projeto = p;
            v.Ujetokm = u;
            v.Znacka = s;
            cout<<fixed<<setprecision(2);
            cout<<"\nSpotreba na 100km auta znacky "<< s <<" (v literech): "<< calculate(v)<<" l/100km";
        }
};

int main(){
    string Znacka;
    int Ujetokm;
    int Projeto;
    cout<<"Zadej znacku: ";
    cin>>Znacka;
    cout<<"\nZadej hodnotu ujetych km: ";
    cin>>Ujetokm;
    cout<<"\nZadej hodnotu projetych litru: ";
    cin>>Projeto;

    Vozidlo v;
    v.execute(v, Znacka, Ujetokm, Projeto);
}