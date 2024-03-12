#pragma once
#include <vector>

using namespace std;

class RadixSort
{
public:
  /// <summary>
  /// Sorts vector according to Radix Sort.
  /// </summary>
  /// <param name="toSort">Vector to be sorted.</param>
  /// <returns>Sorted vector.</returns>
  static vector<int> Sort(vector<int> toSort)
  {
    auto maxVal = max_element(toSort.begin(), toSort.end());
    int maximumValue = distance(toSort.begin(), maxVal);

    for (int exponent = 1; maximumValue / exponent; exponent *= 10)
    {
      toSort = CountingSort(exponent, toSort);
    }
    return toSort;
  }
private:
  /// <summary>
  /// A counting sort algorithm that sorts the values according to a single place value.
  /// </summary>
  /// <param name="exponent">The place value that the sequence of values must be sorted by.</param>
  /// <param name="toSort">Sequence of values to be sorted.</param>
  /// <returns>Vector sorted according to a specific place value.</returns>
  static vector<int> CountingSort(int exponent, vector<int> toSort)
  {
    vector<int> outputVector(toSort.size(), 0);
    int occurences[10]{};

    for (int i = 0; i < toSort.size(); i++)
    {
      occurences[(toSort[i] / exponent) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
      occurences[i] += occurences[i - 1];
    }

    for (int i = toSort.size() - 1; i >= 0; i--)
    {
      outputVector[occurences[(toSort[i] / exponent) % 10] - 1] = toSort[i];
      occurences[(toSort[i] / exponent) % 10]--;
    }

    return outputVector;
  }
};

