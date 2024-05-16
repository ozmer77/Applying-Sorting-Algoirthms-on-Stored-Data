#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int RandomNumbers() {

    int randomSayi = rand() % 10000;
    return randomSayi;
}

void dosyayaz(const string& filename) {
    ofstream dosya(filename);
    int sayi;
    if (dosya.is_open()) {
        for (int i = 1; i < 1000; i++) {
            sayi = RandomNumbers();
            dosya << sayi << endl;
        }

    }
    dosya.close();

}

void selectionSorting(const string& filename) {
    ifstream dosya(filename);

    string line;
    if (!dosya.is_open()) {
        cerr << "dosya açılamadı " << endl;
    }

    int arr[1000];
    int index = 0;

    while (getline(dosya, line) && index < 1000) {
        arr[index] = stoi(line);
        index++;
    }
    dosya.close();


    for (int i = 0; i < 999; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 1000; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    for (int i = 0; i < 1000; i++) {
        cout << arr[i] << endl;
    }
}

void insertionSort(const string& filename) {
    ifstream dosya(filename);

    string line;
    if (!dosya.is_open()) {
        cerr << "dosya açılamadı " << endl;
    }

    int arr[1000];
    int index = 0;

    while (getline(dosya, line) && index < 1000) {
        arr[index] = stoi(line);
        index++;
    }
    dosya.close();

    int deger, j;
    for (int i = 1; i < 1000; i++) {
        deger = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > deger) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = deger;
    }
    for (int i = 0; i < 1000; i++) {
        cout << arr[i] << endl;
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    int leftSubarrayCapacity = mid - low + 1;
    int rightSubarrayCapacity = high - mid;

    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while (i < leftSubarrayCapacity && j < rightSubarrayCapacity) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSubarrayCapacity) {
        arr[k++] = left[i++];
    }

    while (j < rightSubarrayCapacity) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int>& arr, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void mergeSortFromFile(const std::string& filename) {
    ifstream file(filename);
    vector<int> arr;
    string line;

    if (!file.is_open()) {
        cerr << "Dosya açılamadı." << endl;
        return;
    }

    while (getline(file, line)) {
        arr.push_back(stoi(line));
    }
    file.close();

    mergeSort(arr, 0, arr.size() - 1);

    // Dosyadan okunan ve sıralanan sayıları göstermek için (opsiyonel):
    for (int num : arr) {
        cout << num << endl;
    }
}




int main()
{
    string file = "numbers.txt";
    mergeSortFromFile(file);
  // selectionSorting(file);
   // insertionSort(file);
   // dosyayaz(file); birkere kullandık ve dosyaya 1000 tane random sayı yazdırdık.
}


