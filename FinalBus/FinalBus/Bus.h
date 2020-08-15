#pragma once
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

const int priceGoods = 10000;
static int P = 0;
static int Q = 1;

class Date
{
protected:
    int _day, _month, _year;

public:
    Date();
    void input();
    void output();
};

class Ticket
{
protected:
    string _nameOfTrip;
    Date _date;
    int _price;
    int _goods;

public:
    Ticket();
    void input();
    void output();
    int getPrice();
};

class Person
{
protected:
    string _name, _sex;
    int _age;
    string _tel;
    string _email;

public:
    Person();
    void input();
    void output();
};

class User : public Person
{
protected:
    int _number;
    vector<Ticket> _ticket;
    int _sumPrice;
    string _feedback;
public:
    User();
    void input();
    void output();
};

class History {
protected:
    string _name;
    string _tel;
    int _goods;
    int _payment;
    string _feedback;
    string _typebus;
public:
    History();
    void setName(string name);
    void setTel(string tel);
    void setFb(string fb);
    void print();
};

class Bus
{
protected:
    string _name = "Regular Bus";
    int Price;
    string Departure;
    string From;
    string To;
    int seat_max;
    int Row, Col;
    vector<vector<string>>Seats;
    string Driver;
    string Voucher;
public:
    int Number;
    void SetSeats();
    void Install();
    void Reverse();
    void Show();
    virtual void ShowName()
    {
        cout << "Type bus: " << _name << endl;
    }
    virtual void ShowPrice()
    {
        cout << "Price per ticket: 200,000 VND" << endl;
    }
    void ShowSeat();
    bool CheckEmpty(int No);
    void NameRev(string name, int Seat);
    Bus();
};

//Class cac loai xe dac biet 
class Bed_Car :public Bus
{
private:
    string _name = "Bed Car";
    string Voucher;

public:
    void ShowName()
    {
        cout << "Type bus: " << _name << endl;
    }
    void ShowPrice()
    {
        cout << "Price per ticket: 400,000 VND" << endl;
    }

    Bed_Car(int num);

};

class VIP : public Bus
{
private:
    string _name = "Vip Car";
    string Voucher;
public:
    void ShowName()
    {
        cout << "Type bus: " << _name << endl;
    }
    void ShowPrice()
    {
        cout << "Price per ticket: 3,000,000 VND" << endl;
    }
    VIP(int num);
};

class SuperVip : public Bus//Xe rieng tai xe rieng
{
private:
    string _name = "SuperVip Car";
    string Voucher = "supervipVoucher";
public:
    void ShowName()
    {
        cout << "Type bus: " << _name << endl;
    }
    void ShowPrice()
    {
        cout << "Price per ticket: 10,000,000 VND" << endl;
    }
    SuperVip(int num);
};

void OptionInstall();
void OptionRev();

class Admin
{
protected:
    string _account;
    string _password;
    vector<string> _feedback;
    vector<History> _history;
public:
    void account(string str);
    void password(string str);
};

class BusStation
{
private:
    vector<Admin> _ad;
    vector<Bus*> _bus;
    vector<User> _user;
public:
    void setAdmin();
    void addBed_car(Bed_Car a);
    void addVip(VIP b);
    void addVipCar(SuperVip c);
    void Install();
    void Rev();
    void saveInforIntoHistory();
};