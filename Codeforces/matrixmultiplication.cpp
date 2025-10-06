// A. Matrix Multiplications. Link to problem: https://codeforces.com/gym/637457/problem/A 
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix; //Solving problems with Matrix
 
Matrix add(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
 
Matrix substract(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), vector<int>(A.size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
 
Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
 
Matrix strassen(const Matrix &A, const Matrix &B, int threshold = 64) {
    
    int n = A.size(); //only square power of 2
    int half = n / 2; //division of matrix into 4 submatrices with 1/4 size and half being index of both half rows and columns
 
    if (n <= threshold) {
        return multiply(A, B);
    }
 
    Matrix A11(half, vector<int>(half));
    Matrix A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half));
    Matrix A22(half, vector<int>(half));
 
    Matrix B11(half, vector<int>(half));
    Matrix B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half));
    Matrix B22(half, vector<int>(half));
 
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            
            A11[i][j] = A[i][j];                 B11[i][j] = B[i][j];  
            A12[i][j] = A[i][j + half];          B12[i][j] = B[i][j + half];
            A21[i][j] = A[i + half][j];          B21[i][j] = B[i + half][j]; 
            A22[i][j] = A[i + half][j + half];   B22[i][j] = B[i + half][j + half];
        }
    }
 
    Matrix M1 = strassen(add(A11, A22), add(B11, B22), threshold);
    Matrix M2 = strassen(add(A21, A22), B11, threshold);
    Matrix M3 = strassen(A11, substract(B12, B22), threshold);
    Matrix M4 = strassen(A22, substract(B21, B11), threshold);
    Matrix M5 = strassen(add(A11, A12), B22, threshold);
    Matrix M6 = strassen(substract(A21, A11), add(B11, B12), threshold);
    Matrix M7 = strassen(substract(A12, A22), add(B21, B22), threshold);
 
    Matrix C11 = add(substract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(substract(M1, M2), add(M3, M6));
 
    Matrix C(n, vector<int>(n));
 
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j]; 
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];           
        }
    }
    return C;
}
 
void solve() {
    int n; //n is guaranteed to be a power of 2 -> all submatrices will be square
    cin >> n;
    Matrix A(n, vector<int>(n)); //n arrays of n (int) size
    Matrix B(n, vector<int>(n));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
 
    Matrix ans = strassen(A, B);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
 
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   
   solve();
}
