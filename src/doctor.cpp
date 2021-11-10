#include "../include/doctor.hpp"
using namespace std;
doctor::doctor(char *a_name)
    : name{a_name}
{
}
/*****************************************************/
/*****************************************************/
// set_xp method
void doctor::set_xp(int status) //status 0 = healthe person-----status 1 = sick person
{
    try
    {
        if (status == 0)
        {
            xp = xp + 10;
        }
        if (status == 1)
        {
            xp = xp + 5;
        }
        if (status != 0 && status != 1)
        {
            throw out_of_range("Error....input status is invalid!!");
        }
    }
    catch (out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
}
//End of set_xp method
/*****************************************************/
/*****************************************************/
//get_xp method
int doctor::get_xp() const
{
    return xp;
}
//get_xp method
/*****************************************************/
/*****************************************************/
//set_energy functio
void doctor::set_energy(int time, int status)
{
    try
    {
        if (time > 20)
        {
            throw out_of_range("Error...Maximum of each patient is 20 minuts!!!");
        }
        energy = energy - time * 0.5;
        if (status == 0)
        {
            energy += 2;
        }
        if (status == 1)
        {
            energy -= 5;
        }
        if (status != 0 && status != 1)
        {
            throw out_of_range("Error....input status is invalid!!");
        }
        if (energy <= 0)
        {
            cout << "Game Over!!!" << endl;
        }
        
    }
    catch (out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}
//End of set_energy method
/*****************************************************/
/*****************************************************/
//get_energy method
int doctor ::get_energy() const
{
    return energy;
}
//End of get_energy method
/*****************************************************/
/*****************************************************/
//set_credit method 
void doctor::set_credit(int status)
{
    try
    {
        if (status == 0)
        {
            credit = credit + 5;
        }
        if (status == 1)
        {
            credit = credit - 5;
        }
        if (status != 0 && status != 1)
        {
            throw out_of_range("Error....input status is invalid!!");
        }
    }
    catch (out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
}
//End of set_credit method
/*****************************************************/
/*****************************************************/
//get_credit method
int doctor::get_credit() const
{
    return credit;
}
//End of get_credit method
/*****************************************************/
/*****************************************************/
//boost_energy
void doctor::boost_energy()
{
    if (xp > 10)
    {
        xp -= 5;
        energy += 5;
    }else
    {
        cout << "Access Denied!!!" << endl;
    }
}
//End of boost_energy
/*****************************************************/
/*****************************************************/