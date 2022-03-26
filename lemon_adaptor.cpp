#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/dijkstra.h>
#include <lemon/adaptors.h>
using namespace lemon;
using namespace std;

enum family {
    Jeanie,
    Debbie,
    Rick,
    John,
    Amanda,
    Margaret,
    Benjamin,
    N
};

int main() {
    ListGraph g;
    for (int i = 0; i < N; i++)
        g.addNode();
    ListGraph::NodeMap<family> families(g);
    ListGraph::NodeIt it(g);
    families[it] = Jeanie;
    ListGraph::NodeIt jeanie = it;
    ++it;
    families[it] = Debbie;
    ListGraph::NodeIt debbie = it;
    ++it;
    g.addEdge(jeanie, debbie);
    families[it] = Amanda;
    ListGraph::NodeIt amanda = it;
    ++it;
    g.addEdge(debbie, amanda);
    families[it] = Rick;
    ListGraph::NodeIt rick = it;
    ++it;
    g.addEdge(jeanie, rick);
    families[it] = Margaret;
    ListGraph::NodeIt margaret = it;
    ++it;
    g.addEdge(margaret, rick);
    families[it] = John;
    ListGraph::NodeIt john = it;
    ++it;
    g.addEdge(jeanie, john);
    families[it] = Benjamin;
    ListGraph::NodeIt benjamin = it;
    g.addEdge(benjamin, john);
    g.addEdge(debbie, rick);
    g.addEdge(rick, john);

    //arcs are necessary to use
    ListGraph::ArcMap<int> lengthMap(g);
    for (ListGraph::ArcIt it(g); it != INVALID; ++it)
        lengthMap[it] = 1;

    ListGraph::NodeMap<int> distMapo(g);
    ListGraph::NodeMap<ListGraph::Arc> predMapo(g);

    ListGraph::NodeMap<bool> nodeFilter(g, true);
    FilterNodes<ListGraph> filtered(g, nodeFilter);
    nodeFilter[rick] = false;

    using dijkstra_t = Dijkstra<FilterNodes<ListGraph>, ListGraph::ArcMap<int>>;
    dijkstra_t d(filtered, lengthMap);
    d.init();
    d.addSource(debbie);
    d.start();

    dijkstra_t::Path p = d.path(john);

    for (dijkstra_t::Path::RevArcIt it(p); it != INVALID; ++it)
        std::cout << families[g.source(it)];

    return 0;
}
