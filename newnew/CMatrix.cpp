#include "CMatrix.h"

CMatrix::CMatrix() {
    row = column = 0;
    line = 0L;
    scanLine = 0L;
}

CMatrix::~CMatrix() {
    // Fill in codes here
    for (size_t i = 0; i < this->row; i++)
    {
        delete [] this->scanLine[i];
    }
    delete [] this->scanLine;
}

CMatrix::CMatrix(int row, int column, double init_value) {
    this->row = row;
    this->column = column;
    scanLine = new double *[row];
    scanLine[0] = line = new double[row * column];
    double *p = scanLine[0] + column;
    for (int i = 1; i < row; i++, p += column)
        scanLine[i] = p;
    p = line;
    for (int i = 0, size = row * column; i < size; i++, p++)
        *p = init_value;
}

CMatrix::CMatrix(const CMatrix &right) {
    // Fill in codes here
    this->row = right.row;
    this->column = right.column;
    scanLine = new double *[row];
    scanLine[0] = line = new double[row * column];
    double *p = scanLine[0] + column;
    for (int i = 1; i < row; i++, p += column)
        scanLine[i] = p;
    p = line;
    for (int i = 0, size = row * column; i < size; i++, p++)
        *p = right.line[i];
}

CMatrix &CMatrix::operator+(const CMatrix &right) const {
    // Fill in codes here
    CMatrix &clone = this->clone();
    if (this->row == right.row && this->column == right.column)
    {
        for (int i = 0, size = (row * column); i < size; i++)
            clone.line[i] = this->line[i] + right.line[i];
    }
    return clone;
}

CMatrix &CMatrix::operator-(const CMatrix &right) const {
    // Fill in codes here
    CMatrix &clone = this->clone();
    if (this->row == right.row && this->column == right.column)
    {
        for (int i = 0, size = (row * column); i < size; i++)
            clone.line[i] = this->line[i] - right.line[i];
    }
    return clone;
}

CMatrix &CMatrix::operator-() const {
    // Fill in codes here
    CMatrix &clone = this->clone();
    double *p = clone.line;
    for (int i = 0, size = (row * column); i < size; i++, p++)
        *p *= -1;
    return clone;
}

CMatrix &CMatrix::operator*(const CMatrix &right) const {
    // Fill in codes here
    CMatrix &clone = this->clone();
    if (this->column == right.row)
    {
        CMatrix &product = *new CMatrix(this->row, right.column);
        CMatrix &reverse = ~right;
        double *p = product.line;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < reverse.row; j++)
            {
                double sum {0};
                for (size_t k = 0; k < this->column; k++)
                {
                    sum += this->scanLine[i][k] * reverse.scanLine[j][k];
                }
                *p++ = sum;
            }
        }
        return product;
    }
    return clone;
}

CMatrix &CMatrix::operator/(double scale) const {
    CMatrix &m = this->clone();
    if (scale == 0.0) return m;
    double *p = m.line;
    for (int i = 0, size = (row * column); i < size; i++, p++)
        *p /= scale;
    return m;
}

CMatrix &CMatrix::operator[](int col) const {
    CMatrix &m = *new CMatrix(row, 1);
    double *p = m.line;
    for (int i = 0; i < row; i++, p++)
        *p = scanLine[i][col];
    return m;
}

// returns the column vector
CMatrix &CMatrix::operator~() const {
    // Fill in codes here
    CMatrix &m = *new CMatrix(this->column, this->row);
    for (int i = 0; i < this->row; i++)
    {
        for (int k = 0; k < this->column; k++)
        {
            m(k, i) = this->operator()(i, k);
        }
    }
    return m;
}

// CMatrix transpose
CMatrix &CMatrix::clone() const {
    CMatrix &m = *new CMatrix(*this);
    return m;
}

double &CMatrix::operator()(int r, int c) const {
    // Fill in codes here
        return this->scanLine[r][c];
}

double CMatrix::max() const {
    // Fill in codes here
    double *p = this->line;
    double max {*p};
    for (int i = 0; i < this->row * this->column; i++, p++) 
    {
        if (*p > max)
        {
            max = *p;
        }
    }
    return max;
}

double CMatrix::min() const {
    // Fill in codes here
    double *p = this->line;
    double min {*p};
    for (int i = 0; i < this->row * this->column; i++, p++)
    {
        if (*p < min)
        {
            min = *p;
        }
    }
    return min;
}

ostream &operator<<(ostream &os, const CMatrix &m) {
    os << endl << "row=" << m.row << ",column=" << m.column;
    double *p = m.line;
    for (int i = 0; i < m.row; i++) {
        os << endl;
        for (int j = 0; j < m.column; j++, p++)
            os << *p << " ";
    }
    return os;
}