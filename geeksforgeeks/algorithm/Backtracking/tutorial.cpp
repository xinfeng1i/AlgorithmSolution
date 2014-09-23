// Permutation Problem
// If you have no more characters left to rearrage, print the current permutation
// for (every possible choice among the characters left to rearrage)
// {
//      Make a choice and add that character to the permutation so far
//      Use recursion to rearrage the remaing letters
// }
//
void RecursivePermutation(string sofar, string remain)
{
    if (remain == "") cout << sofar << endl;

    for (size_t i = 0; i < remain.size(); ++i)
    {
        string sofar2 = sofar + remain[i];
        string remain2 = remain.substr(0, i) + remain.substr(i+1);
        RecursivePermutation(sofar2, remain2);
    }
}

// Subset Problem
//
// If there are no more elements remaining, print current subset
// Consider the next element of those remaining
// Try adding it to current subset and use recursion to build subsets from here
// Try not adding it to current subset and use recursion to build subsets from here
void RecursiveSubset(string sofar, string remain)
{
    // base case
    if (remain == "") { cout << sofar << endl; return; }
    
    char ch = remain[0];
    string remain2 = remain.substr(1);
    RecursiveSubset(sofar, remain2);        // choose first element
    RecursiveSubset(sofar + ch, remain2);   // not choose first element
}
