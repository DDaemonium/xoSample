#pragma once

class Cells final
{
private:
    unsigned char* m_cells;
    size_t m_size;

public:
    // size - rows OR columns count
    // will be generated matrix size x size
    // size should be >= 3
    explicit Cells(size_t size = 3);
    Cells(const Cells&) = delete;
    Cells(Cells&&) = delete;
    Cells& operator=(Cells&&) = delete;
    Cells& operator=(const Cells&) = delete;
    ~Cells();
    const unsigned char& operator()(size_t row, size_t column) const;
    unsigned char& operator()(size_t row, size_t column);
    const unsigned char& operator[](size_t index) const;
    unsigned char& operator[](size_t index);
    const size_t& Size() const noexcept;
    void Clear() noexcept;
};

