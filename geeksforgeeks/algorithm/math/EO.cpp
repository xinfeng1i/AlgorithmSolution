#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
using namespace std;

struct Gene
{
    size_t index_;
    bool value_;
    double fitness_;
public://constructor
    Gene(size_t index, bool value, double fitness):index_(index),
                                                   value_(value),
                                                   fitness_(fitness)
    {}
};

struct Chromesome
{
    vector<Gene> geneList_;
};

// return the objective Function value of the given Chromesome s
double CalculateObjectiveFunctionValue(Chromesome s);
// Mutate the index-th gene of chromesome s to get a new chromesome
Chromesome MutateGene(Chromesome s, size_t index);

// choose a "worst" gene according to their fitness, return the index
// of the chosen gene
size_t ChooseWorstGene(Chromesome s);

// generate a solution randomly
//      1. generate the binary string
//      2. calculate the objective function
//
// for each gene at pos j, caculate its fitness \lambda j
//      1. mutation at pos j
//      2. calculate the objective function
//      3. calculate the current global best objective function
//      4. return its fitness
//
// sort the all the gene according to their fitness ascendingly
//      1. sturct {index,value,fitness} sort them with fitness
//
// select a genene randomly according to the probability distribution
//      2. wheel algorithm to select a worst gene, get its index
//
// mutation on the selected genene to generate the new solution D'
//      1. mutation the selected gene
//      2. get a new D'
//      3. calculate the objective function of the new D'
//
// update the current solution D = D'
//
// if D is better than the global solution D(best)
// update D(best) = D
//
// iteration += 1 goto step 1
