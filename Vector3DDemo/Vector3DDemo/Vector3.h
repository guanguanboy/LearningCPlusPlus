#ifndef SKELETONDEMO_VECTOR3_H
#define SKELETONDEMO_VECTOR3_H

#include <cmath>

class Vector3
{
public:
	Vector3();//Ĭ�ϵĹ��캯��
	Vector3(const double p);//��������������������ʼ��Ϊһ����
	Vector3(const double v[]);//��һ��double�͵���ֵ��ʼ����ά����
	Vector3(const double x_, const double y_, const double z_);//������double����ֵ��ʼ��������������
	//Vector3(const My3DPoint &p);//��My3DPoint������ά����
								 //	Vector3(const My3DPointWithNormalvector &p);//��My3DPointWithNormalvector��ʼ����ά����
	Vector3(const Vector3 &a); //���ƹ��캯��
	~Vector3(void);//��������
	void SetVector3(const double tempx, const double tempy, const double tempz);//������ά�������������ϵ�����
	double DotProduct(const Vector3 &other)const;//��ά�������  
	void CrossProduct(const Vector3 & l, const Vector3 & r);//��ά�������
	Vector3 CrossProduct(const Vector3 &v)const;//��ά�������
	double magnitude()const;//��������������ƽ���͵ĸ�
	double magnitudeSquared()const;//��������������ƽ����
	void normalize();//������һ��
	double Distance(const Vector3 &a, const Vector3 &b);//��������֮��ľ���
	double Distance(const Vector3 &v)const;//��������֮��ľ���
	void SetZero();//��Ϊ0����
	void Vector3Max(const Vector3 &v);//����ǰ������v��xyz�����Ƚϵõ��ϴ����
	void Vector3Min(const Vector3 &v);//����ǰ������v��xyz�����Ƚϵõ���С����
	void  setNegative(const Vector3 &v);//���β�����vȡ����ֵ����ǰ����
	void  setNegative();//����ǰ����ȡ��
	void  add(const Vector3 & a, const Vector3 & b);//����ǰ��������Ϊa��b�����ĺ�
	void subtract(const Vector3 &a, const Vector3 &b);//����ǰ��������Ϊa��b�����Ĳ�
	void multiply(double s, const Vector3 & a);//����ǰ��������Ϊ����s������a������
	void  arrayMultiply(const Vector3 &a, const Vector3 &b);//����ǰ��������Ϊ����a������b���������ĳ˻�


															  // BOOL�Ͳ�������� 
	bool operator == (const Vector3& v) const //�ж����������Ƿ����
	{
		return x == v.x && y == v.y && z == v.z;
	}
	bool operator != (const Vector3& v) const //�ж����������Ƿ����
	{
		return x != v.x || y != v.y || z != v.z;
	}
	// ����������� 
	Vector3& operator = (const Vector3 &v) //��ֵ����
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	Vector3  operator +  (const Vector3 &v) const//�����������
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	Vector3& operator += (const Vector3 &v) //�����������
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Vector3  operator -  () const //����ȡ��
	{
		return Vector3(-x, -y, -z);
	}
	Vector3  operator -(const Vector3 &v) const //�����������
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	Vector3& operator -= (const Vector3 &v)  //�����������  
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	Vector3  operator *  (const double s) const  //�������� 
	{
		return Vector3(x*s, y*s, z*s);
	}
	Vector3& operator *= (const double s)     //��������   
	{
		x *= s; y *= s; z *= s;
		return *this;
	}
	Vector3  operator /  (const double s) const  //��������һ����
	{
		//ASSERT(s);
		return (*this)* (1 / s);
	}
	Vector3& operator /= (const double s)   //��������һ����
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
	double x, y, z;//xyz���������Ĵ�С
};

inline Vector3 operator *(const double s, const Vector3 &v)//��������  ����ǰ��һ����
{
	return Vector3(s*v.x, s*v.y, s*v.z);
}

#endif // !SKELETONDEMO_VECTOR3_H
