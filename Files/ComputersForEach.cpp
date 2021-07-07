#include "ComputersForEach.hpp"

ComputersForEach::ComputersForEach(AlgorithmStrategy *strategy) : _strategy(strategy)
{
    this->_strategy = strategy;
}

ComputersForEach::~ComputersForEach()
{
    delete this->_strategy;
}

void ComputersForEach::setStrategy(AlgorithmStrategy *strategy)
{
    delete this->_strategy;
    this->_strategy = strategy;
}

int ComputersForEach::getCountOfGroups_N()
{
    return this->_strategy->getCountOfGroups_N();
}

void ComputersForEach::setCountOfGroups_N(int newGroups)
{
    _strategy->setCountOfGroups_N(newGroups);
}

int ComputersForEach::getCountOfAudiences_M()
{
    return _strategy->getCountOfAudiences_M();
}

void ComputersForEach::setCountOfAudiences_M(int newAudiences)
{
    _strategy->setCountOfAudiences_M(newAudiences);
}

int ComputersForEach::DoSolve(std::vector<int> &roster) const
{
    return this->_strategy->solve(roster);
}