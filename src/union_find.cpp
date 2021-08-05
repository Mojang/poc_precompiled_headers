#include "union_find.hpp"

#define __INITIAL_SUBSET_SIZE 1

union_find::union_find( const size_t l ) : m_v(l), m_s(l, __INITIAL_SUBSET_SIZE)
{
    /* Initially there are N subsets containing
       single element in each subset. The initial
       size of each subset will be one */
    unsigned int c = 0;
    for ( int& i : this->m_v ) i = c++;
}

union_find::~union_find() { }

unsigned int
union_find::seek_root( int i )
{
    /* The 'root element' of each subset,
       which is a only special element in
       that subset having itself as the parent. */

    while( this->m_v[i] != i )
    {
       /* during the quest, an interesting optimization
          takes place "path compression" by setting
          each i to point to its grandparent */
       this->m_v[i] = this->m_v[ this->m_v[i] ];

       i = this->m_v[i];
    }
    return i;
}

bool
union_find::do_find( const int a, const int b )
{
    /* if 'a' and 'b' have same root,
       means they are connected. */
    return ( this->seek_root( a ) == this->seek_root( b ) ) ? true : false;
}

void
union_find::do_union( const int a, const int b )
{
    auto weighted = [&]( const int& root_l, const int& root_r )
    {
        this->m_v[root_l] = this->m_v[root_r];
        this->m_s[root_r] += this->m_s[root_l];
    };

    auto root_a = this->seek_root( a );
    auto root_b = this->seek_root( b );

    /* connectting two subsets according to the number
       of elements in subset ("balance by linking root
       of smaller subset to the root of larger subset").
       Such strategy allows us to avoid tall subsets */
    if ( this->m_s[root_a] < this->m_s[root_b] ) weighted( root_a, root_b );
    else weighted( root_b, root_a );
}