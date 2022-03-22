#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/dijkstra.h>
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

    //arcs are necessary to use
    ListGraph::ArcMap<int> lengthMap(g);
    for (ListGraph::ArcIt it(g); it != INVALID; ++it)
        lengthMap[it] = 1;

    ListGraph::NodeMap<int> distMapo(g);
    ListGraph::NodeMap<ListGraph::Arc> predMapo(g);
    Dijkstra<ListGraph> dijkstra(g, lengthMap);
    dijkstra.distMap(distMapo);
    dijkstra.predMap(predMapo);
    dijkstra.init();
    dijkstra.addSource(jeanie);
    dijkstra.start();

    std::cout << families[g.source(predMapo[debbie])];

    return 0;
}
