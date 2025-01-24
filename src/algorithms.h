

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "structs/Graph.h"
#include "sequences/ArraySequence.h"
#include <queue>
#include "structs/HashTable.h"

template <class T>
ArraySequence<size_t> BFS(const OrientedGraph<T>& Graph, size_t startId) {
    ArraySequence<size_t> result;
    std::queue<size_t> q;
    HashTable<size_t, bool> visited;

    q.push(startId);
    visited.Insert(startId, true);
    result.Append(startId);

    while (!q.empty()) {
        size_t currentVertex = q.front();
        q.pop();

        ArraySequence<Edge> neighbors = Graph.GetNeighbours(currentVertex);

        for (size_t i = 0; i < neighbors.GetLength(); i++) {
            size_t nextVertex = neighbors.Get(i).to;

            if (!visited.Find(nextVertex)) {
                q.push(nextVertex);
                visited.Insert(nextVertex, true);
                result.Append(nextVertex);
            }
        }
    }

    return result;
}

template <class T>
void DFSUtil(const OrientedGraph<T>& Graph, size_t currentVertex,
             HashTable<size_t, bool>& visited, ArraySequence<size_t>& result) {
    visited.Insert(currentVertex, true);
    result.Append(currentVertex);

    ArraySequence<Edge> neighbors = Graph.GetNeighbours(currentVertex);
    for (size_t i = 0; i < neighbors.GetLength(); i++) {
        size_t nextVertex = neighbors.Get(i).to;
        if (!visited.Find(nextVertex)) {
            DFSUtil(Graph, nextVertex, visited, result);
        }
    }
}

template <class T>
ArraySequence<size_t> DFS(const OrientedGraph<T>& Graph, size_t startId) {
    ArraySequence<size_t> result;
    HashTable<size_t, bool> visited;

    DFSUtil(Graph, startId, visited, result);

    return result;
}
#endif //ALGORITHMS_H
