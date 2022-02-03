#ifndef AMPOULE_H
#define AMPOULE_H
#include <iostream>
#include <QObject>
#include "medicaldevice.h"
using namespace std;
class ampoule : public device
{
    Q_OBJECT
public:
    explicit ampoule(string a,QObject *parent = nullptr);

    virtual string get_name() override;//return value
    bool operator==(device & rhs) ;//overload
    virtual ~ampoule();//destructor
private:
    static int count_ampoule;
    string name;
signals:
    void noticgetampoulecount(QVariant data);//a signal for update ampoule count
    void noticeampoulemessage(QVariant note);//a signal for show error mrssage
public slots:
    virtual void buy() override;//buy method
    virtual bool use() override;//use method
    virtual int get_count() override;//return value

};

#endif // AMPOULE_H
