class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long x = max(A, E) < min(C, G) ? (min(C, G) - max(A, E)) : 0;
    long y = max(B, F) < min(D, H) ? (min(D, H) - max(B, F)) : 0;

    return (long)(C - A) * (long)(D - B) + (long)(G - E) * (long)(H - F) -
           x * y;
  }
};