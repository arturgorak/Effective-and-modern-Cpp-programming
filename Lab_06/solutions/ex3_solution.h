//
// Created by artem on 10.04.2022.
//

#ifndef INC_06_EX3_SOLUTIONS_H
#define INC_06_EX3_SOLUTIONS_H

#endif //INC_06_EX3_SOLUTIONS_H

template<typename... Bases>
class Mixins : public Bases... {
public:
    Mixins(Bases... bases) : Bases(bases)... {}

};
