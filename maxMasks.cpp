#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <fstream>
#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>

int loadName(std::vector<std::string> &listName, std::string path){
    DIR *dr;
    dr = opendir(path.c_str());
    if (dr == NULL) return 1;
    struct dirent *de;
    while ((de = readdir(dr)) != NULL)
    {
        std::string deName = de->d_name;
        if (deName == "." || deName == "..") continue;
        listName.push_back(deName);
    }
    delete(de);
    closedir(dr);
    return 0;
}

int checkImage(cv::Mat image){
    for (int r = 0; r < image.rows; r++)
        for (int c = 0; c < image.cols; c++)
            if ((int)image.at<uchar>(r, c) != 0) return 0;
    return 1;
}

bool comp(std::pair<int, int> p, std::pair<int, int> q){
    return p.first > q.first;
}

int getSMasks(std::vector<std::string> listName, std::string path, std::pair<int, int> SMasks[]){
    for (int i = 0; i < listName.size(); i++){
        cv::Mat image = cv::imread(path + listName[i], 0);
        // cv::imshow(listName[i], image);
        // cv::waitKey(0);
        for (int r = 0; r < image.rows; ++r)
            for (int c = 0; c < image.cols; ++c)
                if ((int)image.at<uchar>(r, c) != 0) SMasks[i].first++;
    }
    std::sort(SMasks, SMasks + listName.size(), comp);
    return 1;
}

int writeImage(std::string name, std::string outP, std::string path){
    DIR *dircheck;
        dircheck = opendir(outP.c_str());
        if (dircheck == NULL){
            std::string cmd = "mkdir \"" + outP + "\"";
            system(cmd.c_str());
        }
        
    cv::Mat image = cv::imread(path + name, 0);
    bool flag = cv::imwrite(outP + name, image);
    if (flag) std::cout << "Done! :";
        else std::cout << "Error! :";
    std::cout << outP + name << "\n";

    return 1;
}

int loadMasks(std::string inpath, std::string outpath){
    std::string arr[] = {"bladder", "prostate", "left femur", "rectum", "right femur"};
    DIR *dip;
    if ( (dip = opendir(inpath.c_str())) == NULL) return printf("Folder %s not found!", inpath), 1;
    struct dirent *de;
    while ((de = readdir(dip)) != NULL)
    {
        std::string dename = de->d_name;
       
        if (dename == "." || dename == "..") continue;
        std::vector<std::string> listName;
        std::string rpath = inpath + "/" + de->d_name + "/";
        for (int i = 0; i < 5; ++i)
        {
        std::string path = rpath + arr[i] + "/predict_pos/";

        if (loadName(listName, path)) continue;
        // create folder if not exist
        std::string outP = outpath + "/" + de->d_name + "/" + arr[i] + "/predict_pos/";
        if (listName.size() == 0){
            std::cout << path << " is empty!";
        }
        std::pair<int, int> SMasks[listName.size()];
        for (int i = 0; i < listName.size(); ++i){
            SMasks[i] = std::make_pair(0, i);
        }
        getSMasks(listName, path, SMasks);
        float k = 0.2;
        float sMin = SMasks[0].first * k;
        std::cout << "Max Size : " << SMasks[0].first << "\n";
        std::vector<std::string> outName;
        // writeImage(listName[SMasks[0].second], outP, path);
        outName.push_back(listName[SMasks[0].second]);
        for (int i = 1; i < listName.size(); i++){
            if (SMasks[i].first >= sMin)  outName.push_back(listName[SMasks[i].second]);
                else std::cout << "del : " << listName[SMasks[i].second] << " size : " << SMasks[i].first << "\n";
        }
        
        std::pair<int, int> outNameInt[outName.size()];
        for (int i = 0; i < outName.size(); ++i){
            outNameInt[i] = std::make_pair(0,i);
        }
        for (int i = 0; i < outName.size(); ++i){
            std::string name = outName[i];
            name.erase(name.size() - 4, 4);
            // std::cout << name << "x\n";
            for (int j = 0; j < name.size(); j++)
                outNameInt[i].first = outNameInt[i].first*10 + (name[j] - '0');
            // std::cout << outNameInt[i] << "\n";
        }
        std::pair<int, int> idmax = outNameInt[0];
        std::sort(outNameInt, outNameInt + outName.size());
        int l = 0, r = outName.size()+1;
        while (r-l > 1)
        {
            int m = (r+l)/2;
            if (outNameInt[m].first == idmax.first){
                l = m;
                break;
            }
            if (outNameInt[m].first > idmax.first) r = m;
                else r = m;
        }
        int ansl = l, ansr = r;
        r = l + 1;
        --l;
        // writeImage(outName[idmax.second], outP, path);
        // std::cout << "size : " << outName.size() << "\n";
        
        while (true)
        {
            // std::cout << "l : " << l << " " << " r : " << r << "\n";
            if (l >= 0) 
                if (outNameInt[l].first + 5 > outNameInt[l+1].first)  ansl = l; // writeImage(outName[outNameInt[l].second], outP, path);
                    else  l = -1;
            if (r < outName.size())
                if (outNameInt[r].first - 5 < outNameInt[r-1].first) ansr = r; // writeImage(outName[outNameInt[r].second], outP, path);
                    else r = outName.size();
            if (l < 0 && r >= outName.size()) break;
            --l; ++r;
        }
        std::cout << ansl << " " << ansr << "\n";
        std::ofstream outfile;
        outfile.open("test.txt", std::ios_base::app);
        
        outfile << de->d_name << " " << arr[i] << " " << outNameInt[ansl].second << " " << outNameInt[ansr].second << "\n";
        outfile.close();
        // delete(&outNameInt);
        // delete(SMasks);
        }
    }
    delete(de);
    closedir(dip);
    
    return 0;
}

int main(int argc, char const *argv[])
{
    std::string input = argv[1];
    std::string output = argv[2];
    loadMasks(input, output);
    return 0;
}
