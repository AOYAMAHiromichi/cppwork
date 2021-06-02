/* 
20210601ex
time_day class test
*/
#include "CTimeday.h"
#include<iostream>
#include<string>
//#include<stringstream>

int main()
{
    CTimeday ct;
    time_t today_sec=time(nullptr);
    ct.get_struct_tm(today_sec);
    std::cout<<ct.ret_ymdhms_year<<"年"<<ct.ret_ymdhms_mon<<"月"<<ct.ret_ymdhms_day<<"日 \n";

    std::cout<<"\n 7日前　\n";
    time_t sevenday_sec=ct.get_sec1900(ct.ret_ymdhms_year,ct.ret_ymdhms_mon,ct.ret_ymdhms_day-7);
    ct.get_struct_tm(sevenday_sec);
    std::cout<<ct.ret_ymdhms_year<<"年"<<ct.ret_ymdhms_mon<<"月"<<ct.ret_ymdhms_day<<"日 \n";




}