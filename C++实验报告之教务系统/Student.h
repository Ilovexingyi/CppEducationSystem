#include "Person.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"Teacher.h"
#ifndef Student_h
#define Student_h
using namespace std;
class Student :public Person
{
private:
	int sid = 0;
	int classX = 0;
	double chinese = 0;
	double english = 0;
	double math = 0;
	map<int, string> advisors;
	int advisorId;
	string advisorName;

public:
	int getSid() { return sid; }
	void setAdvisorId(int id) { advisorId = id; }
	void setAdvisorName(string name) { advisorName = name; }
	Student() {  }
	Student(string n, int a, char s, int si, int c, double ch, double m, double e) :Person(n, a, s), sid(si), classX(c), chinese(ch), math(m), english(e) {cout << "Student constructor..." << endl; }
	~Student()
	{
		cout << "Student destructor..." << endl;
		
	}
	// ��ֵ���������
	Student& operator =(const Student& s) {
		if (this != &s)
		{
			Person::operator=(s);
			sid = s.sid;
			classX = s.classX;
			chinese = s.chinese;
			math = s.math;
			english = s.english;

		}
		return *this;
	}
	//�������캯��
	Student(const Student& s) :Person(s) {
		sid = s.sid;
		classX = s.classX;
		chinese = s.chinese;
		math = s.math;
		english = s.english;
	}
	virtual void inputData() {
		Person::inputData();
		try {
			cout << "������ѧ����� (int)" << endl;
			cin >> sid;
			if (cin.fail()) {
				throw  "�������ʹ���������int����"; // ����������ʹ����׳��쳣
			}
			cout << "������༶��� (int)" << endl;
			cin >> classX;
			if (cin.fail()) {
				throw  "�������ʹ���������int����"; // ����������ʹ����׳��쳣
			}
			cout << "���������ĳɼ� (double)" << endl;
			cin >> chinese;
			if (cin.fail()) {
				throw "�������ʹ���������double����"; // ����������ʹ����׳��쳣
			}
			cout << "��������ѧ�ɼ� (double)" << endl;
			cin >> math;
			if (cin.fail()) {
				throw "�������ʹ���������double����"; // ����������ʹ����׳��쳣
			}
			cout << "������Ӣ��ɼ� (double)" << endl;
			cin >> english;
			if (cin.fail()) {
				throw "�������ʹ���������double����"; // ����������ʹ����׳��쳣
			}
			
		}
		catch (const char* msg) {
			cout << msg << endl; // �����쳣�����������Ϣ
			cout << "���򼴽��˳�" << endl; // �����ʾ��Ϣ
			exit(1); // �˳�����
		}
		cout << "��Ӹ�����Ϣ�ɹ�" << endl;
	}
	void addAdvisor() {
		int id;
		string name;
		cout << "�����뵼ʦ��id" << endl;
		cin >> id;
		cout << "�����뵼ʦ������" << endl;
		cin >> name;
		if (advisors.empty()) {
			advisors.insert(make_pair(id, name)); // ������и��� ID �Ľ�ʦ����Ϣ
			cout << "��ӵ�ʦ��Ϣ�ɹ�" << endl;
		}
		else {
			cout << "���ʧ�ܣ�һ��ѧ��ֻ��ѡ��һ����ʦ" << endl;
		}
	}
	void printAdvisor() {
		cout << "��ѧ��ѡ��ĵ�ʦ��Ϣ���£�" << endl;
		for (auto it = advisors.begin(); it != advisors.end(); it++)
		{
			cout << "��ʦid:" << it->first << "\t��ʦ������" << it->second<< endl;
		}
	}
	void findAdvisor(int tid)
	{
		cout << "�õ�ʦѡ���ѧ����Ϣ���£�" << endl;
		if (!advisors.empty()) {
			cout << "��ʦ������" << advisors[tid] << endl; // ������и��� ID ��ѧ��������
		}
		else {
			cout << "���ʧ�ܣ���ӳ��Ϊ��" << endl;
		}
	}
	void deleteAdvisor(int id) {
		auto it = advisors.find(id); // �ҵ�����id�ĵ�ʦ
		if (it != advisors.end()) { // ����ҵ��õ�ʦ
			advisors.erase(it); // �������ʦ��mapӳ����ɾ��
			cout << "��ʦ " << id << " �ѱ�ɾ��" << endl;
		}
		else { //���ѧ��û�ҵ�
			cout << "��ʦ " << id << " ������" << endl;
		}
	}
	void modifyAdvisor(int oldId, int newId) {
		auto it = advisors.find(oldId); // �ҵ���id
		if (it != advisors.end()) { // �����ѧ������
			string name = it->second; // ��ø�ѧ��������
			advisors.erase(it); // ����ѧ����mapӳ����ȥ��
			advisors.insert(make_pair(newId, name)); // ��ѧ�������µ�id
			cout << "��ʦ " << oldId << " �ı�����޸�Ϊ " << newId << endl;
		}
		else { // ���ѧ��û�ҵ�
			cout << "��ʦ " << oldId << " ������" << endl;
		}
	}
	virtual void outData()
	{
		Person::outData();
		cout << "ѧ�ţ�" <<sid << "\t�༶��ţ�" << classX << "\t���ĳɼ���" << chinese << "\t��ѧ�ɼ���" << math << "\tӢ��ɼ���" << english << endl;		
		//cout << "��ʦid��" << advisorId << "\t��ʦ������" << advisorName<<endl;
	}
	friend ostream& operator<<(ostream& os, Student& x);

};
ostream& operator<<(ostream& os, Student& x)
{
	os << static_cast<Person&>(x); //ΪPerson������������������
	os << "ѧ�ţ�" << x.sid << "\t�༶��ţ�" << x.classX << "\t���ĳɼ���" << x.chinese << "\t��ѧ�ɼ���" << x.math << "\tӢ��ɼ���" << x.english << endl;
	return os;
}
#endif // !Student_h