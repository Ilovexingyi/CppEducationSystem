#ifndef Person_h
#define Person_h
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Person
{
private:
    string name;//����
    int age = 0;//����
    char sex; //w->Ů m->��
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
    void setSex(char s) { sex = s; }
    string getSex() { if (sex == 'm' || sex == 'M')return"��"; if (sex == 'w' || sex == 'W')return "Ů"; }
    
    Person() { }
    Person(string n, int a, char s) :name(n), age(a), sex(s) {
       
        cout << "Person constructor..." << endl;
    }
    ~Person()
    {
        cout << "Person destructor..." << endl;
    }
    // ��ֵ���������
   /* Person& operator =(const Person& p) {
        if (this != &p)
        {
            name = p.name;
            age = p.age;
            sex = p.sex;
        }
        return *this;
    }*/
    Person& operator=(const Person& p)
    {
        if (this != &p)
        {
            memcpy(this, &p, sizeof(Person));
        }
        return *this;
    }
    //�������캯��
    Person(const Person& p) {
      /*  name = p.name;
        age = p.age;
        sex = p.sex;*/
        memcpy(this, &p, sizeof(Person));
    }

    virtual void inputData() {
        cout << "���������� (string)" << endl;
        cin >> name;
        try {
            cout << "���������� (int)" << endl;
            cin >> age; // ��������
            if (cin.fail()) {
                throw "�������ʹ���������int����"; // ����������ʹ����׳��쳣
            }
            cout << "�������Ա� (char��m->��, w->Ů)" << endl;
            cin >> sex;
            if (sex != 'm' && sex != 'w' && sex != 'M' && sex != 'W')
                throw "�Ա���Ϣ���ʧ�ܣ�������涨�ַ�";
        }
        catch (const char* msg) {
            cout << msg << endl; // �����쳣�����������Ϣ
            cout << "���򼴽��˳�" << endl; // �����ʾ��Ϣ
            exit(1); // �˳�����
        }
            cout << "��ӻ�����Ϣ�ɹ�" << endl;
    }
    virtual void outData() {
        cout << "������" << name << " \t���䣺" << age << "\t�Ա�" << getSex() << endl;
    }
    friend ostream& operator<<(ostream& os, Person& x);
};
ostream& operator<<(ostream& os, Person& x)
{
    cout << "������" << x.name << " \t���䣺" << x.age << "\t�Ա�" << x.getSex() << endl;
    return os;
}

#endif // !Person_h