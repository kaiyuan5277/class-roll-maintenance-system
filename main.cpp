#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>


using namespace std;
string getName();
string getUSFID();
string getEmail();
int getPresentationGrade();
int getEssayGrade();
int getTermProjectGrade();
void printMenu_Updata();

string getName()
{
	string firstName;
	string lastName;
	while (true)
	{
		//get name but make sure name is up to 40 characters or less. Try again if not correct.
		cout << "First Name: ";
		std::cin >> firstName;
		cout << "Last Name: ";
		std::cin >> lastName;
		if ((firstName.length() + lastName.length()) <= 40)
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Name must be less than 40 characters" << endl;
	}
	string name = firstName + " " + lastName;
	return name;
}

string getUSFID()
{

	string USFID;
	while (true)
	{
		//get USFID but make sure ID is equal to 10 characters or less. Try again if not correct.
		cout << "USFID: ";
		std::cin >> USFID;
		if (USFID.length() == 10)
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
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
		std::cin >> email;
		if (email.length() <= 40)
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Email must be less than 40 characters" << endl;
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
		std::cin >> gradeOfPresentation;
		if (!(std::cin.fail()) && (gradeOfPresentation <= 4 && gradeOfPresentation >= 0))
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
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
		std::cin >> gradeOfEssay;
		if (!(std::cin.fail()) && (gradeOfEssay <= 4 && gradeOfEssay >= 0))
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
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
		std::cin >> gradeOfTermProject;
		if (!(std::cin.fail()) && (gradeOfTermProject <= 4 && gradeOfTermProject >= 0))
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;
	}

	return gradeOfTermProject;
}


class Student
{	
public:
	bool operator == (const Student& s) const { return firstName == s.firstName && lastName == s.lastName && usfid == s.usfid && email == s.email && GradeofPresentation == s.GradeofPresentation && GradeofEssay == s.GradeofEssay && GradeofProject == s.GradeofProject; }
	bool operator != (const Student& s) const { return !operator == (s); }
	string firstName;
	string lastName;
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
		while (myfile >> stud.firstName >> stud.lastName >> stud.usfid >> stud.email >> stud.GradeofPresentation >> stud.GradeofEssay >> stud.GradeofProject) {
			cout << stud.firstName << " " << stud.lastName << " " << stud.usfid << " " << stud.email << " " << stud.GradeofPresentation << " " << stud.GradeofEssay << " " << stud.GradeofProject << "\n";
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
			myfile << itr->firstName << " " << itr->lastName << " " << itr->usfid << " " << itr->email << " " << itr->GradeofPresentation << " " << itr->GradeofEssay << " " << itr->GradeofProject << "\n";
		}
		myfile.close();
	}
}

list<Student> add_student(list<Student> Stud_list)
{
	Student stud;

	string firstname, lastname;
	string name = getName();
	stringstream ss(name);
	getline(ss, firstname, ' ');
	getline(ss, lastname);

	stud.firstName = firstname;
	stud.lastName = lastname;
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

	string firstname, lastname;
	cout << "Enter the first name you want to delete: ";
	std::cin >> firstname;
	cout << "Enter the last name you want to delete: ";
	std::cin >> lastname;
	Student stud;
	list<Student>::iterator itr;
	for ( itr = Stud_list.begin(); itr != Stud_list.end(); ++itr) {
	
		if (itr->firstName == firstname && itr->lastName == lastname) {
			
			stud.firstName = itr->firstName;
			stud.lastName = itr->lastName;
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
	string firstname, lastname;
	cout << "Enter the first name you want to retrieve: ";
	std::cin >> firstname;
	cout << "Enter the last name you want to retrieve: ";
	std::cin >> lastname;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->firstName == firstname && it->lastName == lastname) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}
void retrieve_usfid(list<Student> Student_list)
{
	string usfid;
	cout << "Enter the usf id you want to retrieve: ";
	std::cin >> usfid;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->usfid == usfid) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}

void retrieve_email(list<Student> Student_list)
{
	string email;
	cout << "Enter the email you want to retrieve: ";
	std::cin >> email;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->email == email) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}
}

list<Student> Updata_data(list<Student> Student_list)
{
	//list<Student> Stud_list;
	string firstname, lastname;
	string new_firstname, new_lastname, new_usfid, new_email;
	int new_GradeofPresentation,new_GradeofEssay, new_GradeofProject;

	Student stud, stud1;
	
	cout << "Enter the first name you want to modify: ";
	std::cin >> firstname;
	cout << "Enter the last name you want to modify: ";
	std::cin >> lastname;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->firstName == firstname && it->lastName == lastname) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
			stud1.firstName = it->firstName;
			stud1.lastName = it->lastName;
			stud1.usfid = it->usfid;
			stud1.email = it->email;
			stud1.GradeofPresentation = it->GradeofPresentation;
			stud1.GradeofEssay = it->GradeofEssay;
			stud1.GradeofProject = it->GradeofProject;
		}
	}
	Student_list.remove(stud1);
	for (list<Student>::iterator itr = Student_list.begin(); itr != Student_list.end(); ++itr) {
		
			cout << itr->firstName << " " << itr->lastName << " " << itr->usfid << " " << itr->email << " " << itr->GradeofPresentation << " " << itr->GradeofEssay << " " << itr->GradeofProject << "\n";
		
	}
	stud = stud1;
	

	while (true) {
		printMenu_Updata();
		int choice;
		
		std::cin >> choice;
		
		if (choice == 0) {
			
			break;
		}
		else if (choice == 1) {
			string name = getName();
			stringstream ss(name);
			getline(ss, new_firstname, ' ');
			getline(ss, new_lastname);

			stud.firstName = new_firstname;
			stud.lastName = new_lastname;
			
			continue;
		}
		else if (choice == 2) {
			stud.usfid = getUSFID();
			continue;
		}
		else if (choice == 3) {
			stud.email = getEmail();
			continue;
		}
		else if (choice == 4) {
			
			stud.GradeofPresentation = getPresentationGrade();
			continue;
		}
		else if (choice == 5) {
			stud.GradeofEssay = getEssayGrade();
			continue;
		}
		else if (choice == 6)
			stud.GradeofProject = getTermProjectGrade();
			continue;
	}
	Student_list.push_back(stud);
	return Student_list;
}
;

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

void printMenu_Updata() {
	cout << "****************************************************" << endl;
	cout << "which data you want to modify?" << endl;
	cout << "0. exit" << endl;
	cout << "1. name" << endl;
	cout << "2. student id" << endl;
	cout << "3. email" << endl;
	cout << "4. GradeofPresentation" << endl;
	cout << "5. GradeofEssay" << endl;
	cout << "6. GradeofProject" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
	cout << "Enter your choice [0-7]: ";

	return;
	
}
int main()
{
	
	list<Student> Student_list = read_student();

	while (true)
	{
		printMenu();
		string choice;
		std::cin >> choice;

		if (choice == "0")
			break;
		else if (choice == "1") {
			Student_list = add_student(Student_list);//addStudent();
			write_into(Student_list);
		}
		else if (choice == "2") {
			Student_list = delete_student(Student_list);//deleteStudent();
			write_into(Student_list);
		}
		else if (choice == "3")
			retrieve_name(Student_list);//retrieveStudentByName();
		else if (choice == "4")
			retrieve_usfid(Student_list);//retrieveStudentByID();
		else if (choice == "5")
			retrieve_email(Student_list);//retrieveStudentByEmail();
		else if (choice == "6") {
			Student_list = Updata_data(Student_list);
			write_into(Student_list);//updateDataFields();
		}
		else
			cout << "Invalid Number. Please try again." << endl;

		cout << endl;
	}

	return 0;
}