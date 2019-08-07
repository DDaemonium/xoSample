#pragma once
#include "Field.hpp"

class Game final
{
private:
    Field m_field;
    bool m_isFirstPlayerStep;
    bool m_isFirstPlayerWinner;
    bool m_isWinnerExist;
    size_t m_currentStepsCount;
    size_t m_maxStepCounts;

public:
    explicit Game(size_t size = 3);
    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game() = default;
    void Render() noexcept;
    void NextStep() noexcept;
    bool IsWinnerExest() const;
    bool IsFirstPlayerWinner() const;
    const size_t& MaxStepsCount() const noexcept;

private:
    bool CheckForWinner() const;
    size_t SafeInput()const;
};

