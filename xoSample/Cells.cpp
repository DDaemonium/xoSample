#include "Cells.hpp"
#include <exception>

Cells::Cells(size_t size)
{
    if (size < 3)
    {
        throw std::exception("Size should be >= 3");
    }

    // please don't move to initializer list to avoid memory allocation
    // when size < 3
    m_cells = new unsigned char[size * size];
    m_size = size;
}

Cells::~Cells()
{
    delete[] m_cells;
}

const unsigned char& Cells::operator()(size_t row, size_t column) const
{
    if ((row >= m_size) || (column >= m_size))
    {
        throw std::exception("Index out of range");
    }

    return m_cells[row * m_size + column];
}

unsigned char& Cells::operator()(size_t row, size_t column)
{
    return const_cast<unsigned char&>(static_cast<const Cells&>(*this)(row, column));
}

const unsigned char& Cells::operator[](size_t index) const
{
    if (index >= m_size * m_size)
    {
        throw std::exception("Index out of range");
    }

    return m_cells[index];
}

unsigned char& Cells::operator[](size_t index)
{
    return const_cast<unsigned char&>(static_cast<const Cells&>(*this)[index]);
}

const size_t& Cells::Size() const noexcept
{
    return m_size;
}

void Cells::Clear() noexcept
{
    for (size_t i = 0, maxSize = m_size * m_size; i < maxSize; ++i)
    {
        m_cells[i] = '*';
    }
}
