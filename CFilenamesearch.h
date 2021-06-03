/*Class filename search
ファイルネーム中から年月日の8文字を返す
定数として”motion_dir”のパスをグローバルにcnst_motion_dirに持つ。
By.H.Aoyama
2021/6/3
*/
#pragma once

#include<string>
//const std::string cnst_motion_dir="/home/hiro/motion_dir";
extern const std::string cnst_motion_dir;

class CFilenamesearch
{
private:
    std::string str_filename;
    std::string ret_filename;

public:
    std::string get_date8(std::string);
};