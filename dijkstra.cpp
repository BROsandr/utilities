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
#include <boost/graph/dijkstra_shortest_paths.hpp>

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
    int jg;
};

int main()
{
    typedef std::pair< int, int > Edge;
    const char* name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda",
        "Margaret", "Benjamin" };

    // adjacency_list<listS, vecS, bidirectionalS,
    //                    property<vertex_index_t, int> > g(N);


    typedef adjacency_list<vecS, vecS, directedS, 
    first_name_t, property< edge_weight_t, int > > Graph;

    std::pair< int, int > edge_array[] = { Edge(Jeanie, Debbie), Edge(Jeanie, Rick), Edge(Jeanie, John), Edge(Debbie, Amanda), Edge(Rick, Margaret), Edge(John, Benjamin) };
    const int num_nodes = N;
    int weights[] = { 1, 1, 1, 1, 1, 1, 1 };
    int num_arcs = 6;

    Graph g1();
    Graph g(edge_array, edge_array + num_arcs, weights, num_nodes);
    property_map< Graph, edge_weight_t >::type weightmap = get(edge_weight, g);

    std::vector< graph_traits< Graph >::vertex_descriptor > p(num_vertices(g));
    std::vector< int > d(num_vertices(g));
    graph_traits< Graph >::vertex_descriptor s = vertex(Jeanie, g);

    dijkstra_shortest_paths(g, s,
        predecessor_map(boost::make_iterator_property_map(
                            p.begin(), get(boost::vertex_index, g)))
            .distance_map(boost::make_iterator_property_map(
                d.begin(), get(boost::vertex_index, g))));

    std::cout << "distances and parents:" << std::endl;
    graph_traits< Graph >::vertex_iterator vi, vend;
    for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi)
    {
        std::cout << "distance(" << name[*vi] << ") = " << d[*vi] << ", ";
        std::cout << "parent(" << name[*vi] << ") = " << name[p[*vi]]
                  << std::endl;
    }


    return EXIT_SUCCESS;
}
