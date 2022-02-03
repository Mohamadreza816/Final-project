#include "doctor.h"
using namespace std;
//constructor
doctor::doctor(string a_name, QObject *parent) : QObject(parent)
{
    name = a_name;
}

//set static var
int doctor::coin = 30;
int doctor::energy = 100;
int doctor::xp = 0;
int doctor::credit = 0;

//set xp method
void doctor::set_xp(int status)
{
    try
    {
        if (status == HEALTHY)
        {
            xp = xp + 10;
        }
        if (status == ILL)
        {
            xp = xp + 5;
        }
        if (status != HEALTHY && status != ILL)
        {
            throw out_of_range("Error....input status is invalid!!");
        }
    }
    catch (out_of_range &e)
    {
        cerr << e.what() << endl;
    }
}

//return xp value and emit that signal
int doctor::get_xp() const
{
    emit noticexp(QVariant(xp));
    return xp;
}

//set energy method
void doctor::set_energy(int time, int status)
{
    try
    {
        if (time > 20)
        {
            throw out_of_range("Error...Maximum of each patient is 20 minuts!!!");
        }
        energy = energy - (time * 0.5);
        if (status == HEALTHY)
        {
            energy += 2;
        }
        if (status == ILL)
        {
            energy -= 5;
        }
        if (status != HEALTHY && status != ILL)
        {
            throw out_of_range("Error....input status is invalid!!");
        }
        if (energy <= 0)
        {

            cout << "Game Over!!!" << endl;
            //exit(0);
        }
    }
    catch (out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
}

//return energy value and emit that signal
int doctor ::get_energy() const
{
    if(energy <= 0)
    {
        energy = 0;
        emit noticeenergy(QVariant(energy));
        emit gameover(QVariant ("Game over"));
    }
    emit noticeenergy(QVariant(energy));
    return energy;
}

//set credit value method
void doctor::set_credit(int status)
{
    try
    {
        if (status == HEALTHY)
        {
            credit = credit + 5;
        }
        if (status == ILL)
        {
            credit = credit - 5;
        }
        if (status != HEALTHY && status != ILL)
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
//get_credit method and emit that signal
int doctor::get_credit() const
{
    emit noticecredit(QVariant(credit));
    return credit;
}
//End of get_credit method
/*****************************************************/
/*****************************************************/
//set_coint method
void doctor::set_coin(int amount)
{
    //amount depend os patient grade
    coin = coin + amount;

}
//End of set coin method
/*****************************************************/
/*****************************************************/
//return coin method and emit that signal
int doctor::get_coin()
{
    emit noticemessagedoctor("");
    emit noticecoin(QVariant(coin));
     return coin;
}
//End
/*****************************************************/
/*****************************************************/
//boost_energy method and emit signal
void doctor::boost_energy()
{
    if (xp > 10 && energy < 96)
    {
        xp -= 10;
        energy += 5;
        emit noticexp(QVariant(xp));
        emit noticeenergy(QVariant(energy));
    }
    else
    {
        emit noticemessagedoctor("You can't boost energy!");
        cout << "Access Denied!!!" << endl;
    }
}
//End of boost_energy
/*****************************************************/
/*****************************************************/

