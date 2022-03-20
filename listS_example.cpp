//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee,
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>

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

struct name_t {
    family name;
};

int main()
{
    const char* name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda",
        "Margaret", "Benjamin" };

    // adjacency_list<listS, vecS, bidirectionalS,
    //                    property<vertex_index_t, int> > g(N);


    typedef adjacency_list<listS, listS, directedS, name_t > Graph;

    Graph g(N);

    Graph::vertex_descriptor jeanie = add_vertex(g);
    g[jeanie].name = Jeanie;
    Graph::vertex_descriptor debbie = add_vertex(g);
    g[debbie].name = Debbie;
    Graph::vertex_descriptor rick = add_vertex(g);
    g[rick].name = Rick;
    Graph::vertex_descriptor john = add_vertex(g);
    g[john].name = John;
    Graph::vertex_descriptor amanda = add_vertex(g);
    g[amanda].name = Amanda;
    Graph::vertex_descriptor margaret = add_vertex(g);
    g[margaret].name = Margaret;
    Graph::vertex_descriptor benjamin = add_vertex(g);
    g[benjamin].name = Benjamin;
    
    add_edge(jeanie, debbie, g);
    add_edge(jeanie, rick, g);
    add_edge(jeanie, john, g);
    add_edge(debbie, amanda, g);
    add_edge(rick, margaret, g);
    add_edge(john, benjamin, g);

    graph_traits< Graph >::vertex_iterator i, end;
    // // property_map< adjacency_list<>, vertex_index_t >::type index_map
    // //     = get(vertex_index, g);

    // property_map<Graph, first_name_t>::type first_name = get(first_name_t, g);

    typedef boost::graph_traits<Graph>::vertex_descriptor MyVertex;

    int ind = 0;

    for (auto[i, end] = vertices(g); i != end; ++i, ++ind)
    {
        std::cout << *i << " ";
    }

    // remove_vertex(0, g);

    // std::cout << std::endl;

    // for (auto[i, end] = vertices(g); i != end; ++i)
    // {
    //     MyVertex v = vertex(*i, g);
    //     std::cout << *i << ' ' << vertex(*i, g) << ' ' << g[v].jg;
    //     std::cout << std::endl;
    // }

    return EXIT_SUCCESS;
}
