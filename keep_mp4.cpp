/* 
keep_mp4 to keep directory
include CFilenamesearch.h
g++ option: c++17 必要
2021/6/2
2021/6/3 Cfns修正済
*/
#include"CFilenamesearch.h"
#include<filesystem>
#include<iostream>
#include<string>

extern const std::string cnst_motion_dir;

int main()
{
    std::string dir_path=cnst_motion_dir;
    std::string keep_dir=cnst_motion_dir+"/keep";
    CFilenamesearch cfns;

    while(true)
    {
        std::cout<<"Input Filename you want to keep. \n";
        std::string keep_file_name;
        std::cin>>keep_file_name;

        if (keep_file_name=="end")
        {
            std::cout<< "MP4 File keep routine Finish.\n";
            break;
        }
        std::filesystem::path p=keep_file_name;
        if(p.extension()==".mp4")
        {
            if(!(std::filesystem::exists(dir_path+"/"+keep_file_name)))
            {
                std::string sub_dir_path;
                sub_dir_path=cfns.get_date8(keep_file_name);
                if (std::filesystem::exists(dir_path+"/"+sub_dir_path+"/"+keep_file_name))
                {
                    std::filesystem::rename(dir_path+"/"+sub_dir_path+"/"+keep_file_name,keep_dir+"/"+keep_file_name);
                }
            }
            else
            {
                std::filesystem::rename(dir_path+"/"+keep_file_name, keep_dir+"/"+keep_file_name);
            }
        }
    }

}
