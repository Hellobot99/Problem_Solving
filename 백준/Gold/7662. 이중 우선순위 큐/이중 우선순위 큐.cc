#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef struct {
    int* array;
    int count; // 힙 안의 항목 개수
    int capacity; // 힙의 용량
    int heap_type; //힙의 종류
} Heap;

Heap* CreateHeap(int capacity, int heap_type) {
    Heap* h = (Heap*)malloc(sizeof(Heap));

    h->heap_type = heap_type; //heap type 이 0 = max  1 = min
    h->count = 0;
    h->capacity = capacity;
    h->array = (int*)malloc(sizeof(int) * h->capacity);

    return h;
}

int Parent(Heap* h, int i) {
    if (i <= 0 || i >= h->count)
        return -1;
    return (i - 1) / 2;
}

int LeftChild(Heap* h, int i) {
    int left = 2 * i + 1;
    if (left >= h->count)
        return -1;
    return left;
}

int RightChild(Heap* h, int i) {
    int right = 2 * i + 2;
    if (right >= h->count)
        return -1;
    return right;
}

int Search(Heap* h, int a) {
    for (int i = h->count - 1; i >= 0; i--) {
        if (a == h->array[i]) return i;
    }
    return -1;
}

void MaxPercolateDown(Heap* h, int i) {
    int l, r, max, temp;
    l = LeftChild(h, i);
    r = RightChild(h, i);
    if (l != -1 && h->array[l] > h->array[i]) max = l;
    else max = i;
    if (r != -1 && h->array[r] > h->array[max]) max = r;
    if (max != i) {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
        MaxPercolateDown(h, max);
    }
}

void MaxPercolateUp(Heap* h, int i) {
    int temp;
    int parent = Parent(h, i);

    while (i > 0 && h->array[parent] < h->array[i]) {
        temp = h->array[i];
        h->array[i] = h->array[parent];
        h->array[parent] = temp;
        i = parent;
        parent = Parent(h, i);
    }
}

void MinPercolateDown(Heap* h, int i) {
    int l, r, max, temp;
    l = LeftChild(h, i);
    r = RightChild(h, i);
    if (l != -1 && h->array[l] < h->array[i]) max = l;
    else max = i;
    if (r != -1 && h->array[r] < h->array[max]) max = r;
    if (max != i) {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
        MinPercolateDown(h, max);
    }
}

void MinPercolateUp(Heap* h, int i) {
    int temp;
    int parent = Parent(h, i);

    while (i > 0 && h->array[parent] > h->array[i]) {
        temp = h->array[i];
        h->array[i] = h->array[parent];
        h->array[parent] = temp;
        i = parent;
        parent = Parent(h, i);
    }
}

void Insert_Max_Heap(Heap* h, int data) {
    if (h->count == h->capacity) {
        printf("Heap is full\n");
        return;
    }
    h->count++;
    int i = h->count - 1;
    h->array[i] = data;

    MaxPercolateUp(h, i);
}

int Delete_Max_Heap(Heap* h) {
    int data;
    if (h->count == 0) return-1;
    data = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->count--;
    MaxPercolateDown(h, 0);
    return data;
}

void Insert_Min_Heap(Heap* h, int data) {
    if (h->count == h->capacity) {
        printf("Heap is full\n");
        return;
    }
    h->count++;
    int i = h->count - 1;
    h->array[i] = data;

    MinPercolateUp(h, i);
}

int Delete_Min_Heap(Heap* h) {
    int data;
    if (h->count == 0) return-1;
    data = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->count--;
    MinPercolateDown(h, 0);
    return data;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 

	int T, K;

	cin >> T;
	for (int z = 0; z < T; z++) {

        Heap* Max_heap = CreateHeap(1000001, 0);
        Heap* Min_heap = CreateHeap(1000001, 1);        

        map<int, int> map;

		cin >> K;
		for (int y = 0; y < K; y++) {        
            
			char a;
			int b;
			cin >> a >> b;
			if (a == 'I') {
                Insert_Max_Heap(Max_heap, b);
                Insert_Min_Heap(Min_heap, b);
                map[b]++;
			}
			else {
                if (Max_heap->count == 0) {
                    continue;
                }
                else if (b == 1) {                
                    while (Max_heap->count != 0) {
                        int m = Max_heap->array[0];
                        if (map[m] > 0) {
                            Delete_Max_Heap(Max_heap);
                            map[m]--;
                            break;
                        }
                        else 
                            Delete_Max_Heap(Max_heap);
                    }                                     
				}
				else {                    
                    while (Min_heap->count != 0) {
                        int m = Min_heap->array[0];
                        if (map[m] > 0) {
                            Delete_Min_Heap(Min_heap);
                            map[m]--;
                            break;
                        }
                        else
                            Delete_Min_Heap(Min_heap);
                    }
				}
			}
		}

        while (Max_heap->count != 0 && map[Max_heap->array[0]] == 0) Delete_Max_Heap(Max_heap);
        while (Max_heap->count != 0 && map[Min_heap->array[0]] == 0) Delete_Min_Heap(Min_heap);

		if (Max_heap->count == 0)
			cout << "EMPTY" << endl;
		else if (Max_heap->count == 1)
			cout << Max_heap->array[0] << " " << Max_heap->array[0] << endl;
		else
			cout << Max_heap->array[0] << " " << Min_heap->array[0] << endl;

        free(Min_heap);
        free(Max_heap);
    }    

	return 0;
}