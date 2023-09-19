//ask for a person's name
#include <iostream>
#include <string>

int main(){
    //ask for a person's name
    std::cout << "Please enter your first name: ";

    //read the name
    std::string name; //define a name
    std::cin >> name; //read into name

    //build greetings
    const std::string greetings = "Hello, " + name + "!";

    //build the second and fourth lines of the output
    const std::string spaces(greetings.size(), ' ');
    const std::string second = "* "+spaces+" *";

    //build the first and fifth lines
    const std::string first(second.size(), '*');

    //write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second <<std::endl;
    std::cout << "* " << greetings << " *" <<std::endl;
    std::cout << second <<std::endl;
    std::cout << first<<std::endl;
    return 0;
    

}