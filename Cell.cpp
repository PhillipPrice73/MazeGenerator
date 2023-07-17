//
// Created by Nope on 7/8/23.
//

#include "Cell.h"
#include <algorithm>

std::optional<Cell> Cell::getNeighbor(const std::string &neighborLocation) 
{
    auto it = m_neighbors->find(neighborLocation);
    return (it == m_neighbors->end() ? std::nullopt : std::optional<Cell>(it->second));
}

void Cell::addNeighbor(const std::string& neighborName, const Cell& neighbor) 
{
    Cell::m_neighbors->insert({neighborName, neighbor});
}

bool Cell::isLinkedNeighbor(const Cell& potentialNeighbor)
{
    auto it = std::find(m_linkedNeighbors.begin(), m_linkedNeighbors.end(), potentialNeighbor);
    return (it != m_linkedNeighbors.end());
    // Should be a way to do this using the any_of function
    //return std::any_of(m_linkedNeighbors.begin(), m_linkedNeighbors.end(), [](){})
}

void Cell::addLinkedNeighbor(Cell& neighbor, bool bidirectional)
{  
    if (!isLinkedNeighbor(neighbor)) 
    {
        m_linkedNeighbors.push_back(neighbor);
        if (bidirectional)
        {
            neighbor.addLinkedNeighbor(*this, false);
        }
    }
}

void Cell::removeLinkedNeighbor(Cell& neighbor, bool bidirectional)
{
    auto it = std::find(m_linkedNeighbors.begin(), m_linkedNeighbors.end(), neighbor);
    if (it != m_linkedNeighbors.end())
    {
        m_linkedNeighbors.erase(it);
        if (bidirectional) 
        {
            neighbor.removeLinkedNeighbor(*this, false);
        }
    }
}