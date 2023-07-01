#ifndef Chancellor_h
#define Chancellor_h
#include "Teacher.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Chancellor :public Teacher
{
private:
    double yearsalary = 0;
    double salary = 0;
public:
    Chancellor() {}
    Chancellor(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa, double ys) :Teacher(n,a,s,t,p,d,wh,hp,sa), yearsalary(ys) { cout << "Chancelllor constructor..." << endl; }
    ~Chancellor()
    {
        cout << "Chancellor destructor..." << endl;
    }
    //��ֵ���������
    Chancellor& operator=(const Chancellor& t)
    {
        if (this != &t)
        {
            Teacher::operator=(t);
            yearsalary = t.yearsalary;

        }
        return *this;
    }
    virtual double getIncome() { return Teacher::getIncome() + yearsalary; }
    virtual void setSalary(double s) { salary = s; }
    virtual double getSalary() { return salary; }
    //�������캯��
    Chancellor(const Chancellor& t)
    {
        Teacher::operator=(t);
        yearsalary = t.yearsalary;
    }
    virtual void inputData()
    {
        Teacher::inputData();
        try
        {
            cout << "������Ժ����н (double)" << endl;
            cin >> yearsalary;
            if(cin.fail())
                throw "�������ʹ���������double����"; // ����������ʹ����׳��쳣
        }
        catch (const char* msg)
        {
            cout << msg << endl;
            cout << "���򼴽��˳�" << endl;
            exit(1);
        }
         cout << "���Ժ����н��Ϣ�ɹ�" << endl;
    }
    virtual void outData()
    {
        Teacher::outData();
        cout << "Ժ����н��" << yearsalary << endl;
      
    }
    friend ostream& operator<<(ostream& os, Chancellor& x);
};
ostream& operator<<(ostream& os, Chancellor& x)
{
	os << static_cast<Teacher&>(x); //ΪTeacher������������������
	os << "Ժ����н��" << x.yearsalary << endl;
	return os;
}
#endif
