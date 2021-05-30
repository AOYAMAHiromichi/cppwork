#include<iostream>
#include<filesystem>
using std::cout;
using std::string;
namespace fs = std::filesystem;

int main()
{
    string path_name="/home/hiro/motion_dir";
    fs::path fp;

    for (int i=0;i<2;++i)
    {
        string s_filename;
        //fp=x.path();
        s_filename=fp.filename();
        if (fs::exists("/home/hiro/motion_dir/dir000"))
        {
            cout<<"This Dir is exist! \n";
        }
        else
        {
            cout <<"Directory not Exist! Create this dir \n";
            fs::create_directory("/home/hiro/motion_dir/dir000");
        }
        
    }
}