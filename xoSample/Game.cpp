#include "Game.hpp"
#include <exception>
#include <string>
#include <iostream>

bool TryParseInt(std::string& source, size_t& output);

Game::Game(size_t size):
    m_field(size),
    m_currentStepsCount(0),
    m_isFirstPlayerStep(true),
    m_isFirstPlayerWinner(false),
    m_isWinnerExist(false),
    m_maxStepCounts(size * size)
{
}

void Game::Render() noexcept
{
    system("cls");
    std::cout << "------------------------------------------------\n";
    std::cout << "|--------------------NEMEZIDA------------------|\n";
    std::cout << "------------------------------------------------\n\n";
    m_field.Render();
}

void Game::NextStep() noexcept
{
    Render();
    std::cout << "\n\n------------------------------------------------\n";
    std::cout << "Step Player" << (m_isFirstPlayerStep ? 1 : 2) << " enter cell's number: ";

    if (m_currentStepsCount >= m_maxStepCounts || m_isWinnerExist)
    {
        return;
    }

    const auto choosedCell = SafeInput();
    m_field[choosedCell] = m_isFirstPlayerStep ? 'x' : 'o';
    m_isWinnerExist = CheckForWinner();
    if (m_isWinnerExist)
    {
        m_isFirstPlayerWinner = m_isFirstPlayerStep;
    }
    m_isFirstPlayerStep = !m_isFirstPlayerStep;
    ++m_currentStepsCount;
}

bool Game::IsWinnerExest() const
{
    return m_isWinnerExist;
}

bool Game::IsFirstPlayerWinner() const
{
    return m_isFirstPlayerWinner;
}

const size_t & Game::MaxStepsCount() const noexcept
{
    return m_maxStepCounts;
}

bool Game::CheckForWinner() const
{
    const unsigned char currentPlayerMark = m_isFirstPlayerStep ? 'x' : 'o';
    size_t rowMatchesCount = 0;
    size_t columnMatchesCount = 0;
    for (size_t i = 0; i < m_field.Size(); ++i)
    {
        rowMatchesCount = 0;
        columnMatchesCount = 0;
        for (size_t j = 0; j < m_field.Size(); ++j)
        {
            // check each column
            if (m_field(i, j) == currentPlayerMark)
            {
                ++columnMatchesCount;
            }

            // check each row
            if (m_field(j, i) == currentPlayerMark)
            {
                ++rowMatchesCount;
            }
        }

        // checking for winner
        if ((columnMatchesCount == m_field.Size()) || (rowMatchesCount == m_field.Size()))
        {
            return true;
        }
    }

    // diagonals checking
    rowMatchesCount = 0;
    columnMatchesCount = 0;
    for (size_t i = 0; i < m_field.Size(); ++i)
    {
        // top
        if (m_field(i, i) == currentPlayerMark)
        {
            ++columnMatchesCount;
        }

        // bottom
        const auto tmpIndex = m_field.Size() - i - 1;
        if (m_field(tmpIndex, tmpIndex) == currentPlayerMark)
        {
            ++rowMatchesCount;
        }
    }

    // checking for winner
    if ((columnMatchesCount == m_field.Size()) || (rowMatchesCount == m_field.Size()))
    {
        return true;
    }

    return false;
}

size_t Game::SafeInput() const
{
    std::string input = "";
    size_t cellNumber = 0;

    do 
    {
        getline(std::cin, input);
    }
    while (!TryParseInt(input, cellNumber) || !m_field.IsFree(cellNumber));

    return cellNumber;
}

bool TryParseInt(std::string& source, size_t& output)
{
    try
    {
        output = std::stoi(source);
    }
    catch (...)
    {
        return false;
    }
    return true;
}
