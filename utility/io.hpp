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
string mapToCSV(const map<string, vector<T>>& data)
{
    string s;
    char delim = ' ';
    vector<string> header;
    for (auto &v: data)
    {
        s += v.first + delim;
        header.push_back(v.first);
    }

    s.pop_back();
    s += '\n';

    size_t N = data[header[0]].size();
    for(size_t i = 0; i < N; i++) {
        for (auto &h: header) {
            s += to_string(data[header][i]) << delim;
            s.pop_back(); s += '\n';
        }
    }
    return s;
}

}  // namespace dilawar

#endif /* end of include guard: IO_H */
