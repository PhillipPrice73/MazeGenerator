//
// Created by Nope on 7/8/23.
//

#include "Cell.h"

Cell Cell::getNeighbor(const std::string &neighborLocation) {
    auto it = Cell::m_neighbors->find(neighborLocation);
    return it->second;
}

void Cell::addNeighbor(const std::string& neighborName, const Cell& neighbor) {
    Cell::m_neighbors->insert({neighborName, neighbor});
}