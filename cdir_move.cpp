/* 
cdir_move.cpp
動画ファイル(.mp4)を日別のフォルダーに移す
CFilenamesearch.h CDir.h をinclude
OPTION:c++17　必要
2021/6/3
定数として”motion_dir”のパスをグローバルにcnst_motion_dirに持つ。
*/
#include"CFilenamesearch.h"
#include "CDir.h"
#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<stdio.h>

extern const std::string cnst_motion_dir;
CFilenamesearch cfns;

int main()
{
    std::string w_dir=cnst_motion_dir;  //動画のDirectory
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
        std::filesystem::path fs_f_name=f_name;
        if (f_name.empty()==1)
        {
            std::cout<<"File Name Empty Error!";
            exit(1);
        }

        if (fs_f_name.extension()==".mp4")     //拡張子は「.mp4」
        {
            day_str=cfns.get_date8(f_name);                             //ファイル名から日付をget
            if (!(std::filesystem::exists(w_dir+"/"+day_str)))      //日付のDirectoryが存在しなければ作成
            {
                std::filesystem::create_directory(w_dir+"/"+day_str);
            }

            std::ofstream{w_dir+"/"+day_str+"/"+f_name};
            //std::filesystem::path fp=w_dir;
            //std::filesystem::path tp=w_dir+"/"+day_str;
            //std::filesystem::rename(fp+"/"+f_name,tp+"/"+f_name);     //ファイルの移動
            std::string from_fn=w_dir+"/"+f_name;
            std::string to_fn=w_dir+"/"+day_str+"/"+f_name;
            std::filesystem::rename(from_fn,to_fn);
        }
    }
}