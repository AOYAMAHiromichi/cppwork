/* 
CDir_class header
2021/05/20
*/
#pragma once

#include<iostream>
#include<cstdlib>
#include<dirent.h>
#include<vector>
#include<string>
#include<experimental/filesystem>

class CDir
{
private:
    std::string dir_path_name;              //対象とするDirectory
    std::vector<std::string> file_names;    //file name一覧

public:
    int file_num_max;                   //dir_path_nameで示すDirectoryのFile数
    std::string ret_filename;           //put_filenameのfile nameを格納

    CDir(std::string d_p_name);

    int get_filenames();                //file name一覧をthis->file_namesに取り込む

    int put_filename(int);              //引数のfile nameをthis->ret_filenameで返す

    std::string put_date_of_file(std::string,int);      //ファイルの文字数が引数2なら　Fileの日付を返す、異なれば”ERROR"
};
