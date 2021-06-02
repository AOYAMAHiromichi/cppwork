/* 
keep_mp4 to keep directory
g++ option: c++17 必要
2021/6/2
*/
#include<filesystem>
#include<iostream>
#include<string>


int main()
{
    std::string keep_dir;
    std::string dir_path="/home/hiro/motion_dir";
    keep_dir="/home/hiro/motion_dir/keep";
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
        if((keep_file_name.size()==21)&&(keep_file_name.substr(17,4)==".mp4"))
        {
            if(!(std::filesystem::exists(dir_path+"/"+keep_file_name)))
            {
                std::string sub_dir_path;
                sub_dir_path=keep_file_name.substr(3,8);
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
