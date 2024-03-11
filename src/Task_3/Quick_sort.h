#include <vector>


template <typename Iterator>
void quicksort(Iterator begin, Iterator end) {
    if (begin < end) {
        auto pivot = *std::next(begin, std::distance(begin, end) / 2);
        Iterator mid1 = std::partition(begin, end,
                                       [pivot](auto em){ return em < pivot; });
        Iterator mid2 = std::partition(begin, end,
                                       [pivot](auto em){ return em <= pivot ; });

        quicksort(begin, mid1);
        quicksort(mid2, end);
    }
}

template <typename T>
void sort(std::vector<T>& vec) {
    quicksort(vec.begin(), vec.end());
}