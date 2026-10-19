vector<int> mindiv;
vector<int> primes;
void sieve(int N) {
    mindiv = vector<int>(N+1, 0);
    primes = vector<int>();
    for(int i=2; i <= N; ++i) {
        if(mindiv[i] == 0) {
            mindiv[i] = i;
            primes.push_back(i);
        }
        for(int j=0; j < primes.size() and primes[j] <= mindiv[i] and primes[j]*i <= N; ++j) {
            mindiv[i*primes[j]] = primes[j];
        }
    }
}