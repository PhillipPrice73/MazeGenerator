//
// Created by Nope on 7/8/23.
// Cell object for mazes
//

#ifndef CELL_H
#define CELL_H

#include <cstdlib>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <string>

class Cell {
public:
    Cell(std::size_t row, std::size_t column) {
        m_row = row;
        m_column = column;
    };
    virtual ~Cell() = default;

    Cell getNeighbor(const std::string& neighborLocation);
    void addNeighbor(const std::string& neighborName, const Cell& neighbor);
    bool isLinkedNeighbor(const Cell& potentialNeighbor);
    void addLinkedNeighbor(Cell& neighbor, bool bidirectional = true);
    void removeLinkedNeighbor(Cell& neighbor, bool bidirectional = true);
    
protected:

private:
    std::uint64_t m_row{0};
    std::uint64_t m_column{0};

    std::unordered_map<std::string, Cell>* m_neighbors{nullptr};
    std::unordered_set<Cell>* m_linkedNeighbors{nullptr};
};


#endif //CELL_H
