//
// Created by timo on 14.11.18.
//

#ifndef L4_2COUNTINGITERATOR_COUNTING_ITERATOR_H
#define L4_2COUNTINGITERATOR_COUNTING_ITERATOR_H

#include <algorithm>

template<typename T>
class counting_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

    T t;

public:

    explicit counting_iterator(T t = 0) : t(t) { }

    // prefix operator++
    const counting_iterator& operator++() {

        ++t;
        return *this;

    }


    // postfix operator++
    const counting_iterator operator++(int) {

        counting_iterator temp = *this;

        // calling the above prefix operator++
        ++(*this);
        return temp;

    }


    // prefix operator--
    const counting_iterator& operator--() {

        --t;
        return *this;

    }


    // postfix operator--
    const counting_iterator operator--(int) {

        counting_iterator temp = *this;

        // calling the above prefix operator--
        --(*this);
        return temp;

    }


    const bool operator==(counting_iterator second) {

        return t == second.t;

    }


    const bool operator!=(counting_iterator second) {

        return !(t == second.t);

    }


    const T operator *() {

        return t;

    }

};



template<typename T>
counting_iterator<T> counter(const T& t) {

    return counting_iterator<T>(t);

}


#endif //L4_2COUNTINGITERATOR_COUNTING_ITERATOR_H
