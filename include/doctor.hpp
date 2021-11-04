#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <stdexcept>
using namespace std;

class doctor
{
    
private:
    friend class patient;
    char* name;
    int xp = 0;//experience of player
    int energy = 100;
    int credit = 0;
public:
    doctor(char* a_name);//constructor
    //doctor(const doctor& copy);//copy constructor
    void set_xp(int status);//set experience
    int get_xp();//return experience value
    void set_energy(int time, int status);// set energy after each patient
    int get_energy();//return enegy value
    void set_credit(int status);
    int get_credit();//return credit value
    void boost_energy();//decrease xp,increase energy 
};

#endif