#include "benchmark/benchmark.h"
#include "math/big_uint.h"
#include "math/fib.h"

namespace jp::math {

static void BM_Fib(benchmark::State& state) {
  for (auto _ : state) {
    fib(state.range(0));
  }
}

BENCHMARK(BM_Fib)->RangeMultiplier(2)->Range(1 << 16, 1 << 20)->Complexity();

}  // namespace jp::math
