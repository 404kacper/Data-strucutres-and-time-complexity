#pragma once

struct Edge {
public:
    Edge(int fromV, int toV, int weight) {
      from = fromV;
      to = toV;
      this->weight = weight;
    }

    int from, to;
    int weight;

    // Do tworzenia kopca minimalnego
    bool operator < (Edge& comparedEdge) {
        return this->weight > comparedEdge.weight;
    }
};