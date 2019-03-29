
#include <iostream>
#include <string>
#include <vector>
#include "Student_Group_Deanery.h"

using namespace std;

	Group(string gr_name) : title(gr_name),num(0){}

	void Group::addStudent(Student *st){
		students.push_back(st);
		num++;
	}

	int Group::countAverageMarkInGroup(){
		int aver_gr=0;
		for (int i = 0; i < num; i++){
			aver_gr+=students[i]->countAverageMark();
		}
		aver_gr /= num;
		return aver_gr;
	}
	Student* Group::chooseHead() {
		int i = rand() % (num - 1);
		head = students[i];
		return students[i];
	}

	Student* Group::searchStFio(string name) {
		for (int i = 0; i < num; i++) {
			if (students[i]->fio == name){
				return students[i];
			}
		}
	}

	Student* Group::searchStId(int numid) {
		for (int i = 0; i < num; i++) {
			if (students[i]->id == numid) {
				return students[i];
			}
		}
	}
	void Group::exceptionStudent(string name) {
		for (int i = 0; i < num; i++) {
			if (students[i]->fio == name) {
				if (students[i] == head) {
					students.erase(students.begin() + i);
					num--;
					chooseHead();
				}
				else {
					students.erase(students.begin() + i);
					num--;
				}
			}
		}
	}

};
