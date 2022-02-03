#ifndef PILL_H
#define PILL_H
#include <iostream>
#include <QObject>
#include <QVariant>
#include "medicaldevice.h"
using namespace std;
class pill : public device
{
    Q_OBJECT
public:
    explicit pill(string a, QObject *parent = nullptr);//constructor
    virtual string get_name() override;//return value
    bool operator==(device & rhs);//overload
    virtual ~pill();//detructor
private:
    static int count_pill;
    string name;
signals:
    void noticegetpillcount(QVariant data);//a signal for show count of pill
    void noticemessage(QVariant note);//a signal for show error message
public slots:
    virtual int get_count() override;//return value
    virtual void buy( ) override;//buy method
    virtual bool use() override;//use method

};

#endif // PILL_H
