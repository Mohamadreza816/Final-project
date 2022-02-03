#include "pill.h"
//static var
int pill ::count_pill = 0;
pill::pill(string a ,QObject *parent) : device(a)
{
    name = a;
}
//end of pill constructor
/*****************************************************/
/*****************************************************/
//buy method for pill and emit signal
void pill::buy()
{
    //price of pill is 5 coin
    doctor d{"d"};
    int sum = 1 * 5;

    if (d.get_coin() >= sum)
    {
        d.set_coin(-sum);              //decrease amount of coin
        count_pill = count_pill + 1; //increase pill count
        emit noticemessage(QVariant(""));//no error in buy
        emit noticegetpillcount(QVariant(count_pill));//update count of pill
    }
    else
    {
        emit noticemessage(QVariant("count of coin isn't enough!"));//emit error messages
        //throw out_of_range("count of coin isn't enough!");
    }
}
//end of buy method
/*****************************************************/
/*****************************************************/
// use method for pill and emit that signal
bool pill::use()
{
    //use poll for treatment
    doctor d{"doc"};
    try
    {


        if (d.get_xp() >= 0)
        {

            if(count_pill > 0)
            {
                count_pill--; //decrease pill count
                emit noticegetpillcount(QVariant(count_pill));//update count of pill
                 emit noticemessage(QVariant(""));//no error message
            }

        }
        else
        {

            emit noticemessage(QVariant("your experience isn't enough for use pill!"));//show error message
            //throw out_of_range("your experience isn't enough for use pill!");
        }
    }
    catch (const out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}
//end odf use method
/*****************************************************/
/*****************************************************/
//get_count_pill method and emit signal
int pill::get_count()
{
    emit noticegetpillcount(QVariant(count_pill));
    return count_pill;
}
//End of get_count_pill method
/*****************************************************/
/*****************************************************/
//get_name
string pill::get_name()
{
    return name;
}
//end of get_name
/*****************************************************/
/*****************************************************/
//== operator for pill
bool pill::operator==(device & rhs)
{
    return this->get_name() == rhs.get_name();
}
//pill destructor
pill::~pill()
{
}
