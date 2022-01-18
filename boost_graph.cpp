// custom property test

//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee,
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>
enum family
{
    Jeanie,
    Debbie,
    Rick,
    John,
    Amanda,
    Margaret,
    Benjamin,
    N
};

using namespace boost;

struct first_name_t {
    typedef vertex_property_tag kind;
};

int main()
{
    using namespace boost;
    const char* name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda",
        "Margaret", "Benjamin" };

    // adjacency_list<listS, vecS, bidirectionalS,
    //                    property<vertex_index_t, int> > g(N);


    typedef adjacency_list<vecS, vecS, directedS, 
    property<first_name_t, int> , no_property, no_property, listS> gr;

    adjacency_list<vecS, vecS, directedS, 
    property<first_name_t, int> , no_property, no_property, listS> g(N);
    add_edge(Jeanie, Debbie, g);
    add_edge(Jeanie, Rick, g);
    add_edge(Jeanie, John, g);
    add_edge(Debbie, Amanda, g);
    add_edge(Rick, Margaret, g);
    add_edge(John, Benjamin, g);

    graph_traits< adjacency_list<> >::vertex_iterator i, end;
    // property_map< adjacency_list<>, vertex_index_t >::type index_map
    //     = get(vertex_index, g);

    property_map<gr, first_name_t>::type first_name = get(first_name_t(), g);

    typedef boost::graph_traits<gr>::vertex_descriptor MyVertex;

    int ind = 0;

    for (boost::tie(i, end) = vertices(g); i != end; ++i, ++ind)
    {
        MyVertex v = vertex(*i, g);
        put(first_name, v, ind);
        std::cout << vertex(*i, g) << ' ' << get(first_name, v);
        std::cout << std::endl;
    }

    remove_vertex(0, g);

    first_name = get(first_name_t(), g);

    std::cout << std::endl;

    for (boost::tie(i, end) = vertices(g); i != end; ++i, ++ind)
    {
        MyVertex v = vertex(*i, g);
        std::cout << vertex(*i, g) << ' ' << get(first_name, v);
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
