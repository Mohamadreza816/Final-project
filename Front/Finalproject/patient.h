#ifndef PATIENT_H
#define PATIENT_H
#include <stdexcept>
#include <iostream>
#include <QVariant>
#include <QObject>
#include <vector>
#include "doctor.h"
#include "medicaldevice.h"
class patient : public QObject
{
    Q_OBJECT
public:
    explicit patient( QObject *parent = nullptr);
    void set_status(int); //set status method
    int get_status();//return status value

    patient &operator=(const patient &rhs); //copy assogment(operator overloading)
private:
    static int health_count;
    static int sick_count;
    int grade;//1-3
    int status;

signals:
    void noticehealth(QVariant data);//a signal for return count of healthy person
    void noticesick(QVariant data);//a signal for return count og sick person
    void noticetreatmessage(QVariant note);//a signal for show messages
public slots:
    int get_health_count();//return health count
    int get_sick_count();//return sick count
    int treatment(int g);//treatment method


};

#endif // PATIENT_H
