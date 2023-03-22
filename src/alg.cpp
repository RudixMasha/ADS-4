// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int schet = 0;
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        if (arr[i] + arr[j] == value) {
          schet++;
        }
      }
    }
  return schet;
}
int countPairs2(int *arr, int len, int value) {
  int schet = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        schet++;
      }
    }
  }
  return schet;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int righ = len;
    int lef = i;
    while (lef < righ - 1) {
      int mid = (lef + righ) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int midd = mid + 1;
        while (arr[i] + arr[midd] == value && midd < righ) {
          count++;
          midd++;
        }
        midd = mid - 1;
        while (arr[i] + arr[midd] == value && midd > lef) {
          count++;
          midd--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        righ = mid;
      } else {
        lef = mid;
      }
    }
  }
  return count;
}
