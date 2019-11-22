#ifndef METHODS_H
#define METHODS_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <tuple>
#include <utility>

namespace dilawar {

static std::default_random_engine gen_;
static std::uniform_real_distribution<> dist_;

template <typename T = double>
T uniform(T a = 0.0, T b = 1)
{
    T x = dist_(gen_);
    return (b - a) * x + a;
}

template <typename T, typename R = double>
std::pair<int, R> choiceProb(const T& values, const T& probs)
{
    R acc = 0;
    R r = dist_(gen_);
    assert(true ==
           approximatelyEqual(
               1.0, std::accumulate(probs.begin(), probs.end(), 0.0), 1e-9));
    auto N = probs.size();
    for (int i = 0; i < N; i++) {
        acc += probs[i];
        if (r <= acc) return make_pair(i, values[i]);
    }

    // return the last indices??
    // if(acc < 1.0)
    // return make_pair(N-1, values[N-1]);

    std::cerr << "Could not choose indices. " << std::endl;
    return make_pair(-1, nan("Invalid index"));
}

template <typename T, typename R = double>
std::pair<int, R> choiceWeighted(const T& values, const T& weights)
{
    R acc = 0.0;
    R W = accumulate(weights.begin(), weights.end(), 0.0);
    T prob(weights.size());
    std::transform(values.begin(), values.end(), prob.begin(),
                   [W](R x) -> R { return x / W; });
    return choiceProb(values, prob);
}

}  // namespace dilawar

#endif /* end of include guard: METHODS_H */
