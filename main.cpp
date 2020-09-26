#include <iostream>
#include <string>
#include <list>
#include <fstream>



using namespace std;
string getName();
string getUSFID();
string getEmail();
int getPresentationGrade();
int getEssayGrade();
int getTermProjectGrade();

string getName()
{
	string name;
	while (true)
	{
		//get name but make sure name is up to 40 characters or less. Try again if not correct.
		cout << "Name: ";
		cin >> name;
		if (name.length() <= 40)
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Name must less than 40 characters" << endl;
	}

	return name;
}

string getUSFID()
{

	string USFID;
	while (true)
	{
		//get USFID but make sure ID is equal to 10 characters or less. Try again if not correct.
		cout << "USFID: ";
		cin >> USFID;
		if (USFID.length() <= 10)
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "USFID must be 10 characters" << endl;
	}

	return USFID;
}

string getEmail()
{
	string email;

	while (true)
	{
		//get email but make sure email is up to 40 characters or less. Try again if not correct.
		cout << "Email: ";
		cin >> email;
		if (email.length() <= 40)
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Email must less than 40 characters" << endl;
	}

	return email;
}

int getPresentationGrade()
{
	int gradeOfPresentation;

	while (true)
	{
		//get grade of presentation but make sure it's a number between 0 and 4
		cout << "Grade of the presentation(numerical value from 0 (F) to 4 (A)): ";
		cin >> gradeOfPresentation;
		if (!(cin.fail()) && (gradeOfPresentation <= 4 && gradeOfPresentation >= 0))
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;
	}

	return gradeOfPresentation;
}

int getEssayGrade()
{
	int gradeOfEssay;

	while (true)
	{
		//get grade of essay but make sure it's a number between 0 and 4
		cout << "Grade of essay(numerical value from 0 (F) to 4 (A)): ";
		cin >> gradeOfEssay;
		if (!(cin.fail()) && (gradeOfEssay <= 4 && gradeOfEssay >= 0))
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;
	}

	return gradeOfEssay;
}

int getTermProjectGrade()
{
	int gradeOfTermProject;

	while (true)
	{
		//get grade of term project but make sure it's a number between 0 and 4
		cout << "Grade of the term project(numerical value from 0 (F) to 4 (A)): ";
		cin >> gradeOfTermProject;
		if (!(cin.fail()) && (gradeOfTermProject <= 4 && gradeOfTermProject >= 0))
			break;
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;
	}

	return gradeOfTermProject;
}


class Student
{	
public:
	bool operator == (const Student& s) const { return name == s.name && usfid == s.usfid && email == s.email && GradeofPresentation == s.GradeofPresentation && GradeofEssay == s.GradeofEssay && GradeofProject == s.GradeofProject; }
	bool operator != (const Student& s) const { return !operator == (s); }
	string name;
	string usfid;
	string email;
	int GradeofPresentation = 0;
	int GradeofEssay = 0;
	int GradeofProject = 0;
}
;

list<Student> read_student()
{
	list<Student> Student_list;
	Student stud;
	fstream myfile;

	myfile.open("student.txt");
	if (myfile.is_open()) {
		while (myfile >> stud.name >> stud.usfid >> stud.email >> stud.GradeofPresentation >> stud.GradeofEssay >> stud.GradeofProject) {
			cout << stud.name << " " << stud.usfid << " " << stud.email << " " << stud.GradeofPresentation << " " << stud.GradeofEssay << " " << stud.GradeofProject << "\n";
			Student_list.push_back(stud);
		}
		myfile.close();
	}

	
	return Student_list;
}

void write_into(list<Student> Student_list)
{
	ofstream myfile;
	myfile.open("student.txt", ofstream::out | ofstream::trunc);
	
	list<Student>::iterator itr;
	if (myfile.is_open()) {
		for (itr = Student_list.begin(); itr != Student_list.end(); ++itr) {
			myfile << itr->name << " " << itr->usfid << " " << itr->email << " " << itr->GradeofPresentation << " " << itr->GradeofEssay << " " << itr->GradeofProject << "\n";
		}
		myfile.close();
	}
}

list<Student> add_student(list<Student> Stud_list)
{
	Student stud;
	stud.name = getName();
	stud.usfid = getUSFID();
	stud.email = getEmail();
	stud.GradeofPresentation = getPresentationGrade();
	stud.GradeofEssay = getEssayGrade();
	stud.GradeofProject = getTermProjectGrade();
	
	Stud_list.push_back(stud);
	
	return Stud_list;
	
}

list<Student> delete_student(list<Student> Stud_list)
{
	//list<Student> Student_list1 = Student_list;

	string name;
	cout << "enter the name who you want to delete: ";
	cin >> name;
	Student stud;
	list<Student>::iterator itr;
	for ( itr = Stud_list.begin(); itr != Stud_list.end(); ++itr) {
	
		if (itr->name == name) {
			
			stud.name = itr->name;
			stud.usfid = itr->usfid;
			stud.email = itr->email;
			stud.GradeofPresentation = itr->GradeofPresentation;
			stud.GradeofEssay = itr->GradeofEssay;
			stud.GradeofProject = itr->GradeofProject;
		}
		
	}
	Stud_list.remove(stud);
	return Stud_list;
};

void retrieve_name(list<Student> Student_list)
{
	string name;
	cout << "Enter the name you want to retrieve: ";
	cin >> name;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->name == name) {
			cout << it->name << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}
void retrieve_usfid(list<Student> Student_list)
{
	string usfid;
	cout << "Enter the usf id you want to retrieve: ";
	cin >> usfid;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->usfid == usfid) {
			cout << it->name << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}

void retrieve_email(list<Student> Student_list)
{
	string email;
	cout << "Enter the email you want to retrieve: ";
	cin >> email;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->email == email) {
			cout << it->name << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}

void printMenu()
{
	cout << "****************************************************" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Delete student" << endl;
	cout << "3. Retrieve student data based on a search by name" << endl;
	cout << "4. Retrieve student data based on a search by ID" << endl;
	cout << "5. Retrieve student data based on a search by email" << endl;
	cout << "6. Update data field(s)" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
	cout << "Enter your choice [0-6]: ";

	return;
};
int main()
{
	
	list<Student> Student_list = read_student();

	while (true)
	{
		printMenu();
		string choice;
		cin >> choice;

		if (choice == "0")
			break;
		else if (choice == "1")
			Student_list = add_student(Student_list);//addStudent();
		else if (choice == "2")
			Student_list = delete_student(Student_list);//deleteStudent();
		else if (choice == "3")
			retrieve_name(Student_list);//retrieveStudentByName();
		else if (choice == "4")
			retrieve_usfid(Student_list);//retrieveStudentByID();
		else if (choice == "5")
			retrieve_email(Student_list);//retrieveStudentByEmail();
		else if (choice == "6")
			write_into(Student_list);//updateDataFields();
		else
			cout << "Invalid Number. Please try again." << endl;

		cout << endl;
	}

	return 0;
}