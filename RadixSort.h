#pragma once
#include <vector>
#include <functional>

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
    int maximumValue = distance(toSort.begin(), max_element(toSort.begin(), toSort.end()));
    int minimumValue = distance(toSort.begin(), min_element(toSort.begin(), toSort.end()));
    int chosenVal;
    if (maximumValue >= abs(minimumValue))
    {
      chosenVal = maximumValue;
    }
    else
    {
      chosenVal = minimumValue;
    }
    for (int exponent = 1; chosenVal / exponent; exponent *= 10)
    {
      toSort = CountingSort(exponent, toSort);
    }
    vector<int> sorted = GetOrdered(toSort);
    return sorted;
  }
private:

  static vector<int> GetOrdered(vector<int> allVals)
  {
    vector<int> negatives;

    for (int i = 0; i < allVals.size(); i++)
    {
      if (allVals[i] < 0)
      {
        negatives.push_back(allVals[i]);
        allVals.erase(allVals.begin() + i);
        i--;
      }
    }
    reverse(negatives.begin(), negatives.end());

    negatives.insert(negatives.end(), allVals.begin(), allVals.end());

    return negatives;
  }

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
      occurences[abs((toSort[i] / exponent) % 10)]++;
    }

    for (int i = 1; i < 10; i++)
    {
      occurences[i] += occurences[i - 1];
    }

    for (int i = toSort.size() - 1; i >= 0; i--)
    {
      outputVector[occurences[abs((toSort[i] / exponent) % 10)] - 1] = toSort[i];
      occurences[abs((toSort[i] / exponent) % 10)]--;
    }
    return outputVector;
  }
};

