/* 
cdir_move.cpp
動画を日別のフォルダーに移す
CDir.h をinclude
OPTION:c++17　必要
*/
#include "CDir.h"
#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>

int main()
{
    std::string w_dir="/home/hiro/motion_dir";  //動画のDirectory
    CDir dir(w_dir);                            //クラスCDirのObject：dir
    int flag_get;
    flag_get=dir.get_filenames();               //dirにファイル名一覧を取り込む

    for(int i=0;i<dir.file_num_max;++i)
    {

        if (dir.put_filename(i)==1)             //names[i]に相当するファイル名をret_filenameに格納
        {
            std::cout<<"i="<<i<<"  No data ERROR!"<<std::endl;
            exit(1);
        }
        std::string f_name,day_str;
        f_name=dir.ret_filename;
        if (f_name.empty()==1)
        {
            std::cout<<"File Name Empty Error!";
            exit(1);
        }

        if ((f_name.size()==21)&&(f_name.substr(17,4)==".mp4"))     //file名は23文字で　拡張子は「.mp4」か？
        {
            day_str=f_name.substr(3,8);                             //ファイル名から日付をget
            if (!(std::filesystem::exists(w_dir+"/"+day_str)))      //日付のDirectoryが存在しなければ作成
            {
                std::filesystem::create_directory(w_dir+"/"+day_str);
            }

            std::ofstream(w_dir+"/"+f_name);
            std::filesystem::rename(w_dir+"/"+f_name,w_dir+"/"+day_str+"/"+f_name);     //ファイルの移動

        }
    }
}