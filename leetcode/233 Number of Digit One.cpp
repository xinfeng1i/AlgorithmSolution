int countDigitOne(int x) {
    if (x <= 0) return 0;
    long long n = x;
    long long n2 = x;
    long long fact = 10;
    long long rb = 1;
    long long cnt = 0;
    while (n2 > 0) {
        cnt += (n)/fact*rb + (n%fact < rb ? 0 : min((n%fact-rb)+1, rb));
        fact *= 10;
        rb *= 10;
        n2 /= 10;
    }
    return (int)cnt;
    
}
