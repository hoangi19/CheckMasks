
#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>

int load(std::string inpath, std::string outpath){
    DIR *dr;
    dr = opendir(inpath.c_str());
    struct dirent *de;
    while ((de = readdir(dr)) != NULL)
    {
        std::string dename = de->d_name;
        if (dename == "." || dename == "..") continue;
        DIR *drr;
        drr = opendir((inpath + "/" + dename).c_str());
        struct dirent *dee;
        int i = 1;

        std::string outP = outpath + "/" + dename;
        DIR *dircheck;
        dircheck = opendir(outP.c_str());
        if (dircheck == NULL){
            std::string cmd = "mkdir \"" + outP + "\"";
            system(cmd.c_str());
        }

        while ((dee = readdir(drr)) != NULL)
        {
            std::string deename = dee->d_name;
            if (deename == "." || deename == "..") continue;
            std::string newname = std::to_string(i);
            while (newname.size() < 3)
            {
                newname = "0" + newname;
            }

            std::string cmd = ("rename " + inpath + "\\" + dename + "\\" + deename + " "  + newname + ".png");
            std::cout << cmd << "\n";
            system((cmd).c_str());
            ++i;
        }
        
        closedir(drr);
    }

    closedir(dr);
    

    return 1;
}

int main(int argc, char const *argv[])
{
    std::string input = "C:\\Users\\Hoangi19\\Desktop\\MyDCMTK\\checkMasks\\test";
    std::string output = "../rename";
    load(input, output);
    return 0;
}
