#include<iostream>
#include<math.h>
using namespace std;

class moving{
    public:
    moving();
    int vx;
    int vy;
    int x = 0;
    int y = 0;
    void c_x();
    void c_y();
};

 
void moving::c_x(){
    x += vx;
    if(vx!=0)
        vx -= 1;
}

void moving::c_y(){
    y += vy;
    vy -= 1;
}

moving::moving(){
    int pom = 0;
    for(int i = 20; i <= 22; i++){
        for (int j =1; j <= 1000; j++){
            vx = i;
            vy = j;
            x = 0;
            y = 0;
            while(vx != 0){
                c_x();
                c_y();
            }
            if(x <= 251 && x >= 192 && y>=-89){
                cout<<"\n";
                cout<<"\nvx0= "<<i<<"    "<<"vy0= "<<j;
                cout<<"\nvy= "<<vy;
                cout<<"\nx= "<<x<<"\t"<<"y= "<<y;
                int test = 0.5*y + 0.25*(j*j - vy*vy);
            }
        }
    }
}

int main(){
    float t1, t2, t;
    int check;
    for(int i = 1; i<=100; i++){
        for(int j = -89; j<=-59; j++){
            for(int k = 192; k <= 251; k++){
                t1 = i + sqrt(i*i - 2*j) - sqrt (2*k);
                t2 = i - sqrt(i*i - 2*j) - sqrt (2*k);
                check = t1*1;
                
                if(t1 == check*1){
                    cout<<"\nt= "<<t1;
                    cout<<"\nx= "<<k<<"\t"<<"\ny= "<<j;
                    cout<<"\nvy= "<<i<<endl;;
                }
                check = t2*1;
                if(t2 == check*1){
                    cout<<"\nt= "<<t2;
                    cout<<"\nx= "<<k<<"\t"<<"\ny= "<<j;
                    cout<<"\nvy= "<<i<<endl;
                }
            }
        }
    }
}