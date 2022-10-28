// Colten Vance Mikulastik
// these are notes for helping people understand c-strings and std::strings :^)

#include <iostream>
#include <string>

int main()
{
    
    std::cout << "Hello World!\n"; //string literal

    char str[] = "name here"; // this is actually a c-string, because array of characters
    // can be printed with std::cout
    std::cout << str;

    //lets look at the characters
    for (int i = { 0 }; i <= strlen(str); i++)
    {
        // you can also print the characters one by one
        std::cout << str[i] << std::endl;
    }

    // when we try to assign a new variable
    char *str2 = str;

    // what happens when we print?
    // they will point to the same array
    std::cout << str2 << ": string 2" << std::endl;

    std::cout << &str2 << ": string 2" << std::endl;
    std::cout << &str << ": string 1" << std::endl;
        
    //we can also prove that here
    if (str2 == str) { std::cout << "both string 1 and 2 are the same pointers" << std::endl; }
    else { std::cout << "not equal!" << std::endl; }

    // so make sure to not double delete
    str2 = nullptr;

    int fi[] = {1,2,3,4};
    
    std::cout << &fi << std::endl;


    std::cout << "STRING OBJECT" << std::endl;
    // gonna create a string obj now see if they work better
    std::string beta("Hello!");
    std::string alpha (beta);

    std::cout << beta << std::endl;

}
