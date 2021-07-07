#include "AlgorithmStrategy.hpp"

int AlgorithmStrategy::getCountOfAudiences_M()
{
    return (this->_countOfAudiences_M);
}

int AlgorithmStrategy::getCountOfGroups_N()
{
    return (this->_countOfGroups_N);
}

void AlgorithmStrategy::setCountOfAudiences_M(int newCountOfAudiences)
{
    this->_countOfAudiences_M = newCountOfAudiences;
}

void AlgorithmStrategy::setCountOfGroups_N(int newCountOfGroups)
{
    this->_countOfGroups_N = newCountOfGroups;
}
