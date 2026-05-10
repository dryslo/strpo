#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
    int m;
    int n;
    double** data;
    public:
    Matrix(int n);
    Matrix(int m, int n, double fill_value = 0);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    double get(int i, int j) const;
    void set(int i, int j, double value);
    int get_height() const;
    int get_width() const;
    void negate();
    void add_in_place(const Matrix &other);
    Matrix multiply(const Matrix &other);
    void m_free();
    ~Matrix();
};

#endif