#include "Vector3.h"



Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

//��������������������ʼ��Ϊһ����
Vector3::Vector3(const double p)
{
	x = p;
	y = p;
	z = p;
}

//��һ��double�͵������ʼ����ά����
Vector3::Vector3(const double v[]) :x(v[0]), y(v[1]), z(v[2])
{

}
//����double�͵���ֵ�ֱ��ʼ��x,y,z��������
Vector3::Vector3(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_)
{

}
//���ƹ��캯��
Vector3::Vector3(const Vector3 &a) {
	x = a.x;
	y = a.y;
	z = a.z;
}
//��My3DPoint�ṹ����Ϊ������������
//Vector3::Vector3(const My3DPoint &p)
//{
//	x = p.X;
//	y = p.Y;
//	z = p.Z;
//}

////��My3DPointWithNormalvector�ṹ����Ϊ������������
//Vector3::Vector3(const My3DPointWithNormalvector &p)
//{
//	x=p.zuobiao.X;
//	y=p.zuobiao.Y;
//	z=p.zuobiao.Z;
//}

//Ĭ����������
//Vector3::~Vector3(void)
//{
//
//}

//����������XYZ����
void Vector3::SetVector3(const double tempx, const double tempy, const double tempz)
{
	x = tempx;
	y = tempy;
	z = tempz;
}

//�������ĵ��
double Vector3::DotProduct(const Vector3 &other)const
{
	return x * other.x + y * other.y + z * other.z;
}

//�������Ĳ��
void Vector3::CrossProduct(const Vector3 & l, const Vector3 & r)
{
	double a = (l.y * r.z) - (l.z * r.y);
	double b = (l.z * r.x) - (l.x * r.z);
	double c = (l.x * r.y) - (l.y * r.x);

	x = a;
	y = b;
	z = c;
}
Vector3 Vector3::CrossProduct(const Vector3 &v)const
{
	Vector3 temp;
	temp.CrossProduct(*this, v);
	return temp;
}

//������������ƽ���͵ĸ�
double Vector3::magnitude()const
{
	return sqrt(x * x + y * y + z * z);
}

//��������������ƽ����
double Vector3::magnitudeSquared()const
{
	return x * x + y * y + z * z;
}
//������׼��
void Vector3::normalize()
{
	double m = magnitude();
	if (m)
	{
		const double il = double(1.0) / m;
		x *= il;
		y *= il;
		z *= il;
	}
}

//��������֮��ľ���
double Vector3::Distance(const Vector3 &a, const Vector3 &b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	double dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double Vector3::Distance(const Vector3 &v)const
{
	Vector3 tempObject;
	double dis;
	dis = tempObject.Distance(*this, v);
	return dis;
}

//����ά������Ϊ0����
void  Vector3::SetZero()
{
	x = 0;
	y = 0;
	z = 0;
}

//����ǰ������v��XYZ������ȣ��õ��ϴ��xyz����
void Vector3::Vector3Max(const Vector3 &v)
{
	x = x>v.x ? x : v.x;
	y = y>v.y ? y : v.y;
	z = z>v.z ? z : v.z;
}

//����ǰ������v��XYZ������ȣ��õ��ϴ��xyz����
void Vector3::Vector3Min(const Vector3 &v)
{
	x = x<v.x ? x : v.x;
	y = y<v.y ? y : v.y;
	z = z<v.z ? z : v.z;
}

//���β�����vȡ����ֵ����ǰ����
void  Vector3::setNegative(const Vector3 &v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
}
//����ǰ����ȡ��
void  Vector3::setNegative()
{
	x = -x;
	y = -y;
	z = -z;
}
//����ǰ��������Ϊa��b�����ĺ�
void  Vector3::add(const Vector3 & a, const Vector3 & b)
{
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
}

//����ǰ��������Ϊa��b�����Ĳ�
void Vector3::subtract(const Vector3 &a, const Vector3 &b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
}

//����ǰ��������Ϊ����s������a������
void Vector3::multiply(double s, const Vector3 & a)
{
	x = a.x * s;
	y = a.y * s;
	z = a.z * s;
}

//����ǰ��������Ϊ����a������b���������ĳ˻�
void  Vector3::arrayMultiply(const Vector3 &a, const Vector3 &b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.y;
}