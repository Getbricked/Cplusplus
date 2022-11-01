#include <iostream>
using namespace std;

void print_matice(int** m, int row, int col){
    srand(time(0));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
                cout<<m[i][j]<<"\t";
        cout<<"\n";
    }
}

void dealocation(int** m, int row){
    for (int i = 0; i < row; i++)
        delete[] m[i];
    delete[] m;
    m = NULL;
}

int main(){
    srand(time(0));
    /*Zadej Row/Column pro Matice 1 a zobrat*/
    int row1,col1;
    cout<<"Matice 1: \n";
    cout<<"Row = ";
    cin>>row1;
    cout<<"\nCol = ";
    cin>>col1;
    cout<<"\n";

    /*Create a multidimensional array m1 with pointers*/
    int** m1 = new int*[row1];
    for(int i = 0; i < row1; i++)
        m1[i] = new int[col1];

    /*Give value for each m1[i][j] in array m1*/
    for(int i = 0; i < row1; i++)
        for(int j = 0; j < col1; j++)
            m1[i][j] = rand()%10;
    
    cout<<"\nMatice 1 :\n";
    print_matice(m1, row1, col1);

    /*Zadej Row/Column pro Matice 2 a zobrat*/
    int row2,col2;
    cout<<"\n\nMatice 2: \n";
    cout<<"Row = ";
    cin>>row2;
    cout<<"\nCol = ";
    cin>>col2;
    cout<<"\n";

    /*Create a multidimensional array m2 with pointers*/
    int** m2 = new int*[row2];
    for(int i = 0; i < row2; i++)
        m2[i] = new int[col2];
    
    /*Give value for each m2[i][j] in array m2*/
    for(int i = 0; i < row2; i++)
        for(int j = 0; j < col2; j++)
            m2[i][j] = rand()%10;
    cout<<"\nMatice 2 :\n";
    print_matice(m2, row2, col2);

    /*Plus m1 + m2*/
    if(row1==row2 && col1==col2){
        cout<<"Matice 1 + Matice 2:\n";
        for(int i = 0; i < row1; i++){
            for(int j = 0; j < col1; j++)
                cout<<m1[i][j] + m2[i][j] <<"\t";
            cout<<endl;
        }
    }
    else
        cout<<"\nNemuzeme pocitat matice m1 + matice m2!\n";

    /*Multiply m1 and m2*/
    int pom;
    int** m = new int*[row1];
    for(int i = 0; i < row1; i++)
        m[i] = new int[col2];
    if(col1 == row2){
        for(int i = 0; i < row1; i++){
            for(int j = 0; j < col2; j++){
                m[i][j]=0;
                for(int k = 0; k < col1; k++)
                    m[i][j] += m1[i][k]*m2[k][j];
            }
        }
        cout<<"\nMatice m1 * m2:\n";
        print_matice (m, row1, col2);
    }

    else
        cout<<"\nNemuzeme pocitat matice m1 * matice m2!\n";
    /*dealocation*/
    dealocation(m1, row1);
    dealocation(m2, row2);
}