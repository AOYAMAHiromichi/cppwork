// time date class header
// 2021/6/1

#pragma once

#include <iostream>
#include <sstream>

class CTimeday
{
private:
public:
    //CTimeday();
    int ret_ymdhms_year;
    int ret_ymdhms_mon;
    int ret_ymdhms_day;

    time_t get_sec1900(int, int, int); //西暦、月、日を入れてtotal秒を返す
    int get_struct_tm(time_t);
};
