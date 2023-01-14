#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int calo(string num){
    int pom;
    stringstream ss;
    ss << num;
    if(ss >> pom){
        return pom;
    }
    else{
        return 0;
    }
}

int main(){
    ifstream fs;
    fs.open("input.txt");
    string pom;
    int num = 0;
    int largest = 0;

    while(getline(fs, pom)){
        num += calo(pom);
        if(calo(pom) == 0){
            if(largest <= num)
                largest = num;
            num = 0;
        }
    }
    
    cout<<largest;
}