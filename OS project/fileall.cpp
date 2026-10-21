// file allocation system 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate required blocks
int requiredBlocks(int fileSize, int blockSize) {
    return ceil((double)fileSize / blockSize);
}

// Contiguous Allocation
void contiguousAllocation(vector<int> files, int blockSize) {
    cout << "\nContiguous Allocation:\n";
    int start = 0;
    for (int i = 0; i < files.size(); i++) {
        int blocks = requiredBlocks(files[i], blockSize);
        cout << "File " << i + 1 << " blocks: ";
        for (int j = start; j < start + blocks; j++) {
            cout << j << " ";
        }
        start += blocks;
        cout << endl;
    }
    cout << "Note: May cause external fragmentation if memory is fragmented.\n";
}

// Linked Allocation
void linkedAllocation(vector<int> files, int blockSize) {
    cout << "\nLinked Allocation:\n";
    int blockNumber = 0;
    for (int i = 0; i < files.size(); i++) {
        int blocks = requiredBlocks(files[i], blockSize);
        cout << "File " << i + 1 << " blocks (linked list): ";
        for (int j = 0; j < blocks; j++) {
            cout << blockNumber << " -> ";
            blockNumber++;
        }
        cout << "NULL" << endl;
    }
    cout << "No external fragmentation.\n";
}

// Indexed Allocation
void indexedAllocation(vector<int> files, int blockSize) {
    cout << "\nIndexed Allocation:\n";
    int blockNumber = 0;
    for (int i = 0; i < files.size(); i++) {
        int blocks = requiredBlocks(files[i], blockSize);
        cout << "File " << i + 1 << " index block points to: ";
        for (int j = 0; j < blocks; j++) {
            cout << blockNumber << " ";
            blockNumber++;
        }
        cout << endl;
    }
    cout << "Direct access possible, no external fragmentation.\n";
}

int main() {
    vector<int> files = {10, 6, 8}; // File sizes in KB
    int blockSize = 4; // Block size in KB

    contiguousAllocation(files, blockSize);
    linkedAllocation(files, blockSize);
    indexedAllocation(files, blockSize);

    return 0;
}
