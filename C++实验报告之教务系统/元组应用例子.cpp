//#include<iostream>
//#include<string>
//#include<vector>
//#include<tuple>
//#include<list>
//using namespace std;
//struct Grade
//{
//	string courseName;
//	double grade;
//	Grade(string s,double g):courseName(s),grade(g){}
//};
//typedef tuple<string, int, string, vector<Grade>> Student;
////inputData()�������ص�Student��һ�ָ��ӵ�Ԫ���������ͣ���Ԫ�鱣��ѧ����������ѧ�š�רҵ���Լ�������ſγ̵ĳɼ�
//Student inputData()
//{
//	Student stu;
//	cout << "����ѧ�����ݣ�������ѧ�ţ�רҵ" << endl;
//	cin >> get<0>(stu) >> get<1>(stu) >> get<2>(stu);//Ԫ���Ԫ�صķ��ʷ���
//	string cName;
//	double score = 0;
//	int i = 1;
//	while (cName!="exit")
//	{
//		cout << "�����" << i++ << " ��Ŀ���ƣ�����exit������\t";
//		cin >> cName;
//		if (cName == "exit")
//			break;
//		cout << "�ɼ���\t";
//		cin >> score;
//		get<3>(stu).push_back(Grade(cName, score));//��Ԫ������Ԫ������Ӷ���
//	}
//	return stu;
//}
//void display(Student student)
//{
//	cout << get<0>(student) << "\t" << get<1>(student) << "\t" << get<2>(student) << "\t" << endl;
//	//forѭ��ʾ���˷���Ԫ���о��в�ȷ������������Ԫ�صķ��ʷ���
//	for (int i = 0; i < get<3>(student).size(); i++)
//	{
//		cout << get<3>(student)[i].courseName << "\t" << get<3>(student)[i].grade << endl;
//	}
//}
//int main()
//{
//	auto t = make_tuple("string", 3, 20.01);
//	tuple<const char*, int, double>tt("string", 3, 20.01);
//	tuple<int, int, int>t5{ 1,2,3 };
//	tuple<int, string, const char*>t1, t2{ 1,"���ݽṹ","3.5ѧ��" };
//	t1 = t2;
//	cout << get<0>(t1) << "\t" << get<1>(t1) << "\t" << get<2>(t1) << endl;//Ԫ��ķ��ʷ���
//	//����Ĵ����ʾ���˾��ü̱�����Ԫ�ص�Ԫ�鶨�巽�����Լ�Ԫ���е�������ʷ���
//	tuple < string, vector<double>, int, list<int>> vtable ("tomoto", { 3,12,2.34 }, 42, { 1,8,9 });
//	list<int>::iterator iter;//��������ĵ�����
//	for (iter = get<3>(vtable).begin(); iter != get<3>(vtable).end(); iter++)
//	{
//		cout << *iter << "\t";
//
//	}
//	cout << endl;
//	//student����ʵ������Ԫ���еĶ���ֵ�ķ���
//	Student student{ "����",1001,"�����רҵ",{{"Ӣ��",76.4},{"����",87},{"c++����",89}} };
//	display(student);
//	student = inputData();
//	cout << endl;
//	display(student);
//	system("pause");
//	return 0;
//}