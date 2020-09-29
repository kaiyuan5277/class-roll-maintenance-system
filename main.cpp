#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>


using namespace std;

string getName();//function for get name
string getUSFID();//function for get usf id
string getEmail();//function for get email
int getPresentationGrade();//function for get presentation grade
int getEssayGrade();//function for get essay grade
int getTermProjectGrade();//function for get project grade
void printMenu_Updata();//function for update data menu

string getName()
{
	string firstName;
	string lastName;
	while (true)
	{
		//get name but make sure name is up to 40 characters or less. Try again if not correct.
		cout << "First Name: ";
		std::cin >> firstName;//get first name
		cout << "Last Name: ";
		std::cin >> lastName;//get last name
		if ((firstName.length() + lastName.length()) <= 40)//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Name must be less than 40 characters" << endl;//output error
	}
	string name = firstName + " " + lastName;//get full name
	return name;
}

string getUSFID()
{

	string USFID;
	while (true)
	{
		//get USFID but make sure ID is equal to 10 characters or less. Try again if not correct.
		cout << "USFID: ";
		std::cin >> USFID;//get usf id
		if (USFID.length() == 10)//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "USFID must be 10 characters" << endl;//output error
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
		std::cin >> email;//get email address
		if (email.length() <= 40)//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Email must be less than 40 characters" << endl;//output error
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
		std::cin >> gradeOfPresentation;//get grade of presentation
		if (!(std::cin.fail()) && (gradeOfPresentation <= 4 && gradeOfPresentation >= 0))//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;//output error
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
		std::cin >> gradeOfEssay;//get grade of essay
		if (!(std::cin.fail()) && (gradeOfEssay <= 4 && gradeOfEssay >= 0))//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;//output error
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
		std::cin >> gradeOfTermProject;//get the grade of project
		if (!(std::cin.fail()) && (gradeOfTermProject <= 4 && gradeOfTermProject >= 0))//check condition
			break;
		std::cin.clear();
		std::cin.ignore(123, '\n');
		cout << "Must be number between 0 and 4" << endl;//output error
	}

	return gradeOfTermProject;
}


class Student//declare a class of student
{	
public:
	//declare a bool operator == and !=
	bool operator == (const Student& s) const { return firstName == s.firstName && lastName == s.lastName && usfid == s.usfid && email == s.email && GradeofPresentation == s.GradeofPresentation && GradeofEssay == s.GradeofEssay && GradeofProject == s.GradeofProject; }
	bool operator != (const Student& s) const { return !operator == (s); }
	string firstName;//declare first name
	string lastName;//declare last name
	string usfid;//declare usf id
	string email;//declare email address
	int GradeofPresentation = 0;//declare grade of presentation, initial as 0
	int GradeofEssay = 0;//declare grade of essay, initial as 0
	int GradeofProject = 0;//declare grade of project, initial as 0
}
;

//function for read student from text file
list<Student> read_student()
{
	list<Student> Student_list;//declare a list for a class Student
	Student stud;//declare a student of a class
	fstream myfile;//declare a stream file

	myfile.open("student.txt");//open file
	if (myfile.is_open()) {//if file is open, add elements into the list
		while (myfile >> stud.firstName >> stud.lastName >> stud.usfid >> stud.email >> stud.GradeofPresentation >> stud.GradeofEssay >> stud.GradeofProject) {
			cout << stud.firstName << " " << stud.lastName << " " << stud.usfid << " " << stud.email << " " << stud.GradeofPresentation << " " << stud.GradeofEssay << " " << stud.GradeofProject << "\n";
			Student_list.push_back(stud);
		}
		myfile.close();
	}

	
	return Student_list;//return list
}

void write_into(list<Student> Student_list)//write data into file
{
	ofstream myfile;//declare a file
	myfile.open("student.txt", ofstream::out | ofstream::trunc);//clean file
	
	list<Student>::iterator itr;//declare a iterator
	if (myfile.is_open()) {//write the list into file
		for (itr = Student_list.begin(); itr != Student_list.end(); ++itr) {
			myfile << itr->firstName << " " << itr->lastName << " " << itr->usfid << " " << itr->email << " " << itr->GradeofPresentation << " " << itr->GradeofEssay << " " << itr->GradeofProject << "\n";
		}
		myfile.close();
	}
}

list<Student> add_student(list<Student> Stud_list)//function for adding student into file
{
	Student stud;//declare a student

	string firstname, lastname;//declare variables
	string name = getName();//get name by calling function getName()
	stringstream ss(name);
	getline(ss, firstname, ' ');
	getline(ss, lastname);

	stud.firstName = firstname;//get first name and last name
	stud.lastName = lastname;
	stud.usfid = getUSFID();//get usf id by calling function 
	stud.email = getEmail();//get email by calling function 
	stud.GradeofPresentation = getPresentationGrade();//get presentation grade by calling function 
	stud.GradeofEssay = getEssayGrade();//get essay grade by calling function 
	stud.GradeofProject = getTermProjectGrade();//get project grade by calling function 
	
	Stud_list.push_back(stud);//add into list
	return Stud_list;//return list
	
}

list<Student> delete_student(list<Student> Stud_list)//function for deleting a student from list
{

	string firstname, lastname;
	cout << "Enter the first name you want to delete: ";
	std::cin >> firstname;//get the first name
	cout << "Enter the last name you want to delete: ";
	std::cin >> lastname;//get last name
	Student stud;//declare a new student
	list<Student>::iterator itr;
	for ( itr = Stud_list.begin(); itr != Stud_list.end(); ++itr) {//search a student from begin to end
	
		if (itr->firstName == firstname && itr->lastName == lastname) {//if find the student
			
			//add student's data into a new student
			stud.firstName = itr->firstName;
			stud.lastName = itr->lastName;
			stud.usfid = itr->usfid;
			stud.email = itr->email;
			stud.GradeofPresentation = itr->GradeofPresentation;
			stud.GradeofEssay = itr->GradeofEssay;
			stud.GradeofProject = itr->GradeofProject;
		}
		
	}
	Stud_list.remove(stud);//delete student 
	return Stud_list;//return new list
};

void retrieve_name(list<Student> Student_list)//function for retrieve name
{
	string firstname, lastname;//ask name for retrieve
	cout << "Enter the first name you want to retrieve: ";
	std::cin >> firstname;
	cout << "Enter the last name you want to retrieve: ";
	std::cin >> lastname;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {//search in the list
		if (it->firstName == firstname && it->lastName == lastname) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}//if find student, then print the data
	}
}
void retrieve_usfid(list<Student> Student_list)//function for retrieve by usf id
{
	string usfid;
	cout << "Enter the usf id you want to retrieve: ";
	std::cin >> usfid;//get usf id
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {//search in the list
		if (it->usfid == usfid) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}//if find the id, then print the information
	}
}

void retrieve_email(list<Student> Student_list)//function for retrieve by email
{
	string email;
	cout << "Enter the email you want to retrieve: ";
	std::cin >> email;//get email address
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->email == email) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
		}
	}//search through the list, if find the email, then print the information
}

list<Student> Updata_data(list<Student> Student_list)//function for modify data then update
{
	//declare variables
	string firstname, lastname;
	string new_firstname, new_lastname;

	Student stud, stud1;
	//get the name of a student who need to be modified
	cout << "Enter the first name you want to modify: ";
	std::cin >> firstname;
	cout << "Enter the last name you want to modify: ";
	std::cin >> lastname;
	list<Student>::iterator it;
	for (it = Student_list.begin(); it != Student_list.end(); ++it) {
		if (it->firstName == firstname && it->lastName == lastname) {
			cout << it->firstName << " " << it->lastName << " " << it->usfid << " " << it->email << " " << it->GradeofPresentation << " " << it->GradeofEssay << " " << it->GradeofProject << "\n";
			stud1.firstName = it->firstName;//get the student's data into stud1
			stud1.lastName = it->lastName;
			stud1.usfid = it->usfid;
			stud1.email = it->email;
			stud1.GradeofPresentation = it->GradeofPresentation;
			stud1.GradeofEssay = it->GradeofEssay;
			stud1.GradeofProject = it->GradeofProject;
		}
	}//find the student then delete it
	Student_list.remove(stud1);
	stud = stud1;//save the student's data into stud
	

	while (true) {
		printMenu_Updata();//print menu
		int choice;
		
		std::cin >> choice;//get choice
		
		if (choice == 0) {//exit
			
			break;
		}
		else if (choice == 1) {//modify name
			string name = getName();
			stringstream ss(name);
			getline(ss, new_firstname, ' ');
			getline(ss, new_lastname);

			stud.firstName = new_firstname;
			stud.lastName = new_lastname;
			
			continue;
		}
		else if (choice == 2) {//modify usf id
			stud.usfid = getUSFID();
			continue;
		}
		else if (choice == 3) {//modify email
			stud.email = getEmail();
			continue;
		}
		else if (choice == 4) {//modify grade of presentation
			
			stud.GradeofPresentation = getPresentationGrade();
			continue;
		}
		else if (choice == 5) {//modify the grade of essay
			stud.GradeofEssay = getEssayGrade();
			continue;
		}
		else if (choice == 6) {//modify the grade of project
			stud.GradeofProject = getTermProjectGrade();
			continue;
		}
		else
			cout << "Invalid Number. Please try again." << endl;
	}
	Student_list.push_back(stud);//add new student into list
	return Student_list;
}
;

void printMenu()//the menu for the interface
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

void printMenu_Updata() {//menu for update data fields
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
	
	list<Student> Student_list = read_student();//read data from a text file

	while (true)//while loop to call interface 
	{
		printMenu();
		string choice;
		std::cin >> choice;

		if (choice == "0")//exit
			break;
		else if (choice == "1") {// addStudent and update the text file
			Student_list = add_student(Student_list);
			write_into(Student_list);
		}
		else if (choice == "2") {// delete student and update the text file
			Student_list = delete_student(Student_list);
			write_into(Student_list);
		}
		else if (choice == "3")
			retrieve_name(Student_list);//retrieveStudentByName();
		else if (choice == "4")
			retrieve_usfid(Student_list);//retrieveStudentByID();
		else if (choice == "5")
			retrieve_email(Student_list);//retrieveStudentByEmail();
		else if (choice == "6") {//update Data Fields then write into text file
			Student_list = Updata_data(Student_list);
			write_into(Student_list);
		}
		else
			cout << "Invalid Number. Please try again." << endl;

		cout << endl;
	}

	return 0;
}