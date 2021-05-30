/* 
DateFolder
*/
#include "CDir.h"
#include<iostream>
#include<string>

int main()
{
    CDir dir("/home/hiro/motion_dir");
    if (1==dir.get_filenames())
    {
        std::cout<<"Directory Empty!";
        exit (0);
    }

    //std::cout<<"file_num_max2="<<dir.file_num_max<<std::endl;
    

    for(int i=0;i<dir.file_num_max;++i)
    {

        if (dir.put_filename(i)==1)
        {
            std::cout<<"i="<<i<<"  No data ERROR!"<<std::endl;
            exit(1);
        }
        std::cout<<"i="<<i<<" : "<<dir.ret_filename<<std::endl;
    }
    

}