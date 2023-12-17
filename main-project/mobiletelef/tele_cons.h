#pragma once
#include "const.h"
#ifndef PHONE_CALL_H
#define PHONE_CALL_H

struct time {

    int hours;
    int minutes;
    int seconds;
};
struct date
{
    int day;
    int month;
    int year;
};

struct phone_call
{
    char phone_number[PHONE_NUMBER_SIZE];
    time call_time;
    date call_date;
    char duration[DURATION_SIZE];
    char tariff[TARIFF_SIZE];
    float cost;
};


#endif