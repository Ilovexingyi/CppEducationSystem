#include "Person.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;
#ifndef Teacher_h
#define Teacher_h
class Teacher :public Person
{
private:
    int tid = 0;
    string protitle;
    string dept;
    double hourPrice = 0;
    double salary = 0;
    int workHour = 0;
    map<int, string> students;
    string name;
    int id;
    int num;

public:
    virtual double getSalary() { return salary; }
    virtual double getIncome() { return salary + (hourPrice * double(workHour)); }
    virtual void setSalary(double s) { salary = s; }
    void setWorkHour(int wh) { workHour = wh; }
    void setHourPrice(double hp) { hourPrice = hp; }
    int getTid() { return tid; }
    string getTitle() { return protitle; }
   
    Teacher() {  }
    Teacher(string n, int a, char s, int t, string p, string d, int wh, double hp, double sa) :Person(n, a, s), tid(t), protitle(p), dept(d), workHour(wh), hourPrice(hp), salary(sa) { cout << "Teacher constructor..." << endl; }
    ~Teacher()
    {
        cout << "Teacher destructor..." << endl;
    }
    // ��ֵ���������
    Teacher& operator =(const Teacher& t) {
        Person::operator=(t);
        tid = t.tid;
        protitle = t.protitle;
        dept = t.dept;
        workHour = t.workHour;
        hourPrice = t.hourPrice;
        salary = t.salary;
        return *this;
    }
    //�������캯��
    Teacher(const Teacher& t) :Person(t) {
        tid = t.tid;
        protitle = t.protitle;
        dept = t.dept;
        workHour = t.workHour;
        hourPrice = t.hourPrice;
        salary = t.salary;
       
    }
    virtual void inputData() {
        Person::inputData();
        try {
            cout << "�������ʦ��� (int)" << endl;
            cin >> tid;
            if (cin.fail())
                throw  "�������ʹ���������int����"; // ����������ʹ����׳��쳣
            cout << "������ְ�� (string)" << endl;
            cin >> protitle;
            cout << "����������Ժϵ (string)" << endl;
            cin >> dept;
            cout << "�������ù���ʱ�� (double)" << endl;
            cin >> workHour;
            if (cin.fail())
                throw  "�������ʹ���������double����"; // ����������ʹ����׳��쳣
            cout << "�����빤��ʱн (double)" << endl;
            cin >> hourPrice;
            if (cin.fail())
                throw  "�������ʹ���������double����"; // ����������ʹ����׳��쳣
            cout << "������������� (double)" << endl;
            cin >> salary;
            if (cin.fail())
                throw  "�������ʹ���������double����"; // ����������ʹ����׳��쳣
        }
        catch (const char* msg)
        {
                cout << msg << endl; // �����쳣�����������Ϣ
                cout << "���򼴽��˳�" << endl; // �����ʾ��Ϣ
                exit(1); // �˳�����
        }
        cout << "��ӽ�ʦ������Ϣ�ɹ�" << endl;
    }
    void setStudent() {
        cout << "���������ѧ���ĸ���" << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int id;
            string name;
            cout << "����������ѧ����id" << endl;
            cin >> id;
            cout << "����������ѧ��������" << endl;
            cin >> name;
            students.insert(make_pair(id, name));
        }
    }
    void printStudent()
    {
        int i = 1;
        for (auto it = students.begin(); it != students.end(); it++)
        {
            cout << "�����ѧ��" << i << "\tid:" << it->first << "\t����:" << it->second << endl;
            i++;
        }
    }
    void findStudent(int tid)
    {
            cout << "�õ�ʦѡ���ѧ����Ϣ���£�" << endl;
            if (!students.empty()) {
                cout << "ѧ��������" << students[tid] << endl; // ������и��� ID ��ѧ��������
            }
            else {
                cout << "���ʧ�ܣ���ӳ��Ϊ��" << endl;
            }
    }
    void deleteStudent(int id) {
        auto it = students.find(id); // �ҵ�����id��ѧ��
        if (it != students.end()) { // ����ҵ���ѧ��
            students.erase(it); // �����ѧ����mapӳ����ɾ��
            cout << "ѧ�� " << id << " �ѱ�ɾ��" << endl;
        }
        else { //���ѧ��û�ҵ�
            cout << "ѧ�� " << id << " ������" << endl;
        }
    }
    void modifyStudent(int oldId, int newId) {
        auto it = students.find(oldId); // �ҵ���id
        if (it != students.end()) { // �����ѧ������
            string name = it->second; // ��ø�ѧ��������
            students.erase(it); // ����ѧ����mapӳ����ȥ��
            students.insert(make_pair(newId, name)); // ��ѧ�������µ�id
            cout << "�����ѧ�� " << oldId << " �ı�����޸�Ϊ " << newId << endl;
        }
        else { // ���ѧ��û�ҵ�
            cout << "�����ѧ�� " << oldId << " ������" << endl;
        }
    }
    virtual void outData()
    {
        Person::outData();
        cout << "��ʦ��ţ�" << tid << "\tְ�ƣ�" << protitle << "\t����Ժϵ��" << dept << "\t����ʱ����" << workHour << "\t����ʱн��" << hourPrice << "\t�������ʣ�" << salary << "\t��ʦ�����룺" << getIncome() << endl;
       
    }
    friend ostream& operator<<(ostream& os, Teacher& x);

};
ostream& operator<<(ostream& os, Teacher& x)
{
    os << static_cast<Person&>(x); //ΪPerson������������������
    cout << "��ʦ��ţ�" << x.tid << "\tְ�ƣ�" << x.protitle << "\t����Ժϵ��" << x.dept << "\t����ʱ����" << x.workHour << "\t����ʱн��" << x.hourPrice << "\t�������ʣ�" << x.salary << "\t�����룺" << x.getIncome() << endl;
    return os;
}
#endif // !Teacher_h
