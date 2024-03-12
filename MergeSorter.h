#pragma once
#include <vector>

using namespace std;
/// <summary>
/// Class used to merge sort.
/// </summary>
class MergeSorter
{
public:
  /// <summary>
  /// Takes a vector of integers and sorts it via merge sort.
  /// </summary>
  /// <param name="toSort">Vector of unsorted integers.</param>
  /// <returns>Vector of sorted integers.</returns>
  static vector<int> mergeSortAsc(vector<int> toSort)
  {
    if (isSorted(toSort))
    {
      return toSort;
    }
    int middle = toSort.size() / 2;
    vector<int> left(toSort.begin(), toSort.begin() + middle);
    vector<int> right(toSort.begin() + middle, toSort.end());

    left = mergeSortAsc(left);
    right = mergeSortAsc(right);

    return merge(left, right);
  }
private:
  static bool isSorted(vector<int> toSort)
  {
    if (toSort.size() <= 1)
    {
      return true;
    }
    for (int i = 1; i < toSort.size(); i++)
    {
      if (toSort[i] < toSort[i - 1])
      {
        return false;
      }
    }
    return true;
  }
  /// <summary>
  /// Function used to sort two vectors and return as one sorted vector.
  /// </summary>
  /// <param name="toMergeLeft">Left vector to be merged with right.</param>
  /// <param name="toMergeRight">Right vector to be merged with left. </param>
  /// <returns></returns>
  static vector<int> merge(vector<int> toMergeLeft, vector<int> toMergeRight)
  {
    vector<int> merged;

    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < toMergeLeft.size() && rightIndex < toMergeRight.size())
    {
      if (toMergeLeft[leftIndex] <= toMergeRight[rightIndex])
      {
        merged.push_back(toMergeLeft[leftIndex]);
        leftIndex++;
      }
      else
      {
        merged.push_back(toMergeRight[rightIndex]);
        rightIndex++;
      }
    }

    while (leftIndex < toMergeLeft.size())
    {
      merged.push_back(toMergeLeft[leftIndex]);
      leftIndex++;
    }

    while (rightIndex < toMergeRight.size())
    {
      merged.push_back(toMergeRight[rightIndex]);
      rightIndex++;
    }

    return merged;
  }

};

