bool isVowels(int ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
string reverseVowels(string s) {
    int n = (int)s.size();
    int i = 0; int j = n - 1;
    while (i < j) {
        while (i < j && !isVowels(s[i])) i++;
        while (j > i && !isVowels(s[j])) j--;
        if (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}
