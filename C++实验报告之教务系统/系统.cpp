//#include<iostream>
//#include<string>
//#include <vector>
//#include <algorithm>
//#include"Management.h"
//using namespace std;
//
//int main()
//{
//    TeacherStudentManager t;
//    try
//    {
//        while (true)
//        {
//            int choice;
//            t.Show_Menu();
//            cout << "����������ѡ��" << endl;
//            cin >> choice;
//            if (cin.fail())
//                throw "���򼴽��˳�";
//            switch (choice)
//            {
//            case 0:
//                t.ExitSystem();
//                break;
//            case 1:
//                t.inputData();
//                break;
//            case 2:
//                t.outData();
//                break;
//            case 3:
//                t.deleteData();
//                break;
//            case 4:
//                t.modifyData();
//                break;
//            case 5:
//                t.findData();
//                break;
//            case 6:
//                t.sortData();
//                break;
//            default:
//                system("cls");//����
//                break;
//            }
//        }
//    }
//    catch (const char*msg)
//    {
//        cout << msg << endl;
//        system("pause");
//        exit(1);
//    }
//   
//}