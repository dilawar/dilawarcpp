// =====================================================================================
//
//       Filename:  io.hpp
//
//    Description: I/O utilities.
//
//        Version:  1.0
//        Created:  11/22/2019 11:27:10 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Dilawar Singh (), dilawar.s.rajput@gmail.com
//   Organization:  NCBS Bangalore
//
// =====================================================================================

#ifndef IO_H
#define IO_H

#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

namespace dilawar {

template <typename T = std::string>
void writeFile(const T& data, const string& path)
{
    ofstream f;
    f.open(path);
    f << data;
    f.close();
}

template <typename T = std::string>
void appendFile(const T& data, const string& path)
{
    ofstream f;
    f.open(path, ios::app);
    f << data;
    f.close();
}

template<typename T=double>
string mapToCSV(const map<string, vector<T> >& data)
{
    stringstream ss;
    ss << fixed;
    char delim = ' ';
    vector<vector<double>> cols;
    size_t nCols = 0;
    for (auto it = data.begin(); it != data.end(); it++)
    {
        nCols += 1;
        ss << it->first << delim;
        cols.push_back(it->second);
    }

    ss.seekp(-1, ss.cur); ss << endl;

    for (size_t ii = 0; ii < cols[0].size(); ii++) {
        for (size_t i = 0; i < nCols; i++)
            ss << cols[i][ii] << delim;

        ss.seekp(-1, ss.cur); ss << endl;
    }
    return ss.str();
}

}  // namespace dilawar

#endif /* end of include guard: IO_H */
