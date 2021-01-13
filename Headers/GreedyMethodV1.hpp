#pragma once
#include <vector>
#include "ComputersForEach.hpp"
#include "GeneratorTest.hpp"
class GreedyMethodV1
{
private:
    struct group
    {
    public:
        int capacity;
        int id;
        group(int capacity, int id) : capacity(capacity), id(id){};
    };

    struct room
    {
    public:
        int capacity;
        int id;
        room(int capacity, int id) : capacity(capacity), id(id){};
    };

public:
    GreedyMethodV1(/* args */);
    GreedyMethodV1(int, int, int*, int*);
    GreedyMethodV1(GeneratorTest*);
    ~GreedyMethodV1();
    int solve(std::vector<int> &);
};

