/* 
DateFolder
*/
#include "CDir.h"
#include<iostream>
#include<string>
//#include<experimental/filesystem>
#include<filesystem>
#include<fstream>

int main()
{
    std::string w_dir="/home/hiro/motion_dir";  //動画のDirectory
    CDir dir(w_dir);                            //クラスCDirのObject：dir
    int flag_get;
    flag_get=dir.get_filenames();               //dirにファイル名一覧を取り込む

    //std::cout<<"file_num_max2="<<dir.file_num_max<<std::endl;
    
    //std::cout<<"start \n";

    for(int i=0;i<dir.file_num_max;++i)
    {

        if (dir.put_filename(i)==1)             //names[i]に相当するファイル名をret_filenameに格納
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

        if ((f_name.size()==23)&&(f_name.substr(19,4)==".mp4"))     //file名は23文字で　拡張子は「.mp4」か？
        {
            day_str=f_name.substr(3,8);                             //ファイル名から日付をget
            //std::cout<<"ii="<<i<<" : "<<day_str<<std::endl;
            if (!(std::filesystem::exists(w_dir+"/"+day_str)))      //日付のDirectoryが存在しなければ作成
            {
                std::filesystem::create_directory(w_dir+"/"+day_str);
            }

            std::ofstream(w_dir+"/"+f_name);
            std::filesystem::rename(w_dir+"/"+f_name,w_dir+"/"+day_str+"/"+f_name);     //ファイルの移動

        }

    }
    

}