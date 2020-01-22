clang++ -std=c++17 -g -O0 -fsanitize=fuzzer,address,signed-integer-overflow -lpthread fuzz_search.cpp -o fuzzer
