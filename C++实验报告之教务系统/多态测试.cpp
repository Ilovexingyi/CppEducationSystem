//#include<iostream>
//#include<string>
//#include <vector>
//#include <algorithm>
//#include"Chancellor.h"
//#include"Person.h"
//#include"Student.h"
//#include"Teacher.h"
//#include"Dean.h"
//#include"Management.h"
//using namespace std;
//bool cmp(Person* a, Person* b) {
//    return a->getAge() < b->getAge();
//}
////class TeacherCompare {
////public:
////    bool operator()(Teacher* t1, Teacher* t2) {
////        return t1->getAge() < t2->getAge();
////    }
////};
//int main() {
//    //��STL�е�vector��list����Person����ָ������ã�����̳���ϵ�еĶ���ʵ�����ֶ�̬���������ͬ�������԰���������
//
//    // ����һ�� vector ���������ڴ洢 Person ���͵�ָ��
//    vector<Person*> persons;
//   
//    // ѭ�� 5 �Σ����� Teacher �����������ݣ�����ָ����� vector ������
//    for (int i = 0; i < 1; i++) {
//        Teacher* teacher = new Teacher();
//        teacher->inputData();
//        persons.push_back(teacher);
//    }
//    for (auto t:persons )
//    {
//        t->getName();
//    }
//    //��������
//    
//
//
//    // ѭ�� 5 �Σ����� Student �����������ݣ�����ָ����� vector ������
//    for (int i = 0; i < 1; i++) {
//        Student* student = new Student();
//        student->inputData();
//        persons.push_back(student);
//    }
//
//    // ���� Chancellor �����������ݣ�����ָ����� vector ������
//    Chancellor* chancellor = new Chancellor();
//    chancellor->inputData();
//    persons.push_back(chancellor);
//
//    sort(persons.begin(), persons.end(), cmp);//��������С��������
//
//    // ѭ������ vector �����е�ÿ��Ԫ�أ����� outData() �����������
//    for (int i = 0; i < persons.size(); i++) {
//        persons[i]->outData();
//    }
//
//    //Teacher����
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Teacher*>(persons[i])) {
//            Teacher* teacher = dynamic_cast<Teacher*>(persons[i]);
//            teacher->outData();
//        }
//    }
//
//    // Dean����
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Dean*>(persons[i])) {
//            Dean* dean = dynamic_cast<Dean*>(persons[i]);
//            dean->outData();
//        }
//    }
//
//   //Chancellor����
//    for (int i = 0; i < persons.size(); i++) {
//        if (dynamic_cast<Chancellor*>(persons[i])) {
//            Chancellor* chancellor = dynamic_cast<Chancellor*>(persons[i]);
//            chancellor->outData();
//        }
//    }
//
//    return 0;
//}
