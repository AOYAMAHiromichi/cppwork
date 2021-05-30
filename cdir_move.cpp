/* 
DateFolder
*/
#include "CDir.h"
#include<iostream>
#include<string>
//#include<experimental/filesystem>
#include<filesystem>

int main()
{
    CDir dir("/home/hiro/motion_dir");
    int flag_get;
    flag_get=dir.get_filenames();

    //std::cout<<"file_num_max2="<<dir.file_num_max<<std::endl;
    
    //std::cout<<"start \n";

    for(int i=0;i<dir.file_num_max;++i)
    {

        if (dir.put_filename(i)==1)
        {
            std::cout<<"i="<<i<<"  No data ERROR!"<<std::endl;
            exit(1);
        }
        std::string f_name,day_str;
        f_name=dir.ret_filename;
        //std::cout<<"i="<<i<<" : "<<dir.ret_filename<<std::endl;
        if (f_name.empty()==1)
        {
            std::cout<<"File Name Empty Error!";
            exit(1);
        }

        //std::cout<<"PASS\n";

        if (f_name.size()==23)
        {
            day_str=f_name.substr(3,8);
            std::cout<<"ii="<<i<<" : "<<day_str<<std::endl;
        }

    }
    

}