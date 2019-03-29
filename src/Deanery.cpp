
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Student_Group_Deanery.h"
using namespace std;


	void createStudents(){
		char buff1[50];
		ifstream fin("students.txt");
		while (fin.getline(buff1, 50)){
			ID++;
			num_stud++;
			students.push_back(new Student(buff1, ID));
		}
		fin.close();
	}
	void createGroups(){
		
		char buff2[10];
		ifstream fin("groups.txt");
		while (fin.getline(buff2, 10)){
			groups.push_back(new Group(buff2));
		}
		for (int i = 0; i < num_stud; i++){
			groups[i%groups.size()]->addStudent(students[i]);
			students[i]->assignmentStudent(groups[i%groups.size()]);
		}
		fin.close();
	}
	void addMarks(int num){
		for (int j = 0; j < num_stud; j++){
			for (int i = 0; i < num; i++){
				students[j]->addMark(rand() % 10);
			}
		}
		
	}
	void chooseHeads() {
		for (int i = 0; i < groups.size(); i++) {
			groups[i]->chooseHead();
		}
	}
	void changeGroup(string group_name, string student_name){
		int i = 0, j=0;
		
		while (group_name != groups[j]->title){
			j++;
		}
		Group * present_gr = students[i]->group;
		groups[j]->searchStFio(student_name)->assignmentStudent(groups[j]);
		groups[j]->addStudent(students[i]);
		present_gr->exceptionStudent(students[i]->fio);
	}
	void exceptionStudent() {
		for (int i = 0; i < num_stud; i++) {
			if (students[i]->countAverageMark() < 4) {
				students[i]->group->exceptionStudent(students[i]->fio); 
				students.erase(students.begin() + i);
				num_stud--;
				i--;
			}
		}
	}
	void getStatistic(){
		ofstream fout("statistic.txt");
		for (int j = 0; j < groups.size(); j++){
			vector <vector<string>> list_marks(11);
			int M=0;//M - average mark
			
			int mark = groups[j]->countAverageMarkInGroup();
			cout << "Группа " << groups[j]->title << " Ср. оценка - " << mark<<endl;
			fout << "Группа " << groups[j]->title << " Ср. оценка - " << mark << endl;
			//list_marks[mark].push_back("Average");
			for (int i = 0; i < groups[j]->num; i++){
				M=groups[j]->students[i]->countAverageMark();
				list_marks[M].push_back(groups[j]->students[i]->fio);
			}
			
			for (int j = 0; j < list_marks.size(); j++){
				fout << "Оценка " << j << " - " << list_marks[j].size() << "чел." << endl;
				cout << "Оценка " << j<<" - " <<list_marks[j].size() <<"чел."<< endl;
				for (int k = 0; k < list_marks[j].size(); k++){
					fout << list_marks[j][k] << endl;
					cout << list_marks[j][k] << endl;
				}
				fout << endl;
				cout << endl;
			}			
		}		
	}
	void saveData(){
		ofstream fout("Lists.txt");
		for (int j = 0; j < groups.size(); j++){
			fout <<"Группа:"<< groups[j]->title << endl;
			fout << "Староста: " << groups[j]->head->fio << endl;
			fout << "Список студентов:\n";
			for (int i = 0; i < groups[j]->num; i++){
				fout << groups[j]->students[i]->id <<"    ";
				fout << groups[j]->students[i]->fio << "    ";
				for (int k = 0; k < groups[j]->students[i]->num; k++) 
					fout << groups[j]->students[i]->marks[k]<<"  ";
				fout << endl;
			}
		}	
		fout.close();
	}
	void printData(){
		for (int j = 0; j < groups.size(); j++){
			cout << "Группа:" << groups[j]->title << endl;
			cout << "Староста: " << groups[j]->head->fio << endl;
			cout << "Список студентов:\n";
			for (int i = 0; i < groups[j]->num; i++){
				cout << groups[j]->students[i]->id << "    ";
				cout << groups[j]->students[i]->fio <<"    ";
				for (int k = 0; k < groups[j]->students[i]->num; k++)
					cout << groups[j]->students[i]->marks[k] << "  ";
				cout << endl;
			}
		}
		
	}
