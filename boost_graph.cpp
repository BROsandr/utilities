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

using namespace boost;

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

struct first_name_t {
    typedef vertex_property_tag kind;
};

int main()
{
    const char* name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda",
        "Margaret", "Benjamin" };

    // adjacency_list<listS, vecS, bidirectionalS,
    //                    property<vertex_index_t, int> > g(N);


    typedef adjacency_list<vecS, vecS, directedS, 
    property<first_name_t, int> , no_property, no_property, listS> Graph;

    Graph g(N);
    add_edge(Jeanie, Debbie, g);
    add_edge(Jeanie, Rick, g);
    add_edge(Jeanie, John, g);
    add_edge(Debbie, Amanda, g);
    add_edge(Rick, Margaret, g);
    add_edge(John, Benjamin, g);

    graph_traits< adjacency_list<> >::vertex_iterator i, end;
    // property_map< adjacency_list<>, vertex_index_t >::type index_map
    //     = get(vertex_index, g);

    property_map<Graph, first_name_t>::type first_name = get(first_name_t(), g);

    typedef boost::graph_traits<Graph>::vertex_descriptor MyVertex;

    int ind = 0;

    for (auto[i, end] = vertices(g); i != end; ++i, ++ind)
    {
        MyVertex v = vertex(*i, g);
        put(first_name, v, ind);
        std::cout << vertex(*i, g) << ' ' << get(first_name, v);
        std::cout << std::endl;
    }

    remove_vertex(0, g);

    std::cout << std::endl;

    for (auto[i, end] = vertices(g); i != end; ++i)
    {
        MyVertex v = vertex(*i, g);
        std::cout << vertex(*i, g) << ' ' << get(first_name, v);
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
