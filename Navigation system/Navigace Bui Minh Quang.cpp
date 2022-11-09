#include<iostream>
#include<fstream>
using namespace std;

class ship{
    private:
        int x = 0, y = 0;
        char direction = 'E';
    public:
        ship(string path);

        void LR(bool check){
            switch(direction){
                case 'E':{
                    if (check==true)
                        direction = 'S';
                    else 
                        direction = 'N';
                    break;
                }

                case 'W':{
                    if (check==true)
                        direction = 'N';
                    else 
                        direction = 'S';
                    break;
                }

                case 'N':{
                    if (check==true)
                        direction = 'E';
                    else 
                        direction = 'W';
                    break;
                }

                case 'S':{
                    if (check==true)
                        direction = 'W';
                    else 
                        direction = 'E';
                    break;
                }
            }
        }

        void turn(char turn, int value){
            if(value == 90){
                bool check;
                if(turn == 'L')
                    check = false;
                else
                    check = true;
                LR(check);
            }

            if(value == 180){
                switch(direction){
                    case 'N':{
                        direction = 'S';
                        break;
                    }

                    case 'S':{
                        direction = 'N';
                        break;
                    }

                    case 'E':{
                        direction = 'W';
                        break;
                    }

                    case 'W':{
                        direction = 'E';
                        break;
                    }
                }
            }

            if(value == 270){
                bool check;
                if(turn == 'L')
                    check = true;
                else
                    check = false;
                LR(check);               
            }

        }

        void MovingForward(int value){
            switch (direction){
                case 'E':{
                    x+=value;
                    break;
                }

                case 'N':{
                    y+=value;
                    break;
                }

                case 'W':{
                    x=x-value;
                    break;
                }

                case 'S':{
                    y=y-value;
                    break;
                }
            }
        }

        void movement(char action, int value){
            switch(action){
                case 'N':{
                    y+=value;
                    break;
                }

                case 'S':{
                    y=y-value;
                    break;
                }

                case 'E':{
                    x+=value;
                    break;
                }

                case 'W':{
                    x=x-value;
                    break;
                }
            }
        }
};

ship::ship(string path){
    ifstream f;
    f.open(path);
    char action;
    string pom;
    int count = 0;
    int value = 0;

    if(f){
        while(!f.eof()){
            f>>action;
            getline(f, pom);
            value = stoi(pom);
            if(action == 'L' || action == 'R')
                turn(action, value);
            else if(action == 'F')
                MovingForward(value);
            else
                movement(action, value);
        }
        cout<<"\nThe coordinates of the boat:\n";
        if(x >= 0)      
            cout<<"\nEast "<<x;
        else
            cout<<"\nWest "<<-x;
        if(y >= 0)
            cout<<"\nNorth "<<y;
        else
            cout<<"\nSouth "<<-y;

        cout<<"\nFacing "<<direction;

        cout<<"\nManhattan distance: "<<abs(x)+abs(y);

        f.close();
    }
    else
        cout<<"Error!";
}

int main(){
    string path = "navigace.txt";
    ship s = ship(path);
}