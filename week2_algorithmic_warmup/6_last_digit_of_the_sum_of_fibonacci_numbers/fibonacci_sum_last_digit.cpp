#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n){
    if (n <= 1)
        return n;

    int fib[60]; fib[0] = 1;
    fib[1] = 1;
    int sum = 2;
    for(int i = 2;i<60;++i){
        fib[i] = fib[i-1]%10 + fib[i-2]%10;
        sum += fib[i]%10;
    }
    long long digit = n/60;
    int rem = n%60;
    sum = (digit*sum)%10;
    for(int i = 0;i<rem;++i){
        sum += fib[i]%10;
    }
    return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n)<<" ";
    std::cout << fibonacci_sum_fast(n);
}