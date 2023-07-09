//
// Created by Nope on 7/8/23.
// Cell object for mazes
//

#ifndef CELL_H
#define CELL_H

#include <cstdlib>
#include <vector>

class Cell {
public:
    Cell(std::size_t row, std::size_t column) {
        m_row = row;
        m_column = column;
    };
    virtual ~Cell() = default;
protected:

private:
    std::size_t m_row{0};
    std::size_t m_column{0};
    std::size_t m_northNeighbor[2];
    std::size_t m_southNeighbor[2];
    std::size_t m_eastNeighbor[2];
    std::size_t m_westNeighbor[2];
    std::vector<std::vector<std::size_t>> links;
};


#endif //CELL_H
