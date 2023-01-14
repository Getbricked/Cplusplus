#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class contact{
public:
    int numbercontact(string path){
        ifstream fs;
        fs.open(path);
        int count = 0;
        string pom;

        while(!fs.eof()){
            getline(fs, pom);
            count++;
        }
        fs.close();
        return count;
    }

    void find(string path, string in){
        ifstream fs;
        fs.open(path);
        int count = numbercontact(path);
        string n[1000], s[1000], p[1000];
        for(int i = 0; i < count; i++){
            getline(fs, s[i], ';');
            getline(fs, n[i], ';');
            getline(fs, p[i]);
        }
        fs.close();
        control:
        int type;
        cout<<"\nChoose type of target:";
        cout<<"\n1>Surname";
        cout<<"\n2>Name";
        cout<<"\n3>Phone number";
        cout<<"\nInput: ";
        cin>>type;
        bool check = false;
        switch(type){
            case 1:
                for(int i = 0; i < count; i++){
                    if(s[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        check = true;
                        break;
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                break;

            case 2:
                for(int i = 0; i < count; i++){
                    if(n[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        break;
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                break;

            case 3:
                for(int i = 0; i < count; i++){
                    if(p[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        break;
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                break;

            default:{
                cout<<"\nInvalid input please choose again!";
                goto control;
            }
        }
    }

    void showcontact(string path){
        ifstream fs;
        fs.open(path);
        int count = numbercontact(path);
        string n[1000], s[1000], p[1000];
        for(int i = 0; i < count; i++){
            getline(fs, s[i], ';');
            getline(fs, n[i], ';');
            getline(fs, p[i]);
        }
        fs.close();

        for(int i = 0; i < count; i++){
            cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
        }
    }

    void del(string path, string in){
        ifstream fs;
        fs.open(path);
        int count = numbercontact(path);
        string n[1000], s[1000], p[1000];
        for(int i = 0; i < count; i++){
            getline(fs, s[i], ';');
            getline(fs, n[i], ';');
            getline(fs, p[i]);
        }
        fs.close();

        fs.open(path);
        string storage[1000];
        for(int i = 0; i < count; i++){
            getline(fs, storage[i]);
        }

        fs.close();
        control:
        int type;
        cout<<"\nChoose type of target:";
        cout<<"\n1>Surname";
        cout<<"\n2>Name";
        cout<<"\n3>Phone number";
        cout<<"\nInput: ";
        cin>>type;
        bool check = false;
        string delcontact;
        switch(type){
            case 1:{
                int pom;
                for(int i = 0; i < count; i++){
                    if(s[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        check = true;
                        pom = i;
                        cout<<"\nThis contact has been deleted from the file!";
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                ofstream rewrite(path);
                for(int i = 0; i < count; i++){
                    if(i != pom){
                        if(i != count - 1)
                            rewrite << storage[i] <<"\n";
                        else
                            rewrite << storage[i];
                    }
                }
                rewrite.close();
                break;
            }

            case 2:{
                int pom;
                for(int i = 0; i < count; i++){
                    if(n[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        check = true;
                        pom = i;
                        cout<<"\nThis contact has been deleted from the file!";
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                ofstream rewrite(path);
                for(int i = 0; i < count; i++){
                    if(i != pom){
                        if(i != count - 1)
                            rewrite << storage[i] <<"\n";
                        else
                            rewrite << storage[i];
                    }
                }
                rewrite.close();
                break;
            }

            case 3:{
                int pom;
                for(int i = 0; i < count; i++){
                    if(p[i] == in){
                        cout<<"\nContact info:\n";
                        cout<<s[i] << "\t\t" << n[i] << "\t\t" << p[i] <<"\n";
                        check = true;
                        pom = i;
                        cout<<"\nThis contact has been deleted from the file!";
                    }
                    if(i == count - 1 && check == false)
                        cout<<"\nNo match could be found!";
                }
                ofstream rewrite(path);
                for(int i = 0; i < count; i++){
                    if(i != pom){
                        if(i != count - 1)
                            rewrite << storage[i] <<"\n";
                        else
                            rewrite << storage[i];
                    }
                }
                rewrite.close();
                break;
            }

            default:{
                cout<<"\nInvalid input please choose again!";
                goto control;
            }
        }
    }


    void add(string s, string n, string p, string path){
        int count = numbercontact(path);
        ifstream fs;
        fs.open(path);
        string storage[1000];
        for(int i = 0; i < count; i++){
            getline(fs, storage[i]);
        }
        storage[count] = s + ";" + n + ";" + p;
        sort(storage, storage + count + 1);
        fs.close();
        
        ofstream rewrite(path);
        for(int i = 0; i < count + 1; i++){
            if(i != count)
                rewrite << storage[i] << "\n";
            else
                rewrite << storage[i];
        }
        rewrite.close();
    }

    contact(string path){
        showcontact(path);
        control :
        int task;
        cout<<"\nChoose task:";
        cout<<"\n1>Add contact";
        cout<<"\n2>Delete contact";
        cout<<"\n3>Find contact";
        cout<<"\n4>Exit";
        cout<<"\nInput: ";
        cin>>task;
        
        switch(task){
            case 1:{
                string s, n, p;

                cout<<"\nSurname: ";
                cin>>s;

                cout<<"\nName: ";
                cin>>n;

                cout<<"\nPhone number: ";
                cin>>p;

                add(s, n, p, path);
                showcontact(path);
                break;
            }
            
            case 2:{
                string target;

                cout<<"\nEnter target: ";
                cin>>target;

                del(path, target);
                break;
            }

            case 3:{
                string target;

                cout<<"\nEnter target: ";
                cin>>target;

                find(path, target);
                break;
            }

            case 4:{
                break;
            }
            default:{
                cout<<"\nInvalid input!";
                goto control;
            }
        }
    }

};

int main(){
    string path;
    cout<<"Input contact file path: ";
    cin>>path;
    contact test(path);
}