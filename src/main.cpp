#include <chrono>
#include <iostream>
#include "home_sales.h"

using namespace std;

const int TEST_RUNS = 100;
const int AVG_PRICE_PER_SQ_FT = 222;

void measureBenchmark(const string& name, function<void(void)> benchmark)
{
	int total = 0;
	for (int i = 0; i < TEST_RUNS; i++) {
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		benchmark();
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		total += chrono::duration_cast<chrono::microseconds>(end - begin).count();
	}
	cout << name << ": " << (total / TEST_RUNS) << " μs" << endl;
}

int main()
{
	measureBenchmark("Allocation", [] { allocateSalesData(); });
	measureBenchmark("Function call", [] { assert(averagePricePerSqFt() == AVG_PRICE_PER_SQ_FT); });
	return EXIT_SUCCESS;
}
