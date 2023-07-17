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
#include <optional>
#include <vector>

class Cell {
public:
    Cell(std::size_t row, std::size_t column) {
        m_row = row;
        m_column = column;
    };
    virtual ~Cell() = default;

    std::optional<Cell> getNeighbor(const std::string& neighborLocation); 
    void addNeighbor(const std::string& neighborName, const Cell& neighbor);
    bool isLinkedNeighbor(const Cell& potentialNeighbor);
    void addLinkedNeighbor(Cell& neighbor, bool bidirectional = true);
    void removeLinkedNeighbor(Cell& neighbor, bool bidirectional = true);
    std::uint64_t getRow() const { return m_row; }
    std::uint64_t getColumn() const { return m_column; }

    bool operator==(const Cell& cell) const {
        return (m_row == cell.getRow() && m_column == cell.getColumn());
    }
    
protected:

private:
    std::uint64_t m_row{0};
    std::uint64_t m_column{0};

    std::unordered_map<std::string, Cell>* m_neighbors{nullptr};
    std::vector<Cell> m_linkedNeighbors{};
};

#endif //CELL_H
