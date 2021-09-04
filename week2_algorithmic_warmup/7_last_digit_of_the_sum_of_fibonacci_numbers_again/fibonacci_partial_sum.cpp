#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    if (to <= 1)
        return to;

    int fib[60]; fib[0] = 0;
    fib[1] = 1;
    int sum = 1;
    for(int i = 2;i<60;++i){
        fib[i] = fib[i-1]%10 + fib[i-2]%10;
        sum += fib[i]%10;
    }
    int fib_sum = 0;
    long long from_q = from/60;
    int from_r = from%60;
    int temp_sum = (from_q*sum)%10;
    for(int i = 0;i<from_r;++i){
        temp_sum += fib[i]%10;
    }
    temp_sum = temp_sum%10;
    long long to_q = to/60;
    int to_r = to%60;
    fib_sum = (to_q*sum)%10;
    for(int i = 0;i<=to_r;++i){
        fib_sum += fib[i]%10;
    }
    fib_sum = fib_sum%10;
    fib_sum = 10 + fib_sum - temp_sum;
    return fib_sum%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to);
}
