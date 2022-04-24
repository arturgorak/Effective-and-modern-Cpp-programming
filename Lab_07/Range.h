

#ifndef LAB6_RANGE_H
#define LAB6_RANGE_H

template <typename T>
class Range{
     T start;
     T stop;
     T step;
public:
    Range(T start, T stop, T step = 1) : start(start), stop(stop), step(step) {}

    explicit Range(T stop) : Range(0, stop, 1) {}

    class Iterator{
        T index;
        const Range& range;
    public:
        explicit Iterator(const Range& range, T index = 0) : index(index), range(range) {}


        Iterator& operator++() {
            index = std::min(index + range.step, range.stop);
            return *this; }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp; }

        T operator*() {
            return index;
        }

        friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.index == b.index;
        };

        friend bool operator!= (const Iterator& a, const Iterator& b) {
            return a.index != b.index;
        };


    };

    Iterator begin() {
        return Iterator(*this, start);
    }
    Iterator end()   {
        return Iterator(*this, stop);
    }




};

template<typename T>
Range<T> make_range(T&& stop) {
    return Range<T>(0, std::forward<T>(stop), 1);
}

template<typename T>
Range<T> make_range(T&& start, T&& stop, T&& step = 1) {
    return Range<T>(std::forward<T>(start), std::forward<T>(stop), std::forward<T>(step));
}

#endif //LAB6_RANGE_H
