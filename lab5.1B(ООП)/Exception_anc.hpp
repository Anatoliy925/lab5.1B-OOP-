#ifndef Exception_anc_hpp
#define Exception_anc_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Exception_anc: public exception{
    string message;
public:
    Exception_anc(string message): message(message){}
    string What(){return message;}
};


#endif
