#include "Student_info.h";
using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        //get rid of previous contents
        hw.clear();
        double x;
        while(in >> x){
            hw.push_back(x);
        }
        //clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}
istream& read(istream& is, Student_info& s){

    //read and store name, final, and midterm
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework); //read and store all the student's homework grade

    return is;
}
