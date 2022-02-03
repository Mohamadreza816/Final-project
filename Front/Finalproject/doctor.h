#ifndef DOCTOR_H
#define DOCTOR_H
#include <QVariant>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <stdexcept>
using namespace std;
enum status
{
    HEALTHY,
    ILL
};

class doctor : public QObject
{
    Q_OBJECT
public:
    explicit doctor(string a_name,QObject *parent = nullptr);
    void set_xp(int status);               //set experience
    void set_energy(int time, int status); // set energy after each patient
    void set_credit(int status);
    void set_coin( int amount); //set amount of con
private:
    string name;
    static int xp ; //experience of player
    static int energy ;
    static int credit ;
    static int coin;
signals:
    void noticecoin(QVariant data);//a signal for return coin value
    void noticexp(QVariant data) const;//a signal for return XP value
    void noticeenergy(QVariant data) const;//a signal for return energy value
    void noticecredit(QVariant data) const;//a signal for return credit value
    void noticemessagedoctor(QVariant note) const;//a signal for message
    void gameover(QVariant message)const;//a signal for show game over
public slots:
    int get_coin();                        //return coin
    int get_xp() const;                    //return experience value
    int get_energy() const;                //return enegy value
    void boost_energy();                    //boost energy
    int get_credit() const;                //return credit value
};

#endif // DOCTOR_H
