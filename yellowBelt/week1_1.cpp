#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
private:
  int row;
  int col;
  vector<vector<int>> v;
public:
  Matrix(){
    row = 0;
    col = 0;
  }

  Matrix(int num_rows, int num_cols){
    Reset(num_rows, num_cols);
  }

  void Reset(int r, int c) {
    if (r < 0) {
      throw out_of_range("rows must be >= 0");
    }
    if (c < 0) {
      throw out_of_range("columns must be >= 0");
    }
    if (r == 0 || c == 0) {
      r = c = 0;
    }
    row = r;
    col = c;
    v.assign(r, vector<int>(c));
  }


  int At(int r, int c) const{
    return v.at(r).at(c);
  }

  int& At(int r, int c) {
    return v.at(r).at(c);
  }

  int GetNumRows() const{
    return row;
  }

  int GetNumColumns() const{
    return col;
  }
};

bool operator== (const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows() ||
  lhs.GetNumColumns() != rhs.GetNumColumns()) return false;

  for (int i = 0;   i < lhs.GetNumRows(); ++i) {
    for(int j = 0; j < rhs.GetNumColumns(); ++j) {
      if(lhs.At(i, j) != rhs.At(i, j)) return false;
    }
  }
  return true;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows())
    throw invalid_argument("Mismatched number of rows");
  if (lhs.GetNumColumns() != rhs.GetNumColumns())
    throw invalid_argument("Mismatched number of columns");
  Matrix out;
  out.Reset(lhs.GetNumRows(), rhs.GetNumColumns());

  for (int i = 0;   i < lhs.GetNumRows(); ++i) {
    for(int j = 0; j < rhs.GetNumColumns(); ++j) {
      out.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }
  return out;
}

ostream& operator<< (ostream& stream, const Matrix& m) {
  stream << m.GetNumRows() << " " << m.GetNumColumns() << '\n';
  for (int i = 0;   i < m.GetNumRows(); ++i) {
    for(int j = 0; j < m.GetNumColumns(); ++j) {
      stream << m.At(i, j);
      if(j + 1 < m.GetNumColumns()) stream << ' ';
    }
    stream << '\n';
  }
  return stream;
}

istream& operator>> (istream& stream, Matrix& m) {
  int r, c;
  stream >> r >> c;
  m.Reset(r, c);
  for (int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      stream >> m.At(i,j);
    }
  }
  return stream;
}


int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;


  return 0;
}
