#include <iostream>
using namespace std;

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char **argv) {
    // 各种初始化
    Matrix<float, 2, 3> matrix_23;
    cout << matrix_23 << endl;
    Vector3d v_3d;
    Matrix<float, 3, 1> vd_3d;
    Matrix3d matrix_33 = Matrix3d::Zero();
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    MatrixXd matrix_x;

    // 赋值
    matrix_23 << 1, 2, 3, 4, 5, 6;
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    // 操作
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << result << endl;
    cout << result2 << endl;

    matrix_33 = Matrix3d::Random();
    cout << matrix_33 << endl;
    
    matrix_33 << 1, 0, 0, 0, 2, 0, 0, 0, 3;
    matrix_33.transpose();
    matrix_33.sum();
    matrix_33.trace();
    matrix_33.inverse();
    10 * matrix_33;
    matrix_33.determinant();

    // 特征值、特征向量
    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    eigen_solver.eigenvalues();
    eigen_solver.eigenvectors();

    // 解方程
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);
    Matrix<double, MATRIX_SIZE, 1> x;
    clock_t time_stt;
    // 直接求逆     6.1ms
    time_stt = clock();
    x = matrix_NN.inverse() * v_Nd;
    cout << "time:" << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << endl;
    // QR分解       4.5ms
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time:" << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << endl;
    // cholesky分解(需要正定)   1.3ms
    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << "time:" << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << endl;

    // cout << eigen_solver.eigenvectors() << endl;
}