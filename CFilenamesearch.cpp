/*Class filename search
ファイルネーム中から年月日の8文字を返す
定数として”motion_dir”のパスをグローバルにcnst_motion_dirに持つ。
By.H.Aoyama
2021/6/3
*/

#include"CFilenamesearch.h"
//#include<string>
const std::string cnst_motion_dir="/home/hiro/motion_dir";
std::string CFilenamesearch::get_date8(std::string inp_string)
{
    this->str_filename=inp_string;
    this->ret_filename="";
    for(int i=0;i<this->str_filename.size();++i)
    {
        //char c=this->str_filename[i];
        if (this->str_filename.substr(i,1)=="-")
        {
            this->ret_filename=this->str_filename.substr(i+1,8);
            break;
        }
    }
    return this->ret_filename;

}
