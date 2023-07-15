//
// Created by Nope on 7/8/23.
//

#include "Cell.h"
#include <algorithm>

Cell Cell::getNeighbor(const std::string &neighborLocation) {
    auto it = Cell::m_neighbors->find(neighborLocation);
    return it->second;
}

void Cell::addNeighbor(const std::string& neighborName, const Cell& neighbor) {
    Cell::m_neighbors->insert({neighborName, neighbor});
}

bool Cell::isLinkedNeighbor(const Cell& potentialNeighbor)
{
    auto it = Cell::m_linkedNeighbors->find(potentialNeighbor);
    return (it != m_linkedNeighbors->end());
}

void Cell::addLinkedNeighbor(Cell& neighbor, bool bidirectional)
{
    m_linkedNeighbors->insert(neighbor);
    if (bidirectional) {
        neighbor.addLinkedNeighbor(*this, false);
    }
}

void Cell::removeLinkedNeighbor(Cell& neighbor, bool bidirectional)
{
    m_linkedNeighbors->erase(neighbor);
    if (bidirectional) {
        neighbor.removeLinkedNeighbor(*this, false);
    }
}