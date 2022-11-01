#include<iostream>
using namespace std;

bool primenumber(int num){
    bool test = true;

    if(num>1){
        for(int i = 2; i < num; i++){
            if(num % i == 0)
                test = false;
        }
    }
    else 
        test = false;

    return test;
}

int JeProvocislo(int num){
    if(primenumber(num) == true)
        cout<<num<<" je provocislo!";
    else
        cout<<num<<" neni provocislo!";

    return num;
}

void CifernySoucet(){
    int prime[1000];
    int count = 0;

    cout<<"\n\n\n\n";

    for(int num = 999000; num <= 1001000; num++){
        if (primenumber(num)==true){
            prime[count] = num;
            count++;
        }
    }

    int c13 = 0;
    int c44 = 0;

    for(int i = 0; i < count ; i++){
        int cal = 0;
        while(prime[i]/10 > 0){
            cal+= prime[i]%10;
            prime[i] = prime[i] / 10;
        }

        if (cal==13)
            c13++;

        if (cal==44)
            c44++;
    }
    cout<<"\nSoucet ciferny 13: "<<c13;

    cout<<"\nSoucet ciferny 44: "<<c44;
}
int main(){
    int num;
    cout<<"Zadej cislo: ";
    cin>>num;
    num=JeProvocislo(num);

    CifernySoucet();
}