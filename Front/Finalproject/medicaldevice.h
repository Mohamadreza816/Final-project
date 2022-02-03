#ifndef MEDICALDEVICE_H
#define MEDICALDEVICE_H
#include "doctor.h"
#include <QVariant>
#include <iostream>
using namespace std;
#include <QObject>
//abstract class
class device : public QObject
{
    Q_OBJECT
public:
    explicit device(string a_name, QObject *parent = nullptr);
    virtual string get_name() = 0;           //return name
    virtual ~device();//destructor
private:
    string name;

signals:
    void noticegetpillcount(QVariant data);
public slots:
    virtual void buy() = 0; // buy device(abstract class)
    virtual bool use() = 0;      // how to use(abstract class)
    virtual int get_count() = 0;         //return count of pill or ampoule

};

#endif // MEDICALDEVICE_H
