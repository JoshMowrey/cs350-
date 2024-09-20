#include <stdio.h> 
#include <stdlib.h>

struct LinkedList {
    int value;
    struct LinkedList* p, * n;
};

void PrintList(struct LinkedList* a)
{ 
    do {
        printf("%d, ", a->value);
        a = a->n;
    } while (a->n != NULL);
    printf("%d\n", a->value);
}
    /* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(int* array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void insert(int value, int pos, struct LinkedList* a) {
    for (int i = 0; i < pos; i++) {
        if (a->n == NULL) {
            struct LinkedList* temp = a->n;
            a->n = (struct LinkedList*) malloc(sizeof(struct LinkedList));
            a->n->p = a;
            a->n->n = temp;
        }
        a = a->n;
    }
    if (a->value != NULL) {
        struct LinkedList* temp = a->n;
        a->n = (struct LinkedList*)malloc(sizeof(struct LinkedList));
        a->n->value = a->value;
        a->n->n = temp;
    }
    a->value = value;

}

void swap(int* one, int* two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}

int is_Sorted(struct LinkedList* a, int length) {
    int last = a->value;
    for (int i = 1; i < length; i++) {
        a = a->n;
        if (last > a->value) {
            return -1;
        }
        last = a->value;
    }
    return 1;
}

int main() {
    int arr[5] = { 3, 4, 5, 1, 2 };
    for (int i = 0; i < 1000; i++) {
        shuffle(arr, 5);
        if (arr[0] > arr[1]) //Compare 1
            swap(arr, arr + 1);
        if (arr[3] > arr[4]) //Compare 2
            swap(arr + 3, arr + 4);
        int n1 = arr[0], n2 = arr[1], n3 = arr[2], n4 = arr[3], n5 = arr[4];

        struct LinkedList list;
        list.n = NULL;
        if (n1 > n4) { //compare 3
            swap(&n1, &n4);
            swap(&n2, &n5);
            
        }
        insert(n1, 0, &list);
        insert(n4, 1, &list);
        insert(n5, 2, &list);
        if (n4 < n3) { //compare 4
            if (n5 < n3) { // compare 5
                insert(n3, 3, &list);
                if (n5 < n2) { // compare 6
                    if (n3 < n2) //compare 7
                        insert(n2, 4, &list);
                    else
                        insert(n2, 3, &list);
                }
                else { 
                    if (n4 < n2) //comare 7
                        insert(n2, 2, &list);
                    else
                        insert(n2, 1, &list);
                }
            }
            else {
                insert(n3, 2, &list);
                if (n3 < n2) { // compare 6
                    if (n5 < n2) //compare 7
                        insert(n2, 4, &list);
                    else
                        insert(n2, 3, &list);
                }
                else {
                    if (n4 < n2) //comare 7
                        insert(n2, 2, &list);
                    else
                        insert(n2, 1, &list);
                }
            }
        }
        else {
            if (n1 < n3) { //compare 5
                insert(n3, 1, &list);
                if (n4 < n2) { //compare 6
                    if (n5 < n2) //compare 7
                        insert(n2, 4, &list);
                    else
                        insert(n2, 3, &list);
                }
                else {
                    if (n3 < n2) //compare 7
                        insert(n2, 2, &list);
                    else
                        insert(n2, 1, &list);
                }
            }
            else {
                insert(n3, 0, &list);
                if (n4 < n2) { //compare 6
                    if (n5 < n2) //compare 7
                        insert(n2, 4, &list);
                    else
                        insert(n2, 3, &list);
                }
                else
                    insert(n2, 2, &list);
            }
        }
        PrintList(&list);
        if (is_Sorted(&list, 5) == -1) {
            printf("dun fucked up");
        }
        
    }



    return 1;
}