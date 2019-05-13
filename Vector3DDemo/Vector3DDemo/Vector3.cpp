#include "Vector3.h"



Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

//将向量的三个分量都初始化为一个数
Vector3::Vector3(const double p)
{
	x = p;
	y = p;
	z = p;
}

//用一个double型的数组初始化三维向量
Vector3::Vector3(const double v[]) :x(v[0]), y(v[1]), z(v[2])
{

}
//三个double型的数值分别初始化x,y,z三个分量
Vector3::Vector3(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_)
{

}
//复制构造函数
Vector3::Vector3(const Vector3 &a) {
	x = a.x;
	y = a.y;
	z = a.z;
}
//以My3DPoint结构体作为参数构造向量
//Vector3::Vector3(const My3DPoint &p)
//{
//	x = p.X;
//	y = p.Y;
//	z = p.Z;
//}

////以My3DPointWithNormalvector结构体作为参数构造向量
//Vector3::Vector3(const My3DPointWithNormalvector &p)
//{
//	x=p.zuobiao.X;
//	y=p.zuobiao.Y;
//	z=p.zuobiao.Z;
//}

//默认析构函数
//Vector3::~Vector3(void)
//{
//
//}

//设置向量的XYZ坐标
void Vector3::SetVector3(const double tempx, const double tempy, const double tempz)
{
	x = tempx;
	y = tempy;
	z = tempz;
}

//两向量的点积
double Vector3::DotProduct(const Vector3 &other)const
{
	return x * other.x + y * other.y + z * other.z;
}

//两向量的叉积
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

//三个向量分量平方和的根
double Vector3::magnitude()const
{
	return sqrt(x * x + y * y + z * z);
}

//三个向量分量的平方和
double Vector3::magnitudeSquared()const
{
	return x * x + y * y + z * z;
}
//向量标准化
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

//两个向量之间的距离
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

//将三维向量置为0向量
void  Vector3::SetZero()
{
	x = 0;
	y = 0;
	z = 0;
}

//将当前向量与v的XYZ分量相比，得到较大的xyz分量
void Vector3::Vector3Max(const Vector3 &v)
{
	x = x>v.x ? x : v.x;
	y = y>v.y ? y : v.y;
	z = z>v.z ? z : v.z;
}

//将当前向量与v的XYZ分量相比，得到较大的xyz分量
void Vector3::Vector3Min(const Vector3 &v)
{
	x = x<v.x ? x : v.x;
	y = y<v.y ? y : v.y;
	z = z<v.z ? z : v.z;
}

//将形参向量v取负赋值给当前向量
void  Vector3::setNegative(const Vector3 &v)
{
	x = -v.x;
	y = -v.y;
	z = -v.z;
}
//将当前向量取负
void  Vector3::setNegative()
{
	x = -x;
	y = -y;
	z = -z;
}
//将当前向量设置为a和b向量的和
void  Vector3::add(const Vector3 & a, const Vector3 & b)
{
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
}

//将当前向量设置为a和b向量的差
void Vector3::subtract(const Vector3 &a, const Vector3 &b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
}

//将当前向量设置为数字s与向量a的数乘
void Vector3::multiply(double s, const Vector3 & a)
{
	x = a.x * s;
	y = a.y * s;
	z = a.z * s;
}

//将当前向量设置为向量a与向量b各个分量的乘积
void  Vector3::arrayMultiply(const Vector3 &a, const Vector3 &b)
{
	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.y;
}