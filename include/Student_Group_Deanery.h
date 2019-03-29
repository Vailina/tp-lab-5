#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Group;

class Student{
	friend class Group;
	friend class Deanery;
private:
	int id;// идентификационный номер
	string fio;// фамилия и инициалы
	Group  *group;// ссылка на группу(объект Group)
	vector <int> marks;// массив оценок
	int num=0;// количество оценок
public:
	Student(char* name, int id);
	void assignmentStudent(Group *gr);
	void addMark(int score);
	int countAverageMark();
};

class Group{
	friend class Deanery;
private:
	string title; //название группы
	vector <Student*> students; //массив из ссылок на студентов
	int num;//количество студентов в группе
	Student *head; //ссылка на старосту(из членов группы)
public:
	Group(string gr_name) : title(gr_name),num(0){};
	void addStudent(Student *st);
	int countAverageMarkInGroup();
	Student* chooseHead();
	Student* searchStFio(string name);
	Student* searchStId(int numid);
	void exceptionStudent(string name);

};

class Deanery{
private:
	vector <Student *> students; //массив студентов
	vector <Group *> groups; //массив групп
	int ID = 0;
	int num_stud = 0;
public:
	void createStudents();
	void createGroups();
	void addMarks(int num);
	void chooseHeads();
	void changeGroup(string group_name, string student_name);
	void exceptionStudent();
	void getStatistic();
	void saveData();
	void printData();
};
#endif
