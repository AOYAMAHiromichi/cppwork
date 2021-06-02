/* time date class CPP
ファイル名から時間の計算を行うクラス
 2021/6/1
*/

#include "CTimeday.h"

time_t CTimeday::get_sec1900(int tmt_year,int tmt_mon,int tmt_day)    //西暦、月、日を入れてtotal秒を返す
{
    time_t ret_sec;    //戻り値　time_t
    struct tm tm_time={0,0,0,tmt_day,tmt_mon-1,tmt_year-1900};
    ret_sec=mktime(&tm_time);
    return ret_sec;
}

int CTimeday::get_struct_tm(time_t x_sec)
{
    struct tm* temp_tm=localtime(&x_sec);
    this->ret_ymdhms_year=temp_tm->tm_year+1900;    //年は1900年からカウントされてるため
    this->ret_ymdhms_mon=temp_tm->tm_mon+1;     //日付は-1日されてるため
    this->ret_ymdhms_day=temp_tm->tm_mday;
    return 0;
}
 
    