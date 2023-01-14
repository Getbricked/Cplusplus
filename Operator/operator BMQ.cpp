#include<iostream>
using namespace std;

class matice{
private:
    int row;
    int col;
    int** M;
public:
    void genmatice(int r, int c){
        row = r;
        col = c;
        M = new int*[r];
        for(int i = 0; i < r; i++){
            M[i] = new int[c];
        }
    };

    matice randmatice(int r, int c){
        srand(time(0));
        matice m;
        m.genmatice(r, c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++)
                m.M[i][j] = rand() % 10;
        }
        return m;
    };

    friend ostream& operator<<(ostream& os, const matice& m){
        for (int i = 0; i < m.row; i++){
            for (int j = 0; j < m.col; j++){
                os<<m.M[i][j]<<"\t";
            }
            os<<endl;
        }
        return os;
    };

    matice operator - (matice& m){
        matice mat;
        mat.genmatice(m.row, m.col);
        for(int i = 0; i < m.row; i++){
            for(int j = 0; j < m.col; j++){
                mat.M[i][j] = M[i][j] - m.M[i][j];
            }
        }
        return mat;
    };

    matice operator + (matice& m){
        matice mat;
        mat.genmatice(m.row, m.col);
        for(int i = 0; i < m.row; i++){
            for(int j = 0; j < m.col; j++){
                mat.M[i][j]= M[i][j] + m.M[i][j];
            }
        }
        return mat;
    };

    matice operator * (matice& m){
        matice mat;
        mat.genmatice(row, m.col);
        int pom;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < m.col; j++){
                mat.M[i][j] = 0;
                for(int k = 0; k < col; k++)
                    mat.M[i][j] += M[i][k] * m.M[k][j];
            }
        }
        return mat;
    }

    void deldata(){
    for(int i = 0; i < row; i++)
        delete[] M[i];
    delete[] M;
    M = NULL;
}
};

int main(){
    int r1, c1;
    cout<<"\nMatice 1:\n";
    cout<<"\nRadek: ";
    cin>>r1;
    cout<<"\nSloupec: ";
    cin>>c1;
    cout<<endl;
    matice m1;
    m1 = m1.randmatice(r1, c1);
    cout<<m1;

    int r2, c2;
    cout<<"\nMatice 2:\n";
    cout<<"\nRadek: ";
    cin>>r2;
    cout<<"\nSloupec: ";
    cin>>c2;
    cout<<endl;
    matice m2;
    m2 = m2.randmatice(r2, c2);
    cout<<m2;

    if(r1 == r2 && c1 == c2){
        cout<<"\nMatice 1 + Matice 2:\n";
        cout<<m1 + m2;
        cout<<"\nMatice 1 - Matice 2:\n";
        cout<<m1 - m2;
    }
    else
        cout<<"\nNemuzeme pocitat matice 1 + matice 2 nebo matice 1 - matice 2!\n";
    
    cout<<"\n";

    if(c1 == r2){
        cout<<"\nMatice 1 * Matice 2:\n";
        cout<<m1 * m2;
    }
    else
        cout<<"\nNemuzeme pocitat matice 1 * matice 2!\n";
    m1.deldata();
    m2.deldata();
}