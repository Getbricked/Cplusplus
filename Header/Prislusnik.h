#ifndef PRISLUSNIK_H
#define PRISLUSNIK_H

#pragma once
using namespace std;
#include<string>
#include<iostream>
class Prislusnik
{
public:
    Prislusnik();
    void kontrolacislo();
    void kontrolajmeno();
    void kontrolaprijmeni();
    void kontroladatumnarozeni();
private:

protected:
    int y;
    int m;
    int d;
    string rodnecislo;
    string jmeno;
    string prijmeni;
    string pohlavi;
};

#endif