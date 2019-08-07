#include "Field.hpp"
#include <exception>
#include <iostream>

Field::Field(size_t size) : m_cells(size)
{
    m_cells.Clear();
}

void Field::Render() noexcept
{
    std::cout << "|--------------------Sample------------------|\n\n";
    RenderSampleField();
    std::cout << "\n\n|--------------------Feild------------------|\n";
    for (size_t i = 0; i < m_cells.Size(); ++i)
    {
        std::cout << "\n";
        for (size_t j = 0; j < m_cells.Size(); ++j)
        {
            std::cout << static_cast<unsigned char>(m_cells(i, j)) << "\t|\t";
        }
    }
}

const unsigned char& Field::operator()(size_t row, size_t column) const
{
    return m_cells(row, column);
}

unsigned char& Field::operator()(size_t row, size_t column)
{
    return m_cells(row, column);
}

const unsigned char & Field::operator[](size_t index) const
{
    return m_cells[index];
}

unsigned char & Field::operator[](size_t index)
{
    return m_cells[index];
}

bool Field::IsFree(size_t row, size_t column) const
{
    return m_cells(row, column) == '*';
}

bool Field::IsFree(size_t index) const
{
    return m_cells[index] == '*';
}

const size_t & Field::Size() const noexcept
{
    return m_cells.Size();
}

void Field::RenderSampleField() noexcept
{
    for (size_t i = 0, linearCounter = 0; i < m_cells.Size(); ++i)
    {
        std::cout << "\n";
        for (size_t j = 0; j < m_cells.Size(); ++j, ++linearCounter)
        {
            const auto tmp = m_cells(i, j);
            if (tmp == '*')
            {
                std::cout << linearCounter;
            }
            else
            {
                std::cout << static_cast<unsigned char>(tmp);
            }
            std::cout << "\t|\t";
        }
    }
}
