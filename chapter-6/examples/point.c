#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
  int x;
  int y;
};

struct rect {
  // Rectangle includes its left and bottom sides
  // but not its top and right sides
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);

int main() {
  struct point maxpt = {320, 200};
  printf("%d, %d\n", maxpt.x, maxpt.y);

  struct point p1 = {1, 2};
  struct point p2 = {3, 4};
  struct point sumpt = addpoint(p1, p2);
  printf("%d, %d\n", sumpt.x, sumpt.y);
  printf("%d, %d\n", p1.x, p1.y);

  struct point origin = {0, 0};
  struct point *pp = &origin;
  printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
  printf("origin is (%d, %d)\n", pp->x, pp->y);

  return 0;
}

struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

struct point addpoint(struct point p1, struct point p2) {
  p1.x += p2.x;
  p1.y += p2.y;

  return p1;
}

int ptinrect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

struct rect canonrect(struct rect r) {
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);

  return temp;
}
