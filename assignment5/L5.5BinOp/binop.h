#ifndef L5_5BINOP_BINOP_H
#define L5_5BINOP_BINOP_H

#include <functional>

template<typename BinOp, typename Op1, typename Op2>
class some_function :
        public std::unary_function<typename Op1::argument_type, typename BinOp::result_type> {

protected:

    BinOp o;
    Op1 o1;
    Op2 o2;

public:

    some_function(BinOp binop, Op1 op1, Op2 op2) :
            o(binop),
            o1(op1),
            o2(op2) {}

    typename BinOp::result_type operator ()(const typename Op1::argument_type& x) {
        return o(o1(x), o2(x));
    }

};

#endif //L5_5BINOP_BINOP_H
