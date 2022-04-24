
#ifndef LAB6_FILTER_H
#define LAB6_FILTER_H

#include <utility>
#include <iostream>

template<class Container, typename Predicate>
class Filter{
    Container container;
    const Predicate& predicate;

public:
    Filter(Container&& container, const Predicate& predicate) : container(std::forward<Container>(container)), predicate(predicate) {}

    class Iterator;

    using iterator = Iterator;

    class Iterator{
        //decay_t  lvalue to rvalue
        using container_iterator = typename std::decay_t<Container>::iterator;
        Filter& filter;
        container_iterator iterator;
        using cvalue = decltype(*iterator);


    public:
        Iterator(Filter& filter, container_iterator iterator) : filter(filter), iterator(iterator) {
        }

        Iterator& operator++() {
            ++iterator;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp{*this};
            operator++();
            return tmp;
        }

        cvalue& operator*() {
            while (iterator != filter.container.end() && !filter.predicate(*iterator)) {
                operator++();
            }
            return *iterator;
        }

        friend inline bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.iterator == rhs.iterator; }

        friend inline bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !operator==(lhs, rhs); }


    };

    Iterator begin() {
        return Iterator(*this, container.begin());
    }

    Iterator end() {
        return Iterator(*this, container.end());
    }

};

template<class Container, typename Predicate>
auto make_filter(Container&& c, Predicate p) {
    return Filter<Container, Predicate>(std::forward<Container>(c), p);
}


#endif //LAB6_FILTER_H

