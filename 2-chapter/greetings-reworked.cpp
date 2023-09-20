#include <iostream>
#include <string>
using std::cin; using std::endl; using std::cout; using std::string;

int main() {
    //ask for name
    cout << "Please enter your first name: ";

    //read the name
    string name;

    cin >> name;

    //build the message that we intend to write
    const string greetings = "Hello " + name + "!";

    //number blanks surrounding the greeting
    const int pad = 1;

    //total number of rows to write
    const int rows = pad *2 + 3;

    const string::size_type cols = greetings.size() +pad * 2 + 2;

    cout << endl;

    for(int r = 0; r != rows; r++){
        string::size_type c =0;

        while(c !=cols ){
            //time to write the greetings?
            if(r == pad +1 && c== pad +1){
                cout << greetings;
                c+= greetings.size();
            }else{
                //border??
                if(r ==0 || r==rows-1 || c==0 || c==cols -1){
                    cout << "*";    
                }else{
                    cout << " ";
                }
                ++c;
                    
            }
        }
        cout << endl;
    }
}