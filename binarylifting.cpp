#include <bits/stdc++.h>
using namespace std;
 
// Table for storing 2^ith parent
int **table;
 
// To store the height of the tree
int height;
 
// initializing the table and
// the height of the tree
void initialize(int n)
{
    height = (int)ceil(log2(n));
    table = new int *[n + 1];
}
 
// Filling with -1 as initial
void preprocessing(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        table[i] = new int[height + 1];
        memset(table[i], -1, sizeof table[i]);
    }
}
 
// Calculating sparse table[][] dynamically
void calculateSparse(int u, int v)
{
    // Using the recurrence relation to
    // calculate the values of table[][]
    table[v][0] = u;
    for (int i = 1; i <= height; i++)
    {
        table[v][i] = table[table[v][i - 1]][i - 1];
 
        // If we go out of bounds of the tree
        if (table[v][i] == -1)
            break;
    }
}
 
// Function to return the Kth ancestor of V
int kthancestor(int V, int k)
{
    // Doing bitwise operation to
    // check the set bit
    for (int i = 0; i <= height; i++)
    {
        if (k & (1 << i))
        {
            V = table[V][i];
            if (V == -1)
                break;
        }
    }
    return V;
}
 
// Driver Code
int main()
{
    // Number of vertices
    int n = 6;
 
    // initializing
    initialize(n);
 
    // Pre-processing
    preprocessing(n);
 
    // Calculating ancestors of v
    calculateSparse(1, 2);
    calculateSparse(1, 3);
    calculateSparse(2, 4);
    calculateSparse(2, 5);
    calculateSparse(3, 6);
 
    int K = 2, V = 5;
    cout << kthancestor(V, K) << endl;
 
    return 0;
}
 