#include <iostream>

using namespace std;

void imprimirArr(int *, int);

int main()
{
  int n = 10;
  int arr[n];
  int *p = arr;

  for (int *z=arr; z<(arr+n); z++) {
    *z = rand()%100;
  }
  cout << "Array generada:\n";
  imprimirArr(arr, n);

  for(int *item = arr; item < (arr+n); item++)
  {
    int currentindex = item-arr;
    int pos = currentindex;

    cout << "Ciclo: " << currentindex << " Item: " << *item << endl;
    imprimirArr(arr, n);

    for(int *i = (arr+currentindex+1); i < (arr+n); i++)
    {
      if(*i < *item) pos++;
    }

    if(pos == currentindex) continue;

    while (*item == *(arr+pos)) {
      pos++;
    }

    p = arr;
    p = p + pos;
    swap(*item, *p);

    while (pos != currentindex) {
      pos = currentindex;

      for (int *k = (arr+currentindex+1); k < (arr+n); k++)
      {
        if (*k < *item) pos++;
      }

      if(pos == currentindex) continue;

      while (*item == *(arr+pos)) {
        pos = pos + 1;
      }

      p = arr;
      p += pos;
      swap(*p, *item);
    }
  }
}

void imprimirArr(int *a, int n)
{
  for(int *i= a; i < (a+n); i++)
  {
    cout << *i << " ";
  }
  cout << endl;
}
