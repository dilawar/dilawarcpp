// =====================================================================================
//
//       Filename:  numeric.hpp
//
//    Description:
//
//        Version:  1.0
//        Created:  11/23/2019 12:30:55 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Dilawar Singh (), dilawar.s.rajput@gmail.com
//   Organization:  NCBS Bangalore
//
// =====================================================================================

#include <numeric>
using namespace std;

#ifndef NUMERIC_H
#define NUMERIC_H

namespace dilawar {

// These are from Knuth and from here
// https://stackoverflow.com/a/253874/1805129

template <typename T = double>
bool approximatelyEqual(T a, T b, T epsilon)
{
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template <typename T = double>
bool essentiallyEqual(T a, T b, T epsilon)
{
    return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template <typename T = double>
bool definitelyGreaterThan(T a, T b, T epsilon)
{
    return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template <typename T = double>
bool definitelyLessThan(T a, T b, T epsilon)
{
    return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

}  // namespace dilawar

#endif /* end of include guard: NUMERIC_H */
