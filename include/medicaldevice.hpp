#ifndef MEDICALDIVICE_H
#define MEDICALDIVICE_H
#include <iostream>
using namespace std;
class device{
private:
    char* name;
    int count;//count of each device
public:
    device(char* a_name, int a_count);
    
};

#endif