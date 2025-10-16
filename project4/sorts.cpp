#include "sorts.h"
#include <algorithm>
#include <vector>

void insertionSortItems(std::vector<ItemHandle>& a, bool ascending) {
    for (size_t i = 1; i < a.size(); ++i) {
        ItemHandle key = a[i];
        long long j = i - 1;

        if (ascending) {
            while (j >= 0 && (key < a[j])) {
                a[j + 1] = a[j];
                j--;
            }
        } else {
            while (j >= 0 && (a[j] < key)) {
                a[j + 1] = a[j];
                j--;
            }
        }
        a[j + 1] = key;
    }
}

void merge(std::vector<ItemHandle>& a, size_t left, size_t mid, size_t right, bool ascending) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    std::vector<ItemHandle> L(a.begin() + left, a.begin() + left + n1);
    std::vector<ItemHandle> R(a.begin() + mid + 1, a.begin() + mid + 1 + n2);

    size_t i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        bool take_from_L = ascending ? !(R[j] < L[i]) : !(L[i] < R[j]);
        if (take_from_L) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortRec(std::vector<ItemHandle>& a, size_t left, size_t right, bool ascending) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSortRec(a, left, mid, ascending);
        mergeSortRec(a, mid + 1, right, ascending);
        merge(a, left, mid, right, ascending);
    }
}

void mergeSortItems(std::vector<ItemHandle>& a, bool ascending) {
    if (a.size() > 1) {
        mergeSortRec(a, 0, a.size() - 1, ascending);
    }
}

void sortItems(std::vector<ItemHandle>& a, SortAlgo algo, bool ascending) {
    switch (algo) {
        case SortAlgo::Insertion: insertionSortItems(a, ascending); break;
        case SortAlgo::Merge:     mergeSortItems(a,     ascending); break;
    }
}
