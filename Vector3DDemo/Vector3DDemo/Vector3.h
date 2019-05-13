#ifndef SKELETONDEMO_VECTOR3_H
#define SKELETONDEMO_VECTOR3_H

#include <cmath>

class Vector3
{
public:
	Vector3();//默认的构造函数
	Vector3(const double p);//将向量的三个分量都初始化为一个数
	Vector3(const double v[]);//以一个double型的数值初始化三维向量
	Vector3(const double x_, const double y_, const double z_);//以三个double型数值初始化向量三个分量
	//Vector3(const My3DPoint &p);//用My3DPoint构造三维向量
								 //	Vector3(const My3DPointWithNormalvector &p);//用My3DPointWithNormalvector初始化三维向量
	Vector3(const Vector3 &a); //复制构造函数
	~Vector3(void);//析构函数
	void SetVector3(const double tempx, const double tempy, const double tempz);//设置三维向量三个方向上的坐标
	double DotProduct(const Vector3 &other)const;//三维向量点积  
	void CrossProduct(const Vector3 & l, const Vector3 & r);//三维向量叉积
	Vector3 CrossProduct(const Vector3 &v)const;//三维向量叉积
	double magnitude()const;//三个向量分量的平方和的根
	double magnitudeSquared()const;//三个向量分量的平方和
	void normalize();//向量归一化
	double Distance(const Vector3 &a, const Vector3 &b);//两个向量之间的距离
	double Distance(const Vector3 &v)const;//两个向量之间的距离
	void SetZero();//置为0向量
	void Vector3Max(const Vector3 &v);//将当前向量与v的xyz分量比较得到较大分量
	void Vector3Min(const Vector3 &v);//将当前向量与v的xyz分量比较得到较小分量
	void  setNegative(const Vector3 &v);//将形参向量v取负赋值给当前向量
	void  setNegative();//将当前向量取负
	void  add(const Vector3 & a, const Vector3 & b);//将当前向量设置为a和b向量的和
	void subtract(const Vector3 &a, const Vector3 &b);//将当前向量设置为a和b向量的差
	void multiply(double s, const Vector3 & a);//将当前向量设置为数字s与向量a的数乘
	void  arrayMultiply(const Vector3 &a, const Vector3 &b);//将当前向量设置为向量a与向量b各个分量的乘积


															  // BOOL型操作运算符 
	bool operator == (const Vector3& v) const //判断两个向量是否相等
	{
		return x == v.x && y == v.y && z == v.z;
	}
	bool operator != (const Vector3& v) const //判断两个向量是否不相等
	{
		return x != v.x || y != v.y || z != v.z;
	}
	// 常见的运算符 
	Vector3& operator = (const Vector3 &v) //赋值运算
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	Vector3  operator +  (const Vector3 &v) const//两个向量相加
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	Vector3& operator += (const Vector3 &v) //两个向量相加
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Vector3  operator -  () const //向量取反
	{
		return Vector3(-x, -y, -z);
	}
	Vector3  operator -(const Vector3 &v) const //两个向量相减
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	Vector3& operator -= (const Vector3 &v)  //两个向量相减  
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	Vector3  operator *  (const double s) const  //向量数乘 
	{
		return Vector3(x*s, y*s, z*s);
	}
	Vector3& operator *= (const double s)     //向量数乘   
	{
		x *= s; y *= s; z *= s;
		return *this;
	}
	Vector3  operator /  (const double s) const  //向量除以一个数
	{
		//ASSERT(s);
		return (*this)* (1 / s);
	}
	Vector3& operator /= (const double s)   //向量除以一个数
	{
		//ASSERT(s); return (*this) *= (1 / s);
	}
	bool operator< (const Vector3&v) const
	{
		if (x < v.x)	return true;
		if (x > v.x)	return false;
		if (y < v.y)	return true;
		if (y > v.y)	return false;
		if (z < v.z)	return true;
		if (z > v.z)	return false;
		return false;
	}
public:
	double x, y, z;//xyz三个分量的大小
};

inline Vector3 operator *(const double s, const Vector3 &v)//内联函数  向量前乘一个数
{
	return Vector3(s*v.x, s*v.y, s*v.z);
}

#endif // !SKELETONDEMO_VECTOR3_H
