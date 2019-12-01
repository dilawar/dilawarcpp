// =====================================================================================
//
//       Filename:  boost.hpp
//
//    Description: Boost Helpers.
//
//        Version:  1.0
//        Created:  11/22/2019 11:41:07 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Dilawar Singh (), dilawar.s.rajput@gmail.com
//   Organization:  NCBS Bangalore
//
// =====================================================================================

#ifndef BOOST_H
#define BOOST_H

#include <boost/histogram.hpp>
#include <boost/format.hpp>
#include <sstream>

using namespace boost::histogram;

namespace dilawar {

    template<typename A, typename S>
std::string hist1DToCSV(boost::histogram::histogram<A, S>& hist)
{
    std::stringstream ss;
    for (auto && x: indexed(hist, coverage::all)) {
        auto midPoint = (x.bin().lower() + x.bin().upper())/2.0;
        ss << boost::format("%1%,%2%") % midPoint % *x << endl;
    }
    return ss.str();
}

}  // namespace dilawar

#endif /* end of include guard: BOOST_H */
