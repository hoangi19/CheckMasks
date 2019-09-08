#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>

class checkMasks{
public :

    static int BFS(int masks[], cv::Mat curImage, int x, int y, int &n){
        if ((int)curImage.at<uchar>(x, y) == 0) return 0;
        int rows = curImage.rows;
        int cols = curImage.cols;

        if (masks[x*rows + y] != 0) return 0;
        std::queue<int> q;
        ++n;
        
        
        q.push(x*rows + y);
        int *visited = new int[rows*cols];
        // memset(visited, 0, sizeof(visited));
        for (int i = 0; i < rows*cols; i++)
            visited[i] = 0;
        masks[x*rows + y] = n;

        while (!q.empty())
        {
            int u = q.front();
            
            q.pop();
            if (visited[u]) continue;
            masks[u] = n;
            visited[u] = 1;
            
            if (u%rows + 1 < cols)
                if ((int)curImage.at<uchar>(u/rows, u%rows + 1) != 0 && visited[u+1] == 0) q.push(u+1);
            if (u%rows > 0)
                if ((int)curImage.at<uchar>(u/rows, u%rows - 1) != 0 && visited[u-1] == 0) q.push(u-1);
            if (u+rows < rows*cols)
                if ((int)curImage.at<uchar>(u/rows + 1, u%rows) != 0 && visited[u+rows] == 0) q.push(u+rows);
            if (u/rows > 0)
                if ((int)curImage.at<uchar>(u/rows - 1, u%rows) != 0 && visited[u-rows] == 0) q.push(u-rows);
        }
        delete(visited);

        return 1;
    }

    static int checkMask(cv::Mat preImage, cv::Mat &curImage, cv::Mat befImage){
        
        int rows = curImage.rows;
        int cols = curImage.cols;
        
        int *masksP = new int[rows*cols];
        int *masksC = new int[rows*cols];
        int *masksB = new int[rows*cols];
        for (int i = 0; i < rows*cols; i++)
        {
            masksB[i] = 0;
            masksC[i] = 0;
            masksP[i] = 0;
        }
        int nCMask = 0;
        int nBMask = 0;
        int nPMask = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++){
                // if ((int)curImage.at<uchar>(r, c) != 0 && ((int)preImage.at<uchar>(r, c) != 0 || (int)befImage.at<uchar>(r, c) != 0))
                {
                    BFS(masksP, preImage, r, c, nPMask);
                    BFS(masksC, curImage, r, c, nCMask);
                    BFS(masksB, befImage, r, c, nBMask);
                    // if (nBMask != 0) std::cout << r << " " << c << " " <<  nBMask << "\n";
                    // std::cout << (int)curImage.at<uchar>(r, c) << "\n";
                }
            }
        // std::cout << nCMask << "\n";
        int *SMasksP = new int[rows*cols];
        int *SMasksB = new int[rows*cols];
        int *SCMasks = new int[rows*cols];
        int *SBMasks = new int[rows*cols];
        int *SPMasks = new int[rows*cols];
        for (int i = 0; i < rows*cols; i++){
            SMasksB[i] = 0;
            SMasksP[i] = 0;
            SCMasks[i] = 0;
            SBMasks[i] = 0;
            SPMasks[i] = 0;
        }
        int idSCMax = 0;
        int idSBMax = 0;
        int idSPMax = 0;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c){

                if (masksC[r*rows + c] != 0) SCMasks[masksC[r*rows+c]]++;
                if (SCMasks[idSCMax] < SCMasks[masksC[r*rows + c]]) idSCMax = masksC[r*rows + c];

                if (masksB[r*rows + c] != 0) SBMasks[masksB[r*rows+c]]++;
                if (SBMasks[idSBMax] < SBMasks[masksB[r*rows + c]]) idSBMax = masksB[r*rows + c];

                if (masksP[r*rows + c] != 0) SPMasks[masksP[r*rows+c]]++;
                if (SPMasks[idSPMax] < SPMasks[masksP[r*rows + c]]) idSPMax = masksP[r*rows + c];
                
            }
        // std::cout << idSPMax << " " << idSCMax << " " << idSBMax << " ";
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c){
                if (masksC[r*rows + c] != 0 && masksC[r*rows + c] == idSCMax){
                    // curImage.at<uchar>(r, c) = 0;
                    if (masksB[r*rows + c] != 0 && masksB[r*rows + c] == idSBMax) SMasksB[masksB[r*rows + c]]++;
                    if (masksP[r*rows + c] != 0 && masksP[r*rows + c] == idSPMax) SMasksP[masksP[r*rows + c]]++;
                    
                }
            }
        int *dd = new int[rows*cols];
        for (int r = 0; r < rows; ++r)
            for (int c  = 0; c < cols; ++c)
                dd[r*rows + c] = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c){
                if (dd[masksC[r*rows+c]] == 1) continue;
                if (curImage.at<uchar>(r, c) != 0)
                    // if ( masksC[r*rows + c] == 0 || masksC[r*rows + c] != idSCMax) curImage.at<uchar>(r, c) = 0;
                        {
                            int s = SCMasks[masksC[r*rows + c]];
                            int sB = SMasksB[masksC[r*rows + c]];
                            int sP = SMasksP[masksC[r*rows + c]];
                            if (masksB[r*rows + c] != idSBMax) { continue;}
                            if (masksP[r*rows + c] != idSPMax) { continue;}
                            // std::cout << "s : " << s << " sB : " << sB << " sP : " << sP << " ||| \n";
                            if (sB * 10.0 >= s*6.0 || sP * 10.0 >= s*6.0) {
                                dd[masksC[r*rows+c]] = 1;
                                // std::cout << r << " " << c << "  |||\n";
                                continue;
                            }
                            // curImage.at<uchar>(r, c) = 0;
                        }

            }
        // // DEBUG
        //         cv::imshow("CUR", curImage);
        //         cv::imshow("PER", preImage);
        //         cv::imshow("BEF", befImage);
        //         cv::waitKey(0);
        //         // return 0;
        //         // end DEBUG
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (dd[masksC[r*rows + c]] == 0) curImage.at<uchar>(r, c) = 0;
        delete(dd);
        delete(masksB);
        delete(masksC);
        delete(masksP);
        delete(SMasksP);
        delete(SMasksB);
        delete(SCMasks);
        delete(SBMasks);
        delete(SPMasks);
        return 1;
    }

    static int checkImage(cv::Mat image){
    // // DEBUG
    //     cv::imshow("image", image);
    //     cv::waitKey(0);
    //     return 0;
    // // end DEBUG
        for (int r = 0; r < image.rows-1; r++)
            for (int c = 0; c < image.cols-1; c++)
                if ((int)image.at<uchar>(r, c) != 0) return 0;
        return 1;
    }

    static int loadName(std::vector<std::string> &listName, std::string path){
        DIR *dr;
        dr = opendir(path.c_str());
        if (dr == NULL) return 1;
        struct dirent *de;
        while ((de = readdir(dr)) != NULL)
        {
            std::string deName = de->d_name;
            if (deName == "." || deName == "..") continue;
            cv::Mat image = cv::imread(path + deName, 0);
            if (checkImage(image) == 0) listName.push_back(deName);
            
        }
        delete(de);
        closedir(dr);
        return 0;
    }

    static bool checkIndex(std::string p, std::string q){
        p.erase(p.size() - 4, 4);
        q.erase(q.size() - 4, 4);

        int ip = std::stoi(p);
        int iq = std::stoi(q);
        // std::cout << ip << " " << iq << " id\n";
        return ip - iq == 1;
    }

    static int loadMasks(std::string inpath, std::string outpath, std::vector<cv::Mat> &listImages, std::vector<std::string> &listNameReturn){
        // std::string arr[] = {"bladder", "prostate", "left femur", "rectum", "right femur"};
        // DIR *dip;
        // if ( (dip = opendir(inpath.c_str())) == NULL) return printf("Folder %s not found!", inpath), 1;
        // struct dirent *de;
        // while ((de = readdir(dip)) != NULL)
        // {
        //     std::string dename = de->d_name;
        
        //     if (dename == "." || dename == "..") continue;
            std::vector<std::string> listName;
        //     std::string rpath = inpath + "/" + de->d_name + "/";
        //     for (int i = 0; i < 5; ++i)
        //     {
        //     std::string path = rpath + arr[i] + "/predict/";
            
            if (loadName(listName, inpath)) return 0;
            // create folder if not exist
            // std::string outP = outpath + "/" + de->d_name + "/" + arr[i] + "/predict_pos/";
            
            // std::cout << listName.size() << "\n";
            // DIR *dircheck;
            // dircheck = opendir(outP.c_str());
            // if (dircheck == NULL){
            //     std::string cmd = "mkdir \"" + outP + "\"";
            //     system(cmd.c_str());
            // }
            std::cout << inpath << "\n";
            // std::cout << listName.size() << "\n";
            if (listName.empty()) return 0;
            // cv::Mat firstImage = cv::imread(inpath + listName[0], 0);
            
            bool check = true;
            // while(checkImage(firstImage) && !listName.empty()){
            //     listName.erase(listName.begin());
            //     firstImage = cv::imread(inpath + listName[0], 0);
            // }
            // if (!listName.empty()) checkMask(firstImage, firstImage, cv::imread(inpath + listName[1], 0));
            
            // if(checkImage(firstImage)){
            //     listName[0] = listName[1];
            //     check = false;
            // }
            
            // bool flag = true;
            // if (check){
            //     // flag = cv::imwrite(outP + listName[0], firstImage);
            //     listImages.push_back(firstImage);
            //     listNameReturn.push_back(listName[0]);
            //     // if (flag) std::cout << "Done! :";
            //     //     else std::cout << "Error! :";
            //     // std::cout << outP + listName[0] << "\n";
            // }
            // std::cout << inpath + listName[0] << "\n";
            
            std::vector<std::string> listNameCop;
            listNameCop.push_back(listName[0]);
            for (int id = 1; id < listName.size(); id++){
                if (checkIndex(listName[id], listName[id-1])) {
                    listNameCop.push_back(listName[id]);
                    if (id < listName.size() - 1) continue;
                }
                // std::cout << listNameCop[0] << " ";
                if (listNameCop.empty()) continue;
                for (int i = 1; i < listNameCop.size()-1; i++){
                    cv::Mat preImage = cv::imread(inpath + listNameCop[i-1], 0);
                    cv::Mat curImage = cv::imread(inpath + listNameCop[i], 0);
                    cv::Mat befImage = cv::imread(inpath + listNameCop[i+1], 0);
                    
                    // // DEBUG
                    // cv::imshow(listName[i], curImage);
                    // cv::imshow(listName[i-1], preImage);
                    // cv::imshow(listName[i+1], befImage);
                    // cv::waitKey(0);
                    // return 0;
                    // // end DEBUG
                    // if (checkImage(curImage)){
                    //     listNameCop[i] = listNameCop[i-1];
                    //     // std::cout << "run 247\n";
                    //     continue;
                    // }
                    checkMask(preImage, curImage, befImage);
                    
                    if (checkImage(curImage)){
                        listNameCop[i] = listNameCop[i-1];
                        // std::cout << "run 254\n";
                        continue;
                    }
                    // bool flag = cv::imwrite(outP + listName[i], curImage);
                    bool flag = true;
                    listImages.push_back(curImage);
                    listNameReturn.push_back(listName[i]);
                    // if (flag) std::cout << "Done! :";
                    //     else std::cout << "Error! :";
                    // std::cout << outP + listName[i] << "\n";
                    
                }
                listNameCop.clear();
                listNameCop.push_back(listName[id]);
                // std::cout << "hi\n";
                // cv::Mat lastImage = cv::imread(inpath + listName[listName.size()-1], 0);
                // // std::cout << inpath + listName[listName.size()-1];

                // // listNameReturn = listName;
                // // listNameReturn.push_back(listName[listName.size()-1]);
                // if (checkImage(lastImage)) return 1;
                
                // checkMask(listImages[listImages.size() - 1], lastImage, lastImage);
                //     //             // DEBUG
                //     // cv::imshow(listName[listName.size()-1], lastImage);
                //     // cv::waitKey(0);
                //     // // return 0;
                //     // // end DEBUG
                // if (checkImage(lastImage)) return 1;
                // 
                
                // // flag = cv::imwrite(outP + listName[listName.size()-1], lastImage);
                // flag = true;
                
                // listNameReturn.push_back(listName[listName.size()-1]);
                // listImages.push_back(lastImage);
                // listNameReturn = listName;
                // if (flag) std::cout << "Done! :";
                //     else std::cout << "Error! :";
                // std::cout << outP + listName[listName.size()-1] << "\n";

                // }
            // }
            // delete(de);
            // closedir(dip);
            // std::cout << "size : " << listNameReturn.size() << "\n";
            }
        return 1;
    }

};
// int main(int argc, char const *argv[])
// {
//     std::string inpath, outpath;
//     inpath = argv[1];
//     outpath = argv[2];

//     DIR *dircheck;
//     dircheck = opendir(outpath.c_str());
//     if (dircheck == NULL){
//         std::string cmd = "mkdir \"" + outpath + "\"";
//         system(cmd.c_str());
//     }

//     // std::cout << "input path : ";
//     // std::cin >> inpath;
//     // std::cout << "output path : ";
//     // std::cin >> outpath;
//     // std::cin >> path;
//     if (loadMasks(inpath, outpath)) return 1;
//     return 0;
// }
