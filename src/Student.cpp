
#include <iostream>
#include <string>
#include <vector>
#include "Student_Group_Deanery.h"

using namespace std;

	Student::Student(char* name, int i){
		fio = name;
		id = i;
	}
	void Student::assignmentStudent(Group *gr){
		group = gr;
	}
	void Student::addMark(int score){
		marks.push_back(score);
		num++;
	}
	int Student::countAverageMark(){
		int aver=0;
		for (int i = 0; i < num; i++){
			aver += marks[i];
		}
		aver /= num;
		return aver;
	}
