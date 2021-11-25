#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include <stdexcept>
using namespace std;
enum status
{
    HEALTHY,
    ILL
};
class doctor
{

private:
    friend class patient;
    string name;
    int xp = 0; //experience of player
    int energy = 100;
    int credit = 0;
    static int coin;

public:
    doctor(string a_name); //constructor
    //doctor(const doctor& copy);          //copy constructor
    void set_xp(int status);               //set experience
    int get_xp() const;                    //return experience value
    void set_energy(int time, int status); // set energy after each patient
    int get_energy() const;                //return enegy value
    void set_credit(int status);
    int get_credit() const;                //return credit value
    void set_coin( int amount); //set amount of con
    int get_coin();                        //return coin
    void boost_energy();                   //decrease xp,increase energy
};

#endif