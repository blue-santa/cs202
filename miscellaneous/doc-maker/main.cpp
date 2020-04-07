#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <filesystem>

#include "meta.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::make_pair;
using std::setw;
using std::right;
using std::left;

namespace fs = std::filesystem;

int main() {

    string path_downloads = "/home/siddhartha/Downloads/";
    string path_test = "/home/siddhartha/Desktop/test/";
    // string path_books = "/home/siddhartha/Documents/01-Studio/03-Personal-Public/01-Exercises/01-Book-Learning/"; 
    string path_intro = "2020-04-07-";
    vector<string> filenames;
    for (const auto & entry : fs::directory_iterator(path_downloads)) {
        string curr_file_name = entry.path();
        size_t last_instance_div = curr_file_name.find_last_of('/');

        curr_file_name = curr_file_name.substr((int)last_instance_div + 1, (int)curr_file_name.size());

        // size_t last_instance_per = curr_file_name.find_last_of('.');
        string curr_dir_name;
        curr_dir_name = curr_file_name.substr(0, (int)curr_file_name.size() - 4);
        cout << endl;
        cout << "Current File Name: " << curr_file_name << endl ;

        string curr_path = path_test + path_intro + curr_dir_name + "/";
        cout << "Making Directory: " << curr_path << endl << endl;

        fs::create_directory(curr_path);
        fs::copy(entry, curr_path + curr_file_name);

    }

    // vector<string> baselineFileNames;
    // callBaselineFilenames(baselineFileNames);

    /********************************************************************
     * Process Baseline Files
    ********************************************************************/
    // vector< vector< pair< string, int>>> baselineFileData;
    // processBaselineFiles(baselineFileData, baselineFileNames); 

    /********************************************************************
     * Process Main File
    ********************************************************************/
    // vector< pair<string, int> > mainData; 
    // string inputFilename = "doc.stops.stems.freq.1.txt";

    // processFile(inputFilename, mainData);

    /********************************************************************
     * Process Output Files for Each Baseline File
    ********************************************************************/
    // processBaselineOutputFiles(baselineFileNames, baselineFileData);

    /********************************************************************
     * Process main output file
    ********************************************************************/
    // string mainOutputFile = "output.txt";
    // processOutputFile(mainOutputFile, mainData);

    return 0;
}
