/* 
CDir class CPP
2021/05/20
*/
#include "CDir.h"

    CDir::CDir(std::string d_p_name)
    {
        this->dir_path_name=d_p_name; 
        this->file_num_max=0;       
    }

    int CDir::get_filenames()
    {
        //const char* path="./";
        const char* path=this->dir_path_name.c_str();
        DIR *dp;
        int count=0;
        dp=opendir(path);
        if  (dp==NULL) return 1;    //file_names getに失敗　戻り値　1
        dirent* entry=readdir(dp);
        while(entry!=NULL)
        {
            if (entry !=NULL)
            {
                //std::cout<<"i_= "<<count<<"  "<<path<<"/"<<entry->d_name <<std::endl;
                this-> file_names.push_back(entry->d_name);
                ++count;
            }
            entry=readdir(dp);
        }
        //this->file_num_max=this->file_names.size();
        //std::cout<<"file_num_max1="<<this->file_num_max<<std::endl;
        if (count==2) 
        {
            return 1;   //Directoryが空な時　戻り値　1
        }
        this->file_num_max=this->file_names.size();
        return 0;       //一覧をgetしたら戻り値　1
    }

    int CDir::put_filename(int x)
    {
        int i=x;
        if (i>this->file_names.size())
        {
            std::cout<<"No.Error!!"<<std::endl;
            return 1;   // Vectorの添字が大きい時　戻り値　1
        }
        this->ret_filename=file_names[i];
        return 0;
    }

    std::string put_date_of_file(std::string f_name,int len_of_f)
    {
       std::string file_name= s_name;
       std::string ret_date;
       int len_of_file=len_of_f;
       if(len_of_file!=file_name.size())
       {
           return "ERROR";
       }
       ret_date=file_name.substr(3,8);
       return ret_date;
    }
