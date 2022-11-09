#include<iostream>
#include<fstream>
using namespace std;

class S{
    private:
        int x1 = 0;
        int y1 = 0;
        int x21 = 10;
        int y21 = 1;
    public:
        S(string path);
        
        void Ship(int num){
            x1 += num*x21;
            y1 += num*y21;
        }
        
        void Waypoint(int num, char direction){
            switch(direction){
                case 'N':{
                    y21+=num;
                    break;
                }

                case 'S':{
                    y21-=num;
                    break;
                }

                case 'E':{
                    x21+=num;
                    break;
                }

                case 'W':{
                    x21-=num;
                    break;
                }
            }
        }

        void Right(int num){
            int pom1 = x21;
            int pom2 = y21;
            switch(num){
                case 90:{
                    if(pom1>0){
                        if(pom2>0){
                            x21 = -y21;
                            y21 = pom1;
                        }
                        else{
                            x21 = -y21;
                            y21 = pom1;
                        }
                    }
                    else{
                        if(pom2>0){
                            x21 = -y21;
                            y21 = pom1; 
                        }
                        else{
                            x21 = -y21;
                            y21 = x21;
                        }
                    }
                }

                case 180:{
                    x21=-x21;
                    y21=-y21;
                    break;
                }

                case 270:{
                    Left(90);
                }
            }
        }

        void Left(int num){
            int pom1=x21;
            int pom2=y21;
            switch(num){
                case 90:{
                    if(pom1>0){
                        if(pom2>0){
                            x21 = y21;
                            y21 = -pom1;
                        }
                        else{
                            x21 = y21;
                            y21 = -pom1;
                        }
                    }
                    else{
                        if(pom2>0){
                            x21 = y21;
                            y21 = -pom1; 
                        }
                        else{
                            x21 = y21;
                            y21 = -x21;
                        }
                    }
                }

                case 180:{
                    x21=-x21;
                    y21=-y21;
                    break;
                }

                case 270:{
                    Right(90);
                }
            }
        }
};

S::S(string path){
    ifstream fs;
    char direction;
    string pom;
    int num;
    fs.open(path);
    if(fs){
        while(!fs.eof()){
            fs>>direction;
            getline(fs, pom);
            num = stoi(pom);
            if(direction == 'F')
                Ship(num);
            else if(direction == 'L')
                Left(num);
            else if(direction == 'R')
                Right(num);
            else
                Waypoint(num, direction);
        }
        
        cout<<"\nx= "<<x1;
        cout<<"\ny= "<<y1;
        cout<<"\nx21 = "<<x21;
        cout<<"\ny21 = "<<y21;
    }
    else
        cout<<"Error!";
}

int main(){
    S("F:/Testing Stupid Code/Stupid Code/Stupid Code/navigace.txt");
}
