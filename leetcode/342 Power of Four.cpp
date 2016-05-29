// 计算二进制中1的个数 
int numberOfOnes(int x) {
    int cnt = 0;
    while (x) {
        x = x & (x-1);
        cnt++;
    }
    return cnt;
}
//
bool isPowerOfFour(int num) {
    if (num < 0) return false;
    // 保证二进制中仅有一个1，并且1后面跟了2,4,6,8,10个零 
    if (numberOfOnes(num) == 1 && numberOfOnes(num-1) % 2 == 0) return true;
    else return false;
}
