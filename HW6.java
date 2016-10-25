/* #1 - Implement in C++ and Java three sorting algorithms, including
the merge-sort and quick-sort algorithms, and compare the implementations
on CPU time using three different inputs. */

public class Sort {
  public static void mergeSort(Comparable[] arr) {
    if (arr.length <= 1)
      return;

    Comparable[] tmp = new Comparable[arr.length];
    mergeSort(arr, tmp, 0, arr.length-1);
  }

  private static void mergeSort(Comparable[] arr, Comparable[]
                                tmp, int beg, int end) {
    if (beg < end) {
      int mid = beg + ((end - beg) / 2);

      mergeSort(arr, tmp, beg, mid);
      mergeSort(arr, tmp, mid+1, end);
      merge(arr, tmp, beg, mid, end);
    }
  }

  private static void merge(Comparable[] arr, Comparable[] tmp,
                            int beg, int mid, int end) {
    int i = beg;
    int j = mid+1;
    int index = beg;

    // While there's still values on the left or right side, add the
    // smaller element to the tmp array
    while (i < mid+1 || j < end+1) {
      while (arr[i].compareTo(arr[j]) <= 0)
        tmp[index++] = arr[i++];

      while (arr[j].compareTo(arr[i]) <= 0)
        tmp[index++] = arr[j++];
    }

    // Add the rest of the elements to the tmp array when one side is
    // exhausted of elements
    while (j >= end+1)
      tmp[index++] = arr[i++];

    while (i >= mid+1)
      tmp[index++] = arr[j++];

    // Copy the results back onto the original array
    for (int k = beg, k <= end; k++)
      arr[k] = tmp[k];
  }

  public static void quickSort(Comparable[] arr) {

  }

  public static void heapSort(Comparable[] arr) {

  }

  public static void main(String[] args) {
    for (int i = 0; i < 3; i++) {
      Scanner file = new Scanner(new File("./data" + i+1));
      int size = file.nextInt();
      int arr = new int[size];
      int index = 0;
      while(file.hasNextInt() && index < size) {
          arr[index] = file.nextInt();
          index++;
      }
      long timeNow = System.currentTimeMillis();
      mergeSort(arr.clone());
      System.out.println("Merge Sort: " + System.currentTimeMillis() - timeNow);
      timeNow = System.currentTimeMillis();
      quickSort(arr.clone());
      System.out.println("Quick Sort: " + System.currentTimeMillis() - timeNow);
      timeNow = System.currentTimeMillis();
      heapSort(arr.clone());
      System.out.println("Heap Sort: " + System.currentTimeMillis() - timeNow);
    }
  }
}

/* #2 - Write a function that counts the number of n-letter words of
the alphabet Σ = {a, b} that do not contain the string aa; use dynamic
programming to speed-up the function. */
// Bottom up DP solution
public static int numWords(int n) {
  int memo = new int[n];
  memo[0] = 1;
  memo[1] = 2;
  memo[2] = 3;

  if (n <= 2)
    return memo[n];

  for (int i = 3; i < n; i++) {
    // memo[i-1] has memo[i-3] strings ending in 'a' and memo[i-2]
    // strings ending in 'b'; there is only one way to continue with
    // an 'a' as the last char and TWO ways to continue with a 'b'
    // as the last char
    memo[i] = memo[i-3] + (2 * memo[i-2]);

    // this also works
    // memo[i] = memo[i-1] + memo[i-2];
  }
  return memo[n];
}

/* #3 - Write a function that returns a list of all of the n-element subsets
of a given set. For example, if the given set is [1,2,3] and n is 2, then
the returned list should contain [1,2], [1,3], and [2,3]. The order of the
elements is not important. */

public static List<Set<int>> subsetsOfSet(Set<int> input, int n) {
  List<Set<int>> results = new List<Set<int>>();
  findAllSubsets(input, n, 0, results, new Set<int>());
  return results;
}

private static List<Set<int>> findAllSubsets(Set<int> input, int targetSize,
                                             int index, List<Set<int>> results) {
  // if there's no elements left in the set, end this recursive chain
  if (index > input.size())
    return;
  // if there's not enough elements left to be added to the current set,
  // end this recursive chain
  if (targetSize > currentSet.size() + (input.size() - index))
    return;

  if (currentSet.size() == targetSize) {
    results.add(currentSet);
    return;
  }

  findAllSubsets(input, targetSize, index+1, results, currentSet.clone().add(input[index]));
  findAllSubsets(input, targetSize, index+1, results, currentSet.clone());
}

#4
