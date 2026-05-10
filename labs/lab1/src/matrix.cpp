#include "matrix.hpp"
Matrix::Matrix(int n){
    if(n<=0) throw "invalid matrix size";
    data = new double*[n];
    this->m = n;
    this->n = n;
    for(int i = 0; i< n;i++){
        data[i] = new double[n]();
        data[i][i] = 1;
    }
}

Matrix::Matrix(int m, int n, double fill_value){
    if(n<=0 || m<=0) throw "invalid matrix size";
    this->m = m;
    this->n = n;
    data = new double*[m];
    for(int i = 0; i< m;i++){
        data[i] = new double[n];
        for(int j = 0; j<n;j++){
            data[i][j] = fill_value;
        }
    }
}

Matrix::Matrix(const Matrix& other){
    m = other.m;
    n = other.n;
    data = new double*[m];
    for(int i = 0; i< m;i++){
        data[i] = new double[n];
        for(int j = 0; j<n;j++){
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other){
    if(this==&other) return *this;
    if(data!=nullptr && (m!=other.m || n!=other.n)){
        m_free();
        m = other.m;
        n = other.n;
        data = new double*[m];
        for(int i = 0; i<m;i++){
            data[i] = new double[n];
        }
    }
    for(int i = 0; i< m;i++){
        for(int j = 0; j<n;j++){
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

double Matrix::get(int i, int j) const{
    if (i<0 || i>=m || j>=n || j<0){
        throw "index out of range";
    }
    return data[i][j];
}

void Matrix::set(int i, int j,double value){
    if (i<0 || i>=m || j>=n || j<0){
        throw "index out of range";
    }
    data[i][j] = value;
}

int Matrix::get_height() const{
    return m;
}

int Matrix::get_width() const{
    return n;
}

void Matrix::negate(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            data[i][j] = -data[i][j];
        }
    }
}

void Matrix::add_in_place(const Matrix &other){
    if(n!=other.n || m!=other.m){
        throw "size combination error";
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            data[i][j] += other.data[i][j];
        }
    }
}

Matrix Matrix::multiply(const Matrix &other){
    if(n!=other.m){
        throw "size combination error";
    }
    Matrix dst(m,other.n);
    for(int i = 0;i < dst.m; i++){
        for(int j = 0; j< dst.n; j++){
            for(int k = 0; k < n;k++){
                dst.data[i][j]+=data[i][k]*other.data[k][j];
            }
        }
    }
    return dst;
}
void Matrix::m_free(){
    if (data == nullptr) {
            return;
        }
        for(int i = 0;i<m;i++){
            delete[] data[i];
        }
        delete[] data;
        data=nullptr;
}
Matrix::~Matrix(){
    m_free();
}