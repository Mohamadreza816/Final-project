#ifndef MEDICALDIVICE_HPP
#define MEDICALDIVICE_HPP
#include "../include/doctor.hpp"
#include <iostream>
using namespace std;
//abstract class
class device
{
private:
    string name;

public:
    device(string);                      //constructor
    virtual void buy(doctor &, int) = 0; // buy device(abstract class)
    virtual bool use(doctor &) = 0;      // how to use(abstract class)
    virtual int get_count() = 0;         //return count of pill or ampoule
    virtual string get_name();           //return name
};
//----------------------------------------------
//pill class inhreted from abstract class(device)
class pill : public device
{
private:
    static int count_pill;
    string name;

public:
    pill(string); //constructor
    virtual void buy(doctor &, int) override;
    virtual bool use(doctor &) override;
    virtual int get_count() override;
    virtual string get_name() override;
};
//----------------------------------------------
//ampoule class inhreted from abstract class(device class)
class ampoule : public device
{
private:
    static int count_ampoule;
    string name;

public:
    ampoule(string); //constructor
    virtual void buy(doctor &, int) override;
    virtual bool use(doctor &) override;
    virtual int get_count() override;
    virtual string get_name() override;
};
#endif