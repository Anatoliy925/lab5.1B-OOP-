#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>
#include <string>
using namespace std;

class Exception{
    string message;
public:
    Exception(string message): message(message){}
    string What(){return message;}
};

#endif
