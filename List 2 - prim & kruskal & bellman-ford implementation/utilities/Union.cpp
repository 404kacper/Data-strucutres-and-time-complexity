#include "Union.h"

Union::Union(int size)
{
    container = vector<Node>(size);
}

int &Union::findNode(int &node)
{
    if (container[node].deputy == INT_MAX)
        return node;

    container[node].deputy = findNode(container[node].deputy);
    return container[node].deputy;
}

void Union::unionNodes(int &a, int &b)
{
    auto &aDeputy = findNode(a);
    auto &bDeputy = findNode(b);

    if (container[aDeputy].rank < container[bDeputy].rank)
        container[aDeputy].deputy = bDeputy;
    else if (container[aDeputy].rank > container[bDeputy].rank)
        container[bDeputy].deputy = aDeputy;
    else if (aDeputy != bDeputy) {
        container[bDeputy].deputy = aDeputy;
        container[aDeputy].rank++;
    }
}
