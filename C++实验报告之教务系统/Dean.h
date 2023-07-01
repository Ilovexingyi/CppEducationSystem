#ifndef Dean_h
#define Dean_h
#include "Teacher.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Dean :public Teacher
{
private:
	double performance[12];
	double result = 0;
public:
	Dean() :Teacher(), performance{} {
		cout << "Dean constructor..." << endl;
	}
	Dean(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa) : Teacher(n, a, s, t, p, d, wh, hp, sa), performance{} {
		cout << "Dean constructor..." << endl;
	}
	~Dean()
	{
		cout << "Dean destructor..." << endl;
	}
	// ��ֵ���������
	Dean& operator =(const Dean& t) {
		if (this != &t)
		{
			Teacher::operator=(t);
			for (int i = 0; i < 12; i++) {
				performance[i] = t.performance[i];
			}
			result = t.result;
		}
		return *this;
	}
	//�������캯��
	Dean(const Dean& t) : Teacher(t) {
		for (int i = 0; i < 12; i++) {
			performance[i] = t.performance[i];
		}
		result = t.result;
	}
	virtual double getIncome() { return Teacher::getIncome() + getPerformance(); }
	double getPerformance() { for (int i = 0; i < 12; i++) { result += performance[i]; } return result; }
	virtual void inputData() {
		Teacher::inputData();
		setPerformance();
		cout << "���ϵ������Ϣ�ɹ�" << endl;
	}
	void setPerformance() {
		cout << "������������ÿ�¼�Ч���� (double)" << endl;
		try {
			for (int i = 0; i < 12; i++)
			{
				cout << "�������" << i + 1 << "�µļ�Ч����" << endl;
				cin >> performance[i];
				if (cin.fail())
					throw "�������ʹ���������double����";
			}	
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			cout << "���򼴽��˳�" << endl;
			exit(1);
		}
		cout << "���ÿ�¼�Ч��Ϣ�ɹ�" << endl;
	}
	virtual void outData() {
		Teacher::outData();
		cout << "����Ϊϵ����ÿ�¼�Ч���ʣ�" << endl;
		for (int i = 0; i < 12; i++) {
			cout << i + 1 << "�¼�Ч���ʣ�" << performance[i] << "\t";
			if ((i+1) % 3 == 0)
				cout << endl;
		}
	}
	friend ostream& operator<<(ostream& os, Dean& x);
};
ostream& operator<<(ostream& os, Dean& x)
{
	os << static_cast<Teacher&>(x); //ΪTeacher������������������
	os << "����Ϊϵ����ÿ�¼�Ч���ʣ�" << endl;
	for (int i = 0; i < 12; i++) {
		os << i + 1 << "�¼�Ч���ʣ�" << x.performance[i] <<"\t";
		if ((i+1) % 3 == 0)
			os << endl;
	}
	return os;
}
#endif // !Dean_h
