//
// Created by artem on 12.06.22.
//

#ifndef INC_13_EX3_H
#define INC_13_EX3_H

template<int...>
class IntegerList {
};

template<int head, int... tail>
class IntegerList<head, tail...> {
public:
    friend std::ostream &operator<<(std::ostream &os, const IntegerList list) {
        IntegerList<tail...> integerList;
        return os << head << " " << integerList;
    }

    static constexpr int get(int index) {
        if (index == 0) {
            return head;
        } else {
            return IntegerList<tail...>::get(index - 1);
        }
    }

    static constexpr bool isSorted(int prev) {
        if (prev > head) {
            return false;
        } else {
            return IntegerList<tail...>::isSorted(head);
        }
    }

    static constexpr int max() {
        int max_tail = IntegerList<tail...>::max();

        if (max_tail > head) {
            return max_tail;
        } else {
            return head;
        }
    }

};

template<int head>
class IntegerList<head> {
public:
    friend std::ostream &operator<<(std::ostream &os, const IntegerList list) {
        return os << head;
    }

    static constexpr int get(int index) {
        if (index == 0) {
            return head;
        } else {
            return INT16_MIN;
        }
    }

    static constexpr int max() {
        return head;
    }

    static constexpr bool isSorted(int prev) {
        if (prev > head) {
            return false;
        } else {
            return true;
        }
    }

};

template<typename first, typename second>
class Join {
public:
    typedef IntegerList<> type;
};

template<int... x, int... y>
class Join<IntegerList<x...>, IntegerList<y...>> {
public:
    typedef IntegerList<x..., y...> type;
};


template<int index, typename IntegerList>
class getInt {
public:
    static constexpr int value = IntegerList::get(index);
};


template<typename IntegerList>
class IsSorted {
public:
    static constexpr bool value = IntegerList::isSorted(INT16_MIN);
};


template<typename IntegerList>
class Max {
public:
    static constexpr int value = IntegerList::max();
};


#endif //INC_13_EX3_H
