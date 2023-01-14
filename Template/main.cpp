#include<iostream>
using namespace std;

template<typename Temp> Temp swap(Temp* data1, Temp* data2){
    Temp pom = *data1;
	*data1 = *data2;
	*data2 = pom;
}

int main(){
	int n1 = 10;
    int n2 = 5;
    swap(n1, n2);
    cout<<endl<<n1<<" swap to "<<n2;

    float f1 = 3.123;
    float f2 = 35.1233;
    swap(f1, f2);
    cout<<endl<<f1<<" swap to "<<f2;
    
    string s1 = "quang";
    string s2 = "bui";
    swap(s1, s2);
    cout<<endl<<s1<<" swap to "<<s2;

    char c1 = 'q';
    char c2 = 'b';
    swap(c1, c2);
    cout<<endl<<c1<<" swap to "<<c2;

    return 0;
}