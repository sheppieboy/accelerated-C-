#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;
using std::max;

//predicate to determine whether a student failed
bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info>fail;

    vector<Student_info>::iterator iter = students.begin();
    
    while( iter != students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }else{
            ++iter;
        }
    }
    
   
    return fail;
}


//iterator to print students names
int print_students(const vector<Student_info>&students){
    for(vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); iter++){
        //dereferencing returns an lvalue and that lvalue is the value that iter is referencing
         cout << (*iter).name <<endl; // OR cout << iter->name << endl ...... This is known as dereferencing
    }
    return 0;
}


int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen =0; //length of longest name
    //read and store all the students data
    while(read(cin, record)){
        //find longest length name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    //sort
    sort(students.begin(), students.end(), compare);
    
    //write the anmes and grades
    for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
        //write name, padded on teh right to maxlen + 1 character
        cout << students[i].name << string(maxlen+1 -students[i].name.size(), ' ');
        //compute and write the grade
        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }catch(domain_error e){
            cout << e.what();
        }
        cout << endl;
    }

    return 0;

}




