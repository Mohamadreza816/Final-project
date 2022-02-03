#include "ampoule.h"

//static var
int ampoule::count_ampoule = 0;
//constuctor
ampoule::ampoule(string a, QObject *parent) : device(a)
{
    name = a;
}
//end of constructor
/*****************************************************/
/*****************************************************/
//buy method for ampoule and emit signal
void ampoule::buy()
{
    //price of ampoule is 10 coin
    doctor d{"doc"};
    int sum = 1 * 10;
    if (d.get_coin() >= sum)
    {
        d.set_coin(-sum);                    //decrease amount of coin
        count_ampoule = count_ampoule + 1; //increase ampoule count
        emit noticgetampoulecount(QVariant(count_ampoule));//update count of ampoule
        emit noticeampoulemessage(QVariant (""));//no error message
    }
    else
    {
        emit noticeampoulemessage(QVariant ("count of coin isn't enough!"));//error message
        //throw out_of_range("count of coin isn't enough!");
    }
}
//End of buy method
/*****************************************************/
/*****************************************************/
// use method for ampoule and emit signal
bool ampoule::use()
{

    doctor d{"doc"};
    if (d.get_xp() >= 30)
    {
        if( count_ampoule > 0)
        {
             count_ampoule--; //decrease ampoule count
            emit noticegetpillcount(QVariant(count_ampoule));//update count of ampoulw
             emit noticeampoulemessage(QVariant (""));//no error message
        }
    }
    else
    {
        emit noticeampoulemessage(QVariant ("your experience isn't enough for use ampoule!"));
        //throw invalid_argument("your experience isn't enough for use ampoule!");
    }

    return true;
}
//End of use method for ampoule
/*****************************************************/
/*****************************************************/
//get count ampoule method and emit signal
int ampoule::get_count()
{
     emit noticgetampoulecount(QVariant(count_ampoule));
    return count_ampoule;
}
//End of get count ampoule method
/*****************************************************/
/*****************************************************/
//get name constructor
string ampoule::get_name()
{
    return name;
}
//get name constructor
/*****************************************************/
/*****************************************************/
//==operator for ampoule class
bool ampoule::operator==(device & rhs)
{
    return this->get_name() == rhs.get_name();
}
/*****************************************************/
/*****************************************************/
//ampoule destructor
ampoule::~ampoule()
{

}
