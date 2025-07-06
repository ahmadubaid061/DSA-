#include <iostream>
using namespace std;
int findOccurrences(int dataList[], int size, int target, int indices[], int maxIndices) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (dataList[i] == target) {
            if (count < maxIndices) {
                indices[count] = i;
            }
            count++;
        }
    }
    return count;
}

int main() {
     
    int dataList[] = {1, 2, 3, 4, 2, 5, 2, 6};
    int size = sizeof(dataList) / sizeof(dataList[0]);
    int target = 2;
    
    int maxIndices = 10; 
    int indices[maxIndices];
    
    int occurrenceCount = findOccurrences(dataList, size, target, indices, maxIndices);

    cout << "Occurrences of " << target << " are at indices: ";
    for (int i = 0; i < occurrenceCount && i < maxIndices; ++i) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}
