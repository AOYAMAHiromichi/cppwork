#include<iostream>
#include<sstream>
//#include<iomanip>

int main()
{
    time_t t=time(nullptr);
    std::cout <<t<<"sec\n";
    const struct tm* st_time=localtime(&t);
    std::stringstream s;
    s << "20"<<st_time->tm_year-100<<"/";
    s << st_time->tm_mon+1<<"/";
    s << st_time->tm_mday;
    std::cout<<s.str()<<std::endl;

    struct tm ex_tm={st_time->tm_sec,st_time->tm_min,st_time->tm_hour,st_time->tm_mday-33,st_time->tm_mon,st_time->tm_year};
    time_t u=mktime(&ex_tm);
    std::cout<<u<<"sec \n";
    const struct tm* tt_time=localtime(&u);

    std::stringstream ss;
    ss << "20"<<tt_time->tm_year-100<<"/";
    ss << tt_time->tm_mon+1<<"/";
    ss << tt_time->tm_mday;


    std::cout<<ss.str()<<std::endl;

    
    //std::cout<<t<<std::endl;

}