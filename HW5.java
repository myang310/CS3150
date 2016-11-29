// Ming Yang

import org.apache.commons.lang3.ArrayUtils;

public class Solution {
  // Arithmetic functions and relations
  public static int succ(int x) {
    return x+1;
  }
  public static int pred(int x) {
    return x-1;
  }
  public static int add(int x, int y) {
    if (x == 0) return y;
    return succ(add(pred(x), y));
  }
  public static int sub(int x, int y) {
    if (y == 0) return x;
    return sub(pred(x), pred(y));
  }
  public static int mul(int x, int y) {
    if (x == 0) return 0;
    return add(mul(pred(x), y), y);
  }
  public static int div(int x, int y) {
    if (lt(x, y)) return 0;
    return succ(div(sub(x, y), y));
  }
  public static int rem(int x, int y) {
    if (lt(x, y)) return x;
    return rem(sub(x, y), y);
  }
  public static int exp(int x, int y) {
    if (y == 0) return succ(0);
    return mul(x, exp(x, pred(y)));
  }
  public static int fact(int x) {
    if (x == 0) return succ(0);
    return mul(x, fact(pred(x)));
  }
  public static int gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return gcd(y, rem(x, y));
  }
  public static int fib(int x) {
    if (x == 1 || x == 2) return succ(0);
    return add(fib(pred(x)), fib(pred(pred(x))));
  }

  // Comparisons
  public static boolean le(int x, int y) {
    if (x == 0) return true;
    if (y == 0) return false;
    return le(pred(x), pred(y));
  }
  public static boolean lt(int x, int y) {
    return le(succ(x), y);
  }
  public static boolean ge(int x, int y) {
    return le(y, x);
  }
  public static boolean gt(int x, int y) {
    return lt(y, x);
  }
  public static boolean eq(int x, int y) {
    return ge(x, y) && ge(y, x);
  }

  // Functions on arrays
  public static T first(T[] arr) {
    return arr[0];
  }
  public static T last(T[] arr) {
    if (len(arr) == 1) return arr[0];
    return last(Arrays.copyOfRange(arr, 1, len(arr)));
  }
  public static boolean contains(T[] arr, E ele) {
    if (arr[0] == ele) return true;
    return contains(Arrays.copyOfRange(arr, 1, len(arr)));
  }
  public static int find_first_of(T[] arr, E ele) {
    return find_first_of(arr, ele, 0);
  }
  private static int find_first_of(T[] arr, E ele, int index) {
    if (arr[0] == ele) return index;
    if (len(arr) == 0) return -1;
    return find_first_of(Arrays.copyOfRange(arr, 1, len(arr)), ele, succ(index));
  }
  public static int find_last_of(T[] arr, E ele) {
    return find_last_of(arr, ele, 0, -1);
  }
  private static int find_last_of(T[] arr, E ele, int index, int prev) {
    if (len(arr) == 0) return prev;
    if (arr[0] == ele) return find_last_of(Arrays.copyOfRange(arr, 1, len(arr)), ele, index+1, index);
    return find_last_of(Arrays.copyOfRange(arr, 1, len(arr)), ele, index+1, prev);
  }
  public static int kth_elm(T[], int index) {
    if (index == 1) return arr[0];
    return kth_elm(Arrays.copyOfRange(arr, 1, len(arr)), index-1);
  }
  public static int len(T[] arr) {
    return arr.length;
  }
  public static T[] reverse(T[] arr) {
    if (arr.length == 0) return arr;
    return reverse(ArrayUtils.addAll(Arrays.copyOfRange(1, arr.length), Arrays.copyOfRange(0, 1)));
  }

  // Test the functions
  public static void main(String[] args) {
    test_arith();
    test_list();
  }
  private static void test_arith() {
    int x = succ(succ(succ(0)));
    int y = succ(succ(0));
    System.out.printf("%d + %d = %d%n", x, y, add(x, y));
    System.out.printf("%d - %d = %d%n", x, y, sub(x,y));
    System.out.printf("%d * %d = %d%n", x, y, mul(x,y));
    System.out.printf("%d / %d = %d%n", x, y, div(x,y));
    System.out.printf("%d \% %d = %d%n", x, y, rem(x,y));
    System.out.printf("%d ^ %d = %d%n", x, y, exp(x,y));
    System.out.printf("%d! = %d%n", x, fact(x));
    System.out.printf("gcd(%d,%d) = %d%n", x, y, gcd(x,y));
    System.out.printf("fib(%d) = %d%n", x, fib(x));
  }
  private static void test_list() {
    String[] arr = {"a", "b", "c", "a", "b"};
    System.out.println("first(arr) = " + first(arr));
    System.out.println("last(arr) = " + last(arr));
    if (contains(arr,"a")
        System.out.println(arr + " contains a");
    System.out.println("find_first_of(arr, b) = " + find_first_of(arr, "b"));
    System.out.println("find_last_of(arr, b) = " + find_last_of(arr, "b"));
    System.out.println("kth(arr, 3) = " + kth_elm(arr ,3));
    System.out.println("len(arr) = " + len(arr));
    System.out.println("reverse(arr) = " + reverse(arr));
  }
}
