#include <iostream>
using namespace std;

class priorityqueue
{
  int arr[100];
  int size;

public:
  priorityqueue()
  {
    size = 0;
  }

  void insert(int val)
  {
    size++;
    int i = size;
    arr[size] = val;

    while (i > 1)
    {
      if (arr[i] > arr[i / 2])  // for min heap reverse this condition
      {
        swap(arr[i], arr[i / 2]);
        i = i / 2;
      }
      else
      {
        break;
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////



  void removeMax()   // delete highest priority element
  
  {
    if(size == 0){
        cout << "Queue is empty\n";
        return;
    }

    //  Replace root with last element
    arr[1] = arr[size];
    size--;

    int i = 1;

    //  Heapify DOWN
    while(i <= size)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int largest = i;

        // compare parent with left child
        if(left <= size && arr[left] > arr[largest])
            largest = left;

        // compare with right child
        if(right <= size && arr[right] > arr[largest])
            largest = right;

        // if parent already largest → stop
        if(largest == i)
            break;

        // otherwise swap
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

  void display()
  {
    for (int i = 1; i <= size; i++)
      cout << arr[i] << " ";

    cout << endl;
  }
};
int main()
{
  // for max heap

  priorityqueue pq;

  pq.insert(40);
  pq.insert(43);
  pq.insert(10);
  pq.insert(56);

  pq.display();
  pq.removeMax();
  return 0;
}