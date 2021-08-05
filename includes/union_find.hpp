
#pragma once

/*
Algorithm "Union Find with weighted union"

https://en.wikipedia.org/wiki/Disjoint-set_data_structure

Applications:

1) It is used to determine the connected components in a graph.
We can determine whether 2 nodes are in the same connected component
or not in the graph. We can also determine that by adding an edge
between 2 nodes whether it leads to cycle in the graph or not.

2) It is used to determine the cycles in the graph.

code writter: pianodaemon
mailto: j4nusx@yahoo.com
*/

#include <vector>

class union_find
{
    public:
        union_find( const size_t l );
        virtual ~union_find();
        bool do_find( const int a, const int b );
        void do_union( const int a, const int b );

    protected:
        inline unsigned int seek_root( int i );

        std::vector<int> m_v;
        std::vector<int> m_s;
};
