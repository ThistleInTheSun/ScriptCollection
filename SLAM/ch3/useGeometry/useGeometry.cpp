#include <iostream>
#include <cmath>
using namespace std;

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;

int main(int argc, char **argv) {

    Matrix3d rotation_matrix = Matrix3d::Identity();
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));
    cout.precision(3);
    cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();

    // 用旋转向量
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1, 0, 0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;

    // 用旋转矩阵
    v_rotated = rotation_matrix * v;
    cout << "(1, 0, 0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // 将旋转矩阵转换成欧拉角，ZYX顺序
    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    // 欧式变换矩阵
    Isometry3d T = Isometry3d::Identity();
    T.rotate(rotation_vector);  // 按照rotation_vector进行旋转
    T.pretranslate(Vector3d(1, 3, 4));  // 平移向量
    cout << "Transform matrix = \n" << T.matrix() << endl;

    // 用欧式变换矩阵进行坐标变换
    Vector3d v_transformed = T * v;
    cout << "v tranformed = " << v_transformed.transpose() << endl;
    // 仿射变换可用 Eigen::Affine3d
    // 射影变换可用 Eigen::Projective3d

    // 四元数
    // 把AngleAxis赋值给四元数
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl;
    // 把旋转矩阵赋值给四元数
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;
    // 用四元数旋转一个向量
    v_rotated = q * v;  // 注意数学上是 qvq^{-1}
    cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << endl;
    // 用常规向量乘法计算
    cout << "shoule be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}