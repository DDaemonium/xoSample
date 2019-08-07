#pragma once

#include "Cells.hpp"

class Field final
{
private:
    Cells m_cells;

public:
    // size - rows OR columns count
    // will be generated matrix size x size
    // size should be >= 3
    explicit Field(size_t size = 3);
    Field(const Field&) = delete;
    Field(Field&&) = delete;
    Field& operator=(Field&&) = delete;
    Field& operator=(const Field&) = delete;
    ~Field() = default;
    void Render() noexcept;
    const unsigned char& operator()(size_t row, size_t column) const;
    unsigned char& operator()(size_t row, size_t column);
    const unsigned char& operator[](size_t index) const;
    unsigned char& operator[](size_t index);
    bool IsFree(size_t row, size_t column) const;
    bool IsFree(size_t index) const;
    const size_t& Size() const noexcept;

private:
    void RenderSampleField() noexcept;
};

