#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include"Chancellor.h"
#include"Person.h"
#include"Student.h"
#include"Teacher.h"
#include"Dean.h"
#include<fstream>
using namespace std;
template<typename T>
class PersonManager {
public:
    PersonManager() {}
    virtual void inputData() = 0;
    virtual void outData() {
        if (!persons.empty())
        {
            for (auto t : persons) {
                t->outData();
            }
        }
        else
            cout << "���ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    virtual void deleteData() = 0;
    virtual void sortData() = 0;
    virtual  void findData() = 0;
    virtual void modifyData() = 0;
    virtual ~PersonManager() {}
    void promp()
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1������Ա��Ų���" << endl;
        cout << "2������Ա��������" << endl;
    }
public:
    vector<T*> persons;
};
class StudentManager : public PersonManager<Student> {
public:
    StudentManager() :PersonManager() {}
    void inputData() {
        try {
            int number;
            cout << "������ѧ��������:" << endl;
            cin >> number;
            if (cin.fail())
                throw"�������ʹ���";
            else {
                for (int i = 0; i < number; i++) {
                    Student* s = new  Student;
                    s->inputData();
                    cout << "�����뵼ʦid" << endl;
                    int tid;
                    cin >> tid;
                    cout << "�����뵼ʦ����" << endl;
                    string name;
                    cin >> name;
                    s->addAdvisor();
                    persons.push_back(s);
                }
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
            cout << "���������룡" << endl;
            cin.clear(); // ���cin�ϵĴ����־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��κ�ʣ���ַ�
        }
    }
    void outData() {
        PersonManager::outData();
        for (auto t:persons)
        {
            cout << t->getName() << "��ʦ��Ϣ���£�" << endl;
            t->printAdvisor();
        }
    }
    void deleteData() {
        StudentManager::outData();
        if (!persons.empty())
        {
            int index;
            cout << "������Ҫɾ����ʦ��ѧ����ţ�";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getSid() == index) {
                    (*it)->setAdvisorId(0);
                    (*it)->setAdvisorName("0");
                    cout << "ɾ���ɹ�" << endl;
                    break;
                }
                else { cout << "��ѧ����Ų�����" << endl; }
            }
        }
        else
            cout << "ɾ��ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void modifyData()
    {
        PersonManager::outData();
        int index;
        if (!persons.empty())
        {
            cout << "������Ҫ�޸ĵ�ѧ����ţ�";
            cin >> index;
            auto it = find_if(persons.begin(), persons.end(), [index](Student* s) {return s->getSid() == index; });
            int id;
            cout << "������Ҫ�޸ĵĵ�ʦ�ı��" << endl;
            cin >> id;
            string name;
            cout << "������Ҫ�޸ĵĵ�ʦ������" << endl;
            cin >> name;
            if (it != persons.end())
            {
                (*it)->inputData();
                (*it)->addAdvisor();

            }
            else
                cout << "��ѧ����Ų�����" << endl;
        }
        else
            cout << "�޸�ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void findData()
    {
        if (!persons.empty())
        {
            promp();
            int select = 0;
            cin >> select;
            if (select == 1)
            {
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    int sid;
                    cout << "������Ҫ���ҵ�ѧ����ţ�";
                    cin >> sid;
                    if ((*it)->getSid() == sid)
                    {
                        (*it)->outData();
                       // (*it)->getAdvisor((*it)->getAdvisorId());
                        break;
                    }
                    else
                        cout << "��ѧ����Ų�����" << endl;
                }
            }
            else if (select == 2)
            {
                string name;
                cout << "������������" << name;
                cin >> name;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getName() == name)
                    {
                        (*it)->outData();
                       // (*it)->getAdvisor((*it)->getAdvisorId());
                        break;
                    }
                    else
                        cout << "��Ǹ�����޴��ˣ�" << endl;
                }
            }
            else
            {
                cout << "����ѡ������" << endl;
            }
        }
        else
            cout << "����ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void sortData() {
        if (!persons.empty())
        {
            sort(persons.begin(), persons.end(), [](Student* s1, Student* s2) {return s1->getAge() < s2->getAge(); });
            cout << "����ɹ�" << endl;
        }
        else
            cout << "����ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    ~StudentManager() {
        for (auto s : persons) {
            delete s;
        }
    }

   
};
class TeacherManager : public PersonManager<Teacher> {
public:
    TeacherManager() :PersonManager() {}
    void inputData() {
        try {
            int number;
            cout << "�������ʦ������:" << endl;
            cin >> number;
            if (cin.fail())
                throw"�������ʹ���";
            else {
                for (int i = 0; i < number; i++) {
                    Teacher* t = new Teacher();
                    t->inputData();
                    t->setStudent();
                    persons.push_back(t);

                }
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
            cout << "���������룡" << endl;
            cin.clear(); // ���cin�ϵĴ����־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��κ�ʣ���ַ�
        }
    }
    void outData() {
        PersonManager::outData();
        for (auto t : persons)
        {
            t->printStudent();
        }
    }

    void deleteData() {
        PersonManager::outData();
        if (!persons.empty())
        {
            int index;
            cout << "������Ҫɾ��ѧ���Ľ�ʦ��ţ�";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getTid() == index) {
                    int id;
                    cout << "������Ҫɾ��ѧ���ı��" << endl;
                    cin >> id;
                    (*it)->deleteStudent(id);
                    persons.erase(it);
                    cout << "ɾ���ɹ�" << endl;
                    break;
                }
                else
                    cout << "��Ǹ�����޴��ˣ�" << endl;
            }
        }
        else
            cout << "ɾ��ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void modifyData()
    {
        TeacherManager::outData();
        if (persons.empty()) {
            cout << "�޸�ʧ�ܣ���ǰ����Ϊ��" << endl;
            return;
        }
        while (true)
        {
            int index;
            cout << "������Ҫ�޸ĵĽ�ʦ��ţ�";
            cin >> index;
            bool found = false;
            for (auto it = persons.begin(); it != persons.end(); it++)
            {
                if ((*it)->getTid() == index)
                {
                    found = true;
                    int oid,nid;
                    cout << "�������ѧ��id" << endl;
                    cin >> oid;
                    cout << "��������ѧ��id" << endl;
                    cin >> nid;
                    (*it)->modifyStudent(oid,nid);
                    break;
                }
            }
            if (!found)
                cout << "�ý�ʦ��Ų����ڣ�" << endl;
            else
                break;
        }
    }
    void findData()
    {
        if (!persons.empty())
        {
            int select;
            promp();
            cin >> select;
            if (select == 1)
            {
                int tid;
                cout << "������Ҫ���ҵĽ�ʦ��ţ�";
                cin >> tid;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getTid() == tid)
                    {
                        int id;
                        cout << "��������Ҫ���ҵ�ѧ����id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "�ý�ʦ��Ų����ڣ�" << endl;
            }
            else if (select == 2)
            {
                string name;
                cout << "������������" << endl;
                cin >> name;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getName() == name)
                    {
                        int id;
                        cout << "��������Ҫ���ҵ�ѧ����id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "��Ǹ�����޴��ˣ�" << endl;
            }
            else
            {
                cout << "����ѡ������" << endl;
            }
        }
        else
            cout << "����ʧ�ܣ���ǰ����Ϊ��" << endl;
    }

    void sortData() {
        if (!persons.empty())
        {
            sort(persons.begin(), persons.end(), [](Teacher* t1, Teacher* t2) {
                return t1->getAge() < t2->getAge();
                });
            cout << "����ɹ�" << endl;
        }
        else
            cout << "����ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    ~TeacherManager() {
        for (auto t : persons) {
            delete t;
        }
    }
};


class TeacherStudentManager {
public:
    TeacherStudentManager() {}
    void inputData() {
        string type;
        cout << "������Ҫ���ӵ����ͣ�1����ʦ��2��ѧ������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.inputData();
        }
        else if (type == "2")
        {
            studentManager.inputData();
        }

        else
            cout << "�������ʹ���" << endl;
    }
    void outData() {
        string type;
        cout << "������Ҫ��������ͣ�1����ʦ��2��ѧ��,3��ȫ���������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.outData();
        }
        else if (type == "2")
        {
            studentManager.outData();
        }
       
        else if (type == "3")
        {
            teacherManager.outData();
            studentManager.outData();
          
        }
        else
            cout << "�������ʹ���" << endl;
    }
    void deleteData() {
        string type;
        cout << "������Ҫɾ�������ͣ�1����ʦ��2��ѧ������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.deleteData();
        }
        else if (type == "2")
        {
            studentManager.deleteData();
        }
      
        else
            cout << "�������ʹ���" << endl;
    }
    void findData()
    {
        string type;
        cout << "������Ҫ���ҵ����ͣ�1����ʦ��2��ѧ������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.findData();
        }
        else if (type == "2")
        {
            studentManager.findData();
        }
       
        else
            cout << "�������ʹ���" << endl;
    }

    void modifyData()
    {
        string type;
        cout << "������Ҫ�޸ĵ����ͣ�1����ʦ��2��ѧ������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.modifyData();
        }
        else if (type == "2")
        {
            studentManager.modifyData();
        }
     
        else
            cout << "�������ʹ���" << endl;
    }

    void sortData() {
        string type;
        cout << "������Ҫ��������ͣ�1����ʦ��2��ѧ������";
        cin >> type;
        if (type == "1")
        {
            teacherManager.sortData();
        }
        else if (type == "2")
        {
            studentManager.sortData();
        }
      
        else
            cout << "�������ʹ���" << endl;
    }
    void ExitSystem()
    {
        string index;
        cout << "ȷ���Ƿ��˳�(1->�ǣ�2->��)" << endl;
        cin >> index;
        if (index == "1")
        {
            cout << "��ӭ�´�ʹ��" << endl;
            exit(0);//�˳�����
        }
        else if (index == "2")
            cout << "��ӭ����ʹ�ã�" << endl;
        else
            cout << "�������ʹ���!" << endl;
    }
    void Show_Menu();
private:
    TeacherManager teacherManager;
    StudentManager studentManager;
};
void TeacherStudentManager::Show_Menu()
{
    cout << "*************************************" << endl;
    cout << "**********��ӭʹ�ý������ϵͳ*******" << endl;
    cout << "***********0.�˳��������************" << endl;
    cout << "***********1.������Ա��Ϣ************" << endl;
    cout << "***********2.��ʾ��Ա��Ϣ************" << endl;
    cout << "***********3.ɾ����Ա��Ϣ************" << endl;
    cout << "***********4.�޸���Ա��Ϣ************" << endl;
    cout << "***********5.������Ա��Ϣ************" << endl;
    cout << "***********6.������������************" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}