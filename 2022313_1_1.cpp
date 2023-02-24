#include <iostream>
#include <string>
using namespace std;

struct Address;
struct Person;
/* enum Education;
enum Department; */
struct Student;
struct Teacher;
struct Admin;
struct Course;

void addStudent();
void removeStudent();
void showAllStudents();
void addCourse();
void removeCourse();
void showAllCourses();
void addTeacher();
void removeTeacher();
void showAllTeachers();
void updateStudentDetails();
void updateTeacherDetails();
void updateCourseDetails();
void studentLogin();
void teacherLogin();
void showStudentData(Student*);
void enrollCourseMenu(Student*);
void showTeacherData(Teacher*);
void allocateCourseTeacher();
void deallocateCourseTeacher();
void showTeacherCourses(Teacher*);
void unenrollStudent();

Student* currStudent = NULL;
Teacher* currTeacher = NULL;


enum Std_Grade
{
    A,
    B,
    C,
    D,
    E,
    F
};

enum Department
{
    AI,
    DS,
    CS,
    EE,
    CE,
    ME,
    MGS
};

enum Education
{
    highschool,
    BS,
    MS,
    PHD
};



struct Address
{
    string current;
    string permanent;
};

struct Person
{
    string name;
    int age;
    Address address;
    Education education_level;
};

struct Student
{

    int roll_no;
    Person personal;
    Department department;
    //Course enrolledCourses[10];
    //int numOfEnrolledCourses = 0;
   /* Course droppedCourses[10];
    int numOfDroppedCourses = 0;
    Course completedCourses[10];
    int numOfCompletedCourses = 0; */



    void clearData(){
        roll_no = 0;
        personal.address.current = "";
        personal.address.permanent = "";        
        personal.age = 0;
        personal.name = "";

    }


};


struct Course
{
    string courseName;
    string courseCode;
    string teacher;
    Student enrolled_students[50];
    int totalEnrolledSpots = 0;
    Student dropped_students[50];
    int totalDroppedSpots = 0;
    Student graded_students[50];

};



struct Teacher
{
    Person personal;
    int salary;
    Department department;
    Course assignedCourses[10];
    int totalAssignedCourses = 0;
};

struct Admin
{
    Person personal;
    int salary;
};


struct Grade
{
    Std_Grade std_grade;
    int marks;
};

void showAdminPage()
{
    int choice;
    cout << "1. Add a new student in system." << endl;
    cout << "2. Remove a student from system." << endl;
    cout << "3. Update student detail" << endl;
    cout << "4. Check record of all students" << endl;
    cout << "5. Un-enroll a student from a course" << endl;
    cout << "6. Add a new teacher in system." << endl;
    cout << "7. Remove a teacher from system." << endl;
    cout << "8. Update teacher detail" << endl;
    cout << "9. Check record of all teachers" << endl;
    cout << "10. Add a course in system" << endl;
    cout << "11. Remove course from system" << endl;
    cout << "12. Update course detail" << endl;
    cout << "13. Check record of all courses" << endl;
    cout << "14. Allocate a course to teacher" << endl;
    cout << "15. De-allocate a course from teacher" << endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
        addStudent();
        break;
    case 2:
        removeStudent();
        break;

    case 3:
        updateStudentDetails();
        break;
    
    case 4:
        showAllStudents();
        break;

    case 5:
        unenrollStudent();
        break;
    case 6:
        addTeacher();
        break;
    case 7:
        removeTeacher();
        break;

    case 8:
        updateTeacherDetails();
        break;
        
    case 9:
        showAllTeachers();
        break;

    case 10:
        addCourse();
        break;

    case 11:
        removeCourse();
        break;

    case 12:
        updateCourseDetails();
        break;
    case 13:
        showAllCourses();
        break;

    case 14:
        allocateCourseTeacher();
        break;

    case 15:
        deallocateCourseTeacher();
        break;

    default:
        break;
    }
}
void showTeacherPage(){
    cout << "1. Check his/her details or data" <<endl;
    cout << "2. See list of all courses allocated to him" <<endl;
    cout << "3. See list of all students enrolled in each course separately" <<endl;
    cout << "4. Assign marks and grade to each student." <<endl;
    cout << "5. See the top student in his/her class after marking/grading" <<endl;
    cout << "6. Grade-wise division of students in course allocated to him" <<endl;
    int choice;
    cin >> choice;

    switch (choice){
    case 1:
        showTeacherData(currTeacher);
        break;

    case 2:
        showTeacherCourses(currTeacher);
        break;
    
    
    default:
        break;
    }




}

void showStudentData(Student* student)
{
    cout << student->roll_no << endl;
    cout << student->department << endl;
    cout << student->personal.age << endl;
    cout << student->personal.education_level << endl;
    cout << student->personal.name << endl;
    cout << student->personal.address.current << endl;
    cout << student->personal.address.permanent << endl;
}

void showStudentPage()
{

    int choice;

    cout << "Press appropriate number for option:" << endl;
    cout << "1. Check his/her details or data " << endl;
    cout << "2. Enroll any available course" << endl;
    cout << "3. See his/her final grade" << endl;
    cout << "4. See list of his/her teachers" << endl;
    cout << "5. See list of his/her enrolled courses" << endl;
    cout << "6. See list of his/her dropped courses" << endl;
    cout << "7. See list of his/her completed courses" << endl;

    cin >> choice;

    switch(choice){
        case 1:
            showStudentData(currStudent);
            break;
        case 2:
            enrollCourseMenu(currStudent);
            break;

        default:

            break;
    }

    /*  if(choice == 1){
          showStudentData(currStudent);
      }
      else if(choice == 2){
          enrollCourseMenu();
      }
      else if(choice == 3){
          showStudentGrade();
      }
      else if(choice == 4){
          showStudentTeachers();
      }
      else if(choice == 5){
          showEnrolledCourses();
      }
      else if(choice == 6){
          showDroppedCourses();
      }
      else if(choice == 7){
          showCompletedCourses();
      }
   */
}

void showMainMenu()
{   //int isStudent;

    int choice = 0;
    cout << "choose your number: " << endl;
    cout << "1. Admin \n2. Teacher\n3. Student\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        showAdminPage();
        break;
    case 2:
        //isStudent = 0;
        teacherLogin();
        showTeacherPage();
        break;
    case 3:
        //isStudent = 1;
        //Student* currStudent;
        studentLogin();
        showStudentPage();
        break;

    default:

        showMainMenu();
        break;
    }
}

void increaseListSize(int *list, int *listSize)
{
    int *temp = list;
    list = new int[*listSize + 1];
    for (int i = 0; i < *listSize; i++)
    {
        list[i] = temp[i];
    }
    *listSize = *listSize + 1;
    delete[] temp;
}

void increaseListSize(Student* list, int* listSize){
    Student* temp = new Student[*listSize ];

    for(int i = 0; i < *listSize; i++){
        temp[i] = list[i];
    }

    list = NULL;

    list = new Student[*listSize + 1];
    for(int i = 0; i <*listSize; i++){
        list[i] = temp[i];
    }
    *listSize = *listSize + 1;
    delete[] temp;
}

/* void increaseListSize(Student *list, int *listSize)
{
    Student *temp = list;
    list = temp;
    Student *newList = new Student[listSize + 1];
    for (int i = 0; i < listSize; i++)
    {
        newList[i] = temp[i];
    }
    *listSize = *listSize + 1;
    list = newList;
    delete[] temp;
} */

Student studentList[100];
int studentListSize = 0;
int *ptrStudentListSize = &studentListSize;
Teacher teacherList[100];
int teacherListSize = 0;
int *ptrTeacherListSize = &teacherListSize;
Course courseList[100];
int courseListSize = 0;
int *ptrCourseListSize = &courseListSize;




void addStudent()
{
    
    *ptrStudentListSize = *ptrStudentListSize + 1;
    cout << "Enter student Name: ";
    cin >>  studentList[studentListSize - 1].personal.name;
    cout << "Enter student Age: ";
    cin >> studentList[studentListSize - 1].personal.age;
    cout << "Enter student Current Address: ";
    cin >> studentList[studentListSize - 1].personal.address.current;

    //studentList[studentListSize - 1].roll_no = 123;
    
}


void removeStudent(){
    string name;
    cout << "Enter the name of the student you want to remove: ";
    cin >> name;

    for(int i = 0; i < studentListSize; i++){
        if(name == studentList[i].personal.name){
            Student clean;
            studentList[i] = clean;

            break;
        }
        
    }

}


void updateStudentDetails(){
    string name;
    cout << "Enter the name of the student you want to edit: ";
    cin >> name;

    for(int i = 0; i < studentListSize; i++){
        if(name == studentList[i].personal.name){
            cout << "Enter student's new Name: ";
            cin >>  studentList[i].personal.name;
            cout << "Enter student's new Age: ";
            cin >> studentList[i].personal.age;
            cout << "Enter student's new Current Address: ";
            cin >> studentList[i].personal.address.current;
            break;
        }


}
}


void showAllStudents(){
    cout << "These are all the students: " <<endl;
    for(int i = 0; i < studentListSize ; i++){
        cout << "Student " <<i+1<< ". Name: " << studentList[i].personal.name <<endl;
    }
    cout <<endl;
}


void addCourse(){
    *ptrCourseListSize = *ptrCourseListSize + 1;
    cout << "Enter course Name: ";
    cin >> courseList[courseListSize - 1].courseName;
    cout << "Enter course Code: ";
    cin >> courseList[courseListSize - 1].courseCode;
}

void removeCourse(){
    string name;
    cout << "Enter the name of the course you want to remove: ";
    cin >> name;

    for(int i = 0; i < courseListSize; i++){
        if(name == courseList[i].courseName){
            Course clean;
            courseList[i] = clean;

            break;
        }
    }
}

void updateCourseDetails(){
    string name;
    cout << "Enter the name of the course you want to edit: ";
    cin >> name;

    for(int i = 0; i < courseListSize; i++){
        if(name == courseList[i].courseName){
            cout << "Enter course's new name: ";
            cin >>  courseList[i].courseName;
            cout << "Enter course's new code: ";
            cin >> courseList[i].courseCode;
            break;
        }

    }
}


void showAllCourses(){
    cout << "These are all the courses: " <<endl;
    for(int i = 0; i < courseListSize ; i++){
        cout << "Course " <<i+1<< ". Name: " << courseList[i].courseName <<endl;
        cout << "Number of enrolled students: " << courseList[i].totalEnrolledSpots <<endl;
        for(int j = 0; j < courseList[i].totalEnrolledSpots;j++){
            cout << "Student " << i+1 << "details: " <<endl;
            showStudentData(&courseList[i].enrolled_students[j]);

        }
    }
    cout <<endl;
}

void addTeacher(){
    
    *ptrTeacherListSize = *ptrTeacherListSize + 1;
    cout << "Enter Teacher Name: ";
    cin >>  teacherList[teacherListSize - 1].personal.name;
    cout << "Enter Teacher Age: ";
    cin >> teacherList[teacherListSize - 1].personal.age;
    cout << "Enter Teacher Current Address: ";
    cin >> teacherList[teacherListSize - 1].personal.address.current;

}

void removeTeacher(){
    string name;
    cout << "Enter the name of the teacher you want to remove: ";
    cin >> name;

    for(int i = 0; i < teacherListSize; i++){
        if(name == teacherList[i].personal.name){
            Teacher clean;
            teacherList[i] = clean;

            break;
        }
    }

}


void showAllTeachers(){
    cout << "These are all the teachers: " <<endl;
    for(int i = 0; i < teacherListSize ; i++){
        cout << "Teacher " <<i+1<< ". Name: " << teacherList[i].personal.name <<endl;
    }
    cout <<endl;
}

void updateTeacherDetails(){
    string name;
    cout << "Enter the name of the teacher you want to edit: ";
    cin >> name;

    for(int i = 0; i < teacherListSize; i++){
        if(name == teacherList[i].personal.name){
            cout << "Enter teacher's new Name: ";
            cin >>  teacherList[i].personal.name;
            cout << "Enter teacher's new Age: ";
            cin >> teacherList[i].personal.age;
            cout << "Enter teacher's new Current Address: ";
            cin >> teacherList[i].personal.address.current;
            break;
        }

    }
}

void teacherLogin(){
    string name;
    cout << "Enter your official Teacher name: ";
    cin >> name;

    for(int i = 0; i < teacherListSize; i++){
        if(name == teacherList[i].personal.name){
            currTeacher = &teacherList[i];

            break;
        }
        
    }

}


void studentLogin(){
    string name;
    cout << "Enter your official Student name: ";
    cin >> name;

    for(int i = 0; i < studentListSize; i++){
        if(name == studentList[i].personal.name){
            currStudent = &studentList[i];

            break;
        }
        
    }

}


void enrollCourseMenu(Student* student){    
    showAllCourses();
    int choice;
    cout << "Enter the appropriate number to enroll in that course." <<endl;
    cin >> choice;
    courseList[choice - 1].enrolled_students[courseList[choice - 1].totalEnrolledSpots] = *student;
    courseList[choice - 1].totalEnrolledSpots += 1;

}

void showTeacherData(Teacher* teacher){

    //cout << teacher->roll_no << endl;
    cout << teacher->department << endl;
    cout << teacher->personal.age << endl;
    cout << teacher->personal.education_level << endl;
    cout << teacher->personal.name << endl;
    cout << teacher->personal.address.current << endl;
    cout << teacher->personal.address.permanent << endl;
}

void allocateCourseTeacher(){
    cout <<"Enter teacher's name who you want to allocate course to: "<<endl;
    string name;
    cin >> name;
    showAllCourses();
    cout <<"What course do you want to assign to this teacher: " <<endl;
    int courseNum;
    cin >> courseNum;

    for(int i = 0; i < teacherListSize; i++){
        if(name == teacherList[i].personal.name){
            teacherList[i].assignedCourses[teacherList[i].totalAssignedCourses] = courseList[courseNum - 1];
            teacherList[i].totalAssignedCourses += 1;

            break;
        }

    }
}


void deallocateCourseTeacher(){
    cout <<"Enter teacher's name who you want to deallocate a course from: "<<endl;
    string name;
    cin >> name;
    for(int i = 0; i < teacherListSize; i++){
        if(name == teacherList[i].personal.name){
            currTeacher = &teacherList[i];

            break;
        }
    }

    showTeacherCourses(currTeacher);
    cout <<"What course do you want to deallocate from this teacher: " <<endl;
    int courseNum;
    cin >> courseNum;
    Course clean;
    currTeacher->assignedCourses[courseNum - 1] = clean;
}

void showTeacherCourses(Teacher* teacher){
    cout << "These are the courses that are allocated: " <<endl;

    for(int i = 0; i < teacher->totalAssignedCourses; i++){
        cout << "Course Number " <<i+1<< ". Course Name: " << teacher->assignedCourses[i].courseName << endl;

    }


}


void unenrollStudent(){

    showAllCourses();
    cout << "Enter course number you want to unenroll from: " <<endl;
    int courseNum;
    cin >> courseNum;
    cout << "Enter the name of the student you want to unenroll from this course: "<<endl;
    string name;
    cin >> name;
    Student clear;
    clear.clearData();
    int remPos = 0;
    for(;remPos < courseList[courseNum - 1].totalEnrolledSpots; remPos++){
        if(name == courseList[courseNum - 1].enrolled_students[remPos].personal.name){
            break;
        }
    }
    courseList[courseNum - 1].dropped_students[courseList[courseNum - 1].totalDroppedSpots] = courseList[courseNum - 1].enrolled_students[remPos]; 
    courseList[courseNum - 1].totalDroppedSpots += 1;
    courseList[courseNum - 1].enrolled_students[remPos] = clear;

}


int main()
{
    
    for(;;){
        showMainMenu();
    }
    

}