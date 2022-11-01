#include<iostream>
using namespace std;

struct Matrix {
    int** mat;
    int r, c;
};

void delete_data(Matrix* m){
    for(int i = 0; i < m->r; i++)
        delete[] m->mat[i];
    delete[] m->mat;
    m->mat = NULL;
}

void matrix_value(Matrix* m){
    srand(time(0));
    for(int i = 0; i < m->r; i++)
        for(int j = 0; j < m->c; j++)
            m->mat[i][j]= rand() % 10;
}

void show_matrix(Matrix* m){
    for(int i = 0; i < m->r; i++){
        for(int j = 0; j < m->c; j++)
            cout<<m->mat[i][j]<<"\t";
        cout<<"\n";
    }
}

void Form_Matrix(Matrix* m){
    m->mat = new int* [m->r];
    for(int i = 0; i < m->r; i++)
        m->mat[i] = new int[m->c];
}

Matrix* create_matrix(int r, int c){
    Matrix* m = new Matrix;
    m->r = r;
    m->c = c;
    Form_Matrix(m);
    matrix_value(m);
    return m;
}

void plusm(Matrix* M1, Matrix* M2){
    if(M1->r != M2->r || M1->c != M2->c)
        cout<<"Can not calculate sum of two matrix!\n";
    else{
        for(int i = 0; i < M1->r; i++){
            for(int j = 0; j < M1->c; j++)
                cout<<M1->mat[i][j]+M2->mat[i][j]<<"\t";
            cout<<"\n";
        }
    }
}

void multiply(Matrix* M1, Matrix* M2){
    if(M1->c != M2->r)
        cout<<"Can not calculate the multiplication of two matrix!\n";
    else{
        Matrix* M = create_matrix(M1->r, M2->c);
        for(int i = 0; i < M1->r; i++){
            for(int j = 0; j < M2->c; j++){
                M->mat[i][j] = 0;
                for(int k = 0; k < M1->c; k++)
                    M->mat[i][j]+=M1->mat[i][k]*M2->mat[k][j];
                cout<<M->mat[i][j]<<"\t";
            }
            cout<<"\n";
        }
        delete_data(M);
    }
}

int main(){
    /*Matrix 1:*/
    int c1, r1;
    cout<<"Fill in columns and rows of matrix: \n";

    cout<<"Row: ";
    cin>>r1;

    cout<<"Column: ";
    cin>>c1;

    cout<<"\n";
    
    Matrix* M1 = create_matrix(r1,c1);
    
    show_matrix(M1);

    /*Matrix 2:*/

    int c2, r2;
    cout<<"Fill in columns and rows of matrix: \n";

    cout<<"Row: ";
    cin>>r2;

    cout<<"Column: ";
    cin>>c2;

    cout<<"\n";
    
    Matrix* M2 = create_matrix(r2,c2);
    
    show_matrix(M2);

    /*Plus and Multiply*/

    cout<<"\nM1+M2:\n";
    plusm(M1, M2);

    cout<<"\nM1*M2:\n";
    multiply(M1, M2);

    delete_data(M1);
    delete_data(M2);
}