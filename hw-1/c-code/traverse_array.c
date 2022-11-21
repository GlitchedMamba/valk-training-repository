#include <stdio.h>
#include <stddef.h>

int main () {

  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  int l, r;
  scanf("%d %d", &l, &r);

  //printf("%u %d", i, l);
  for (int i = r; i >= l; --i) {
    printf("%d ", arr[i]);
  }

  return 0;
}
