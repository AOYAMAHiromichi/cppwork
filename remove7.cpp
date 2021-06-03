/* 
remove7.cpp
7日分のファイル・ディレクトリをDeleteする
CFilenamesearch.h　と　CDir.h　と　CTimeday.h　includeする
g++ option c++17必要
By.H.Aoyama
2021/6/1-2
2021/6/3 CFNS 修正すみ

*/
#include"CFilenamesearch.h"
#include "CTimeday.h"
#include "CDir.h"
#include<iostream>
#include<string>
#include<filesystem>

extern const std::string cnst_motion_dir;

int main()
{
    CTimeday ct;
    CFilenamesearch cfns;

    //本日の日付(today_sec)設定

    time_t today_sec=time(nullptr); 
    //today_sec=ct.get_sec1900(2021,05,10);
    ct.get_struct_tm(today_sec);

    //7日前 の　日付（sevenday_sec）設定

    time_t sevenday_sec=ct.get_sec1900(ct.ret_ymdhms_year,ct.ret_ymdhms_mon,ct.ret_ymdhms_day-7);
    ct.get_struct_tm(sevenday_sec);

    //　動画の入っているDirectoryをcmr_dir に読み込む

    std::string mt_dir=cnst_motion_dir;
    CDir cmr_dir(mt_dir);
    
    int flag_getfn;
    flag_getfn=cmr_dir.get_filenames();
    if (flag_getfn>0)
    {
        std::cout << "Files read Error! \n";
        exit(1);
    }

    //　7日前のDirectory　削除

    for(int i=0;i<cmr_dir.file_num_max;++i)
    {
        if (cmr_dir.put_filename(i)==1)
        {
            std::cout<<"put_filename  :Read Error!";
            break;
        }

        std::string dir_name;
        dir_name=cmr_dir.ret_filename;
        //
        if (dir_name.substr(0,2)=="20")
        {
            int tmp_year,tmp_mon,tmp_day;
            tmp_year=atoi(dir_name.substr(0,4).c_str());
            tmp_mon=atoi(dir_name.substr(4,2).c_str());
            tmp_day=atoi(dir_name.substr(6.2).c_str());
            time_t dir_sec;
            dir_sec=ct.get_sec1900(tmp_year,tmp_mon,tmp_day);
            if(sevenday_sec>=dir_sec)
            {
                std::filesystem::remove_all(mt_dir+"/"+dir_name);
            }
        }
    }

    //　7日前の写真消去
    std::string photo_dir;
    photo_dir=cnst_motion_dir+"/photo";
    CDir cphoto_dir(photo_dir);

    if(cphoto_dir.get_filenames()==1)
    {
        std::cout<<"Photofiles read error! \n";
        exit(1);
    } 
    
    for (int i=0;i<cphoto_dir.file_num_max;++i)
    {
        std::string photo_filename;
        cphoto_dir.put_filename(i);
        photo_filename=cphoto_dir.ret_filename;
        if (photo_filename.size()>=5) 
        {   
            std::filesystem::path p=photo_filename;
            if (p.extension()==".jpg")
            {
                time_t photo_sec;
                std::string photo_day=cfns.get_date8(photo_filename);
                photo_sec=ct.get_sec1900(atoi(photo_day.substr(0,4).c_str()),atoi(photo_day.substr(4,2).c_str()),atoi(photo_day.substr(6,2).c_str()));
                if (photo_sec<sevenday_sec)
                {
                    std::filesystem::remove(photo_dir+"/"+photo_filename);
                }
            }
        }
    }
}