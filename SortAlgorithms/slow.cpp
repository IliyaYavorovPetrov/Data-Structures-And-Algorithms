#include <bits/stdc++.h>

// WORST: O(N^2) BEST: O(N^2) AVERAGE: O(N^2) SPACE: O(1)
std::vector<int> bubbleSort(std::vector<int> input)
{
    for (size_t i = 0; i < input.size() - 1; i++)
    {
        for (size_t j = 0; j < input.size() - i - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                std::swap(input[j], input[j + 1]);
            }
        }
    }

    return input;
}

// WORST: O(N^2) BEST: O(N^2) AVERAGE: O(N^2) SPACE: O(1)
std::vector<int> selectionSort(std::vector<int> input)
{
    for (size_t i = 0; i < input.size() - 1; i++)
    {
        int indexMax = 0;
        int tempMax = INT_MIN;
        for (size_t j = 0; j < input.size() - i; j++)
        {
            if (tempMax < input[j])
            {
                indexMax = j;
                tempMax = input[j];
            }
        }

        std::swap(input[indexMax], input[input.size() - i - 1]);
    }

    return input;
}

// WORST: O(N^2) BEST: O(N) AVERAGE: O(N^2) SPACE: O(1)
std::vector<int> insertionSort(std::vector<int> input)
{
    for (size_t i = 1; i < input.size(); i++)
    {
        int high = input[i];
        int highIndex = i - 1;
        for (size_t j = i - 1; j >= 0; j--)
        {
            if (input[j] > high)
            {
                input[j + 1] = input[j];
            }
            else
            {
                highIndex = j;
                break;
            }
        }

        input[highIndex + 1] = high;
    }

    return input;
}

int main() 
{
    std::vector<int> input = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};

    std::vector<int> sortedInput = input;
    std::sort(sortedInput.begin(), sortedInput.end());

    std::vector<std::string> result;
    bubbleSort(input) == sortedInput ? result.push_back("Bubble Sort passed\n") : result.push_back("Bubble Sort not passed\n");
    selectionSort(input) == sortedInput ? result.push_back("Selection Sort passed\n") : result.push_back("Selection Sort not passed\n");
    insertionSort(input) == sortedInput ? result.push_back("Insertion Sort passed\n") : result.push_back("Insertion Sort not passed\n");

    // Result
    for (auto &&i : result)
    {
        std::cout << i;
    }

    return 0;
}