#include <iostream>
#include <string>

using namespace std;

class Date
{
	string month;
	int day, year;
	int personID;

public:
	Date(string m, int d, int y, int id) :month(m), day(d), year(y), personID(id)
	{
		cout << "Date-Of-Birth object for person " << personID << " has been created.\n";
	}

	~Date()
	{
		cout << "Date-Of-Birth object for person " << personID << " has been destroyed.\n";
	}
};

class Country
{
	string name;
public:
	Country(string name) : name(name)
	{
		cout << "A country object has been created.\n";
	}

	~Country()
	{
		cout << "A country object has been destroyed.\n";
	}
};

class Person
{
	string name;
	Date dateOfBirth;
	int personID; //Person identification number
	shared_ptr<Country> pCountry;

public:
	static int uniquePersonID;

public:
	Person(string name, string month, int day, int year, shared_ptr<Country>& pC) :
		name(name), dateOfBirth(month, day, year, Person::uniquePersonID), personID(Person::uniquePersonID),
		pCountry(pC)
	{
		cout << "Person object" << personID << " has been created.\n";
		Person::uniquePersonID++;
	}

	~Person()
	{
		cout << "Person object" << personID << " has been destroyed. \n";
	}
};

int Person::uniquePersonID = 1;

int main()
{
	shared_ptr<Country> p_usa = make_shared<Country>("USA");

	shared_ptr<Person> p = make_shared<Person>("Peter Lee", "January", 1, 1985, p_usa);

	shared_ptr<Person> p1 = make_shared<Person>("Eva Gustafson", "May", 15, 1992, p_usa);

	cout << "Now there are two people.\n";

	//system("pause");

	return 0;
}

/*
demo ˵��:
	dateOfBirth ����Ͱ������ǵ�Person����֮��Ĺ�ϵʱ��ϵ�һ�����ӡ��ӳ����������п��Կ�������ЩDate�������Ӧ��Person
	������ͬʱ�����ģ���ӵ�����ǵ�Person����ͬʱ���١������˵��Person �� Country֮��Ĺ�ϵ�����˵�Ǹ���ͨ�ľۺ���ʽ��
*/