//
// Created by Nope on 7/8/23.
// Cell object for mazes
//

#ifndef CELL_H
#define CELL_H

#include <cstdlib>
#include <cstdint>
#include <unordered_map>
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
    
protected:

private:
    std::uint64_t m_row{0};
    std::uint64_t m_column{0};

    std::unordered_map<std::string, Cell>* m_neighbors;
};


#endif //CELL_H
