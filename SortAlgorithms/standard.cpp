#include <bits/stdc++.h>

// WORST: O(N*LGN) BEST: O(N*LGN) AVERAGE: O(N*LGN) SPACE: O(N)
void mergeSort(std::vector<int> &arr, int left, int right)
{
    auto merge = [](std::vector<int> &arr, int left, int mid, int right)
    {
        std::vector<int> temp = arr;
        int first = left;
        int index = left;
        int second = mid + 1;

        while (first <= mid && second <= right)
        {
            if (arr[first] < arr[second])
            {
                temp[index] = arr[first];
                index++;
                first++;
            }
            else
            {
                temp[index] = arr[second];
                index++;
                second++;
            }
        }

        while (first <= mid)
        {
            temp[index] = arr[first];

            index++;
            first++;
        }
        while (second <= right)
        {
            temp[index] = arr[second];
            index++;
            second++;
        }
        for (first = left; first < index; first++)
        {
            arr[first] = temp[first];
        }
    };

    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// WORST: O(N^2) BEST: O(N*LGN) AVERAGE: O(N*LGN) SPACE: O(LGN)
void quickSort(std::vector<int> &arr, int left, int right)
{
    
    auto partition = [](std::vector<int> &arr, int left, int right)
    {
        int pivot = arr[right];
        int index = left;

        for (size_t i = left; i < right; i++)
        {
            if (arr[i] < pivot)
            {
                std::swap(arr[index], arr[i]);
                ++index;
            }
        }

        std::swap(arr[index], arr[right]);

        return index;
    };

    if (left < right)
    {
        int part = partition(arr, left, right);

        quickSort(arr, left, part - 1);
        quickSort(arr, part + 1, right);
    }
}

int main()
{
    std::vector<int> input = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};

    std::vector<int> sortedInput = input;
    std::sort(sortedInput.begin(), sortedInput.end());

    std::vector<std::string> result;

    std::vector<int> tempMerge = input;
    mergeSort(tempMerge, 0, tempMerge.size() - 1);
    tempMerge == sortedInput ? result.push_back("Merge Sort passed\n") : result.push_back("Merge Sort not passed\n");

    std::vector<int> tempQuick = input;
    quickSort(tempQuick, 0, tempQuick.size() - 1);
    tempQuick == sortedInput ? result.push_back("Quick Sort passed\n") : result.push_back("Quick Sort not passed\n");

    // Result
    for (auto &&i : result)
    {
        std::cout << i;
    }

    return 0;
}