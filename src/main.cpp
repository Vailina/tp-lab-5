#include <iostream>
#include <string>
#include <ctime>
#include "Student_Group_Deanery.h"
using namespace std;
int main()
	{
		setlocale(LC_ALL, "rus");
		srand(time(NULL));
		Deanery Dean;
		Dean.createStudents();
		Dean.createGroups();
		Dean.addMarks();
		Dean.chooseHeads();
		Dean.changeGroup("18УБ-2", "Пустохин Прокл Карлович");
		Dean.printData();
		Dean.getStatistic();
		Dean.exceptionStudent();
		Dean.saveData();
	}