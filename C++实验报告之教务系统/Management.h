#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
        for (auto t : persons)
        {
            cout << t->getName() << "��ʦ��Ϣ���£�" << endl;
            t->printAdvisor();
        }
    }
   
    void deleteData() {
        StudentManager::outData();
        if(!persons.empty())
        {
            int choice;
            cout << "1->ɾ��ѧ����2->ɾ����ʦ" << endl;
            cin >> choice;
            int index;
            cout << "������Ҫ������ѧ����ţ�";
            cin >> index;
                for (auto it = persons.begin(); it != persons.end(); it++) {
                    if ((*it)->getSid() == index) {
                        if (choice == 1)
                        {
                            persons.erase(it);
                            cout << "ɾ���ɹ�" << endl;
                        }
                        else if (choice == 2)
                        {
                            int id;
                            cout << "�����뵼ʦ��id" << endl;
                            cin >> id;
                            (*it)->deleteAdvisor(id);
                            cout << "ɾ���ɹ�" << endl;
                        }
                        else { cout << "��ѧ����Ų�����" << endl; }
                        break;
                    }
                   
                }
        }
        else
            cout << "ɾ��ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void modifyData()
    {
        StudentManager::outData();
        int index;
          if (!persons.empty())
          {
              cout << "1->�޸�ѧ����2->�޸�ѧ��ѡ��ĵ�ʦ" << endl;
              int choice;
              cin >> choice;
              cout << "�����������ѧ����ţ�";
              cin >> index;
               auto it = find_if(persons.begin(), persons.end(), [index](Student* s) {return s->getSid() == index; });
                if (it != persons.end())
                {
                    if (choice == 1) {
                        (*it)->inputData();
                    }
                    else if (choice == 2)
                    {
                        int oid,nid;
                        cout << "������ɵ�ʦ���" << endl;
                        cin >> oid;
                        cout << "�������µ�ʦ���" << endl;
                        cin >> nid;
                        (*it)->modifyAdvisor(oid,nid);
                    }
                    else
                        cout << "��ѧ����Ų�����" << endl;
                }
          }
          else
              cout << "�޸�ʧ�ܣ���ǰ����Ϊ��" << endl;
    }
    void findData()
    {
        if (!persons.empty())
        {
            cout << "1->����ѧ����2->����ѧ���ĵ�ʦ" << endl;
            int choice;
            cin >> choice;
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
                        if (choice == 1)
                        {
                            (*it)->outData();

                        }
                        else if (choice == 2)
                        {
                            (*it)->printAdvisor();
                        }
                        else
                            cout << "�������ʹ���" << endl;
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

                        if (choice == 1)
                        {
                            (*it)->outData();

                        }
                        else if (choice == 2)
                        {
                            (*it)->printAdvisor();
                        }
                        else
                            cout << "�������ʹ���" << endl;
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
            cout << "��ʦ��" << t->getName() << "�����ѧ����Ϣ����" << endl;
            t->printStudent();
        }
    }
    void deleteData() {
        TeacherManager::outData();
        if (!persons.empty())
        {
            cout << "1->ɾ����ʦ��2->ɾ����ʦ�����ѧ��" << endl;
            int choice;
            cin >> choice;
            int index;
            cout << "������Ҫ�����Ľ�ʦ��ţ�";
            cin >> index;
            for (auto it = persons.begin(); it != persons.end(); it++) {
                if ((*it)->getTid() == index) {
                    if (choice == 1)
                    {
                        persons.erase(it);
                        cout << "ɾ���ɹ�" << endl;
                      
                    }
                    else if (choice == 2)
                    {
                        int id;
                        cout << "������Ҫɾ��ѧ���ı��" << endl;
                        cin >> id;
                        (*it)->deleteStudent(id);
                        cout << "ɾ���ɹ�" << endl;
                    }
                    else
                        cout << "�������ʹ���" << endl;
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
            cout << "1->�޸Ľ�ʦ��2->�޸Ľ�ʦ�����ѧ��" << endl;
            int choice;
            cin >> choice;
            int index;
            cout << "������Ҫ�޸ĵĽ�ʦ��ţ�";
            cin >> index;
            bool found = false;
            for (auto it = persons.begin(); it != persons.end(); it++)
            {
                if ((*it)->getTid() == index)
                {
                    found = true;
                    if (choice == 1)
                    {
                        (*it)->inputData();
                        break;
                    }
                    else if (choice == 2)
                    {
                        int oid, nid;
                        cout << "�������ѧ��id" << endl;
                        cin >> oid;
                        cout << "��������ѧ��id" << endl;
                        cin >> nid;
                        (*it)->modifyStudent(oid, nid);
                        break;
                    }
                    else
                        cout << "�������ʹ���" << endl;
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
            int select ;
            promp();
            cin >> select;
            if (select == 1)
            {
                cout << "1->���ҽ�ʦ��2->���ҽ�ʦ�����ѧ��" << endl;
                int choice;
                cin >> choice;
                int tid;
                cout << "������Ҫ���ҵĽ�ʦ��ţ�";
                cin >> tid;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if ((*it)->getTid() == tid)
                    {
                        if (choice == 1)
                        {
                            (*it)->outData();
                        }
                        else if (choice == 2)
                        {
                            int id;
                            cout << "��������Ҫ���ҵ�ѧ����id" << endl;
                            cin >> id;
                            (*it)->findStudent(id);
                        }
                        else
                            cout << "�������ʹ���" << endl;
                        found = true;
                        return;
                    }
                }
                if (!found)
                    cout << "�ý�ʦ��Ų����ڣ�" << endl;
            }
            else if (select == 2)
            {
                cout << "1->���ҽ�ʦ��2->���ҽ�ʦ�����ѧ��" << endl;
                int choice;
                cin >> choice;
                string name;
                cout << "������������" << endl;
                cin >> name;
                bool found = false;
                for (auto it = persons.begin(); it != persons.end(); it++)
                {
                    if (choice == 1)
                    {
                        (*it)->outData();
                    }
                    else if (choice == 2)
                    {
                        int id;
                        cout << "��������Ҫ���ҵ�ѧ����id" << endl;
                        cin >> id;
                        (*it)->findStudent(id);
                    }
                    else
                        cout << "�������ʹ���" << endl;
                    found = true;
                    return;
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
        if(!persons.empty())
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

class DeanManager :public TeacherManager
{
public:
    DeanManager() :TeacherManager() {}
    ~DeanManager() {
        for (auto d : persons){ delete d;}
    }
    void inputData() {
        try {
            int number;
            cout << "������ϵ���ε�����:" << endl;
            cin >> number;
            if (cin.fail())
                throw"�������ʹ���";
            else {
                for (int i = 0; i < number; i++) {
                    Dean* d = new Dean();
                    d->inputData();
                    persons.push_back(d);
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
    void outData() { PersonManager::outData(); }
    void deleteData() { TeacherManager::deleteData(); }
    void modifyData(){ TeacherManager::modifyData();}
    void findData(){ TeacherManager::findData();}
    void sortData() {TeacherManager::sortData(); }
};
class ChancellorManager :public TeacherManager
{
public:
    ChancellorManager() :TeacherManager() {}
    ~ChancellorManager()
    {for (auto c : persons){ delete c;}}
    void inputData() {
        try {
            int number;
            cout << "������Ժ��������:" << endl;
            cin >> number;
            if (cin.fail())
                throw"�������ʹ���";
            else {
                for (int i = 0; i < number; i++) {
                    Chancellor* t = new Chancellor();
                    t->inputData();
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
    void outData() { PersonManager::outData(); }
    void deleteData() { TeacherManager::deleteData(); }
    void modifyData() { TeacherManager::modifyData(); }
    void findData() { TeacherManager::findData(); }
    void sortData() { TeacherManager::sortData(); }
};
class TeacherStudentManager {
public:
    TeacherStudentManager() {}
    void inputData() {
        string type;
        cout << "������Ҫ��ӵ����ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ������";
        cin >> type;
        if (type == "1") 
        { teacherManager.inputData(); }
        else if (type == "2") 
        {studentManager.inputData();}
        else if (type == "3")
        { deanManager.inputData(); }
        else if (type == "4")
        { chancellorManager.inputData(); }
        else
            cout << "�������ʹ���" << endl;
    }
    void outData() {
        string type;
        cout << "������Ҫ��������ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ����5��ȫ���������";
        cin >> type;
        if (type == "1") 
        {teacherManager.outData();}
        else if (type == "2")
        {studentManager.outData();}
        else if (type == "3")
        {deanManager.outData();}
        else if (type == "4")
        {chancellorManager.outData();}
        else if (type == "5")
        {
            teacherManager.outData();
            studentManager.outData();
            deanManager.outData();
            chancellorManager.outData();
        }
        else 
            cout << "�������ʹ���" << endl;
    }
    void deleteData() {
        string type;
        cout << "������Ҫɾ�������ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ������";
        cin >> type;
        if (type == "1") 
        { teacherManager.deleteData();}
        else if (type == "2") 
        {studentManager.deleteData();}
        else if (type == "3")
        {deanManager.deleteData();}
        else if (type == "4")
        { chancellorManager.deleteData(); }
        else
            cout << "�������ʹ���" << endl;
    }
   void findData()
    {
        string type;
        cout << "������Ҫ���ҵ����ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ������";
        cin >> type;
        if (type == "1") 
        {teacherManager.findData();}
        else if (type == "2") 
        { studentManager.findData(); }
        else if (type == "3")
        {deanManager.findData();  }
        else if (type == "4")
        {chancellorManager.findData();}
        else 
            cout << "�������ʹ���" << endl;
    }

    void modifyData()
    {
        string type;
        cout << "������Ҫ�޸ĵ����ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ������";
        cin >> type;
        if (type == "1")
        { teacherManager.modifyData();}
        else if (type == "2") 
        {studentManager.modifyData();}
        else if (type == "3")
        {deanManager.modifyData();}
        else if (type == "4")
        {chancellorManager.modifyData();}
        else 
            cout << "�������ʹ���" << endl;
    }

    void sortData() {
        string type;
        cout << "������Ҫ��������ͣ�1����ʦ��2��ѧ��,3��ϵ���Σ�4��Ժ������";
        cin >> type;
        if (type == "1")
        {teacherManager.sortData(); }
        else if (type == "2")
        { studentManager.sortData();}
        else if (type == "3")
        { deanManager.sortData();}
        else if (type == "4")
        {chancellorManager.sortData();}
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
    DeanManager deanManager;
    ChancellorManager chancellorManager;
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