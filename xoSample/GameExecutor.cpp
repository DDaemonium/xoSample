#include "GameExecutor.hpp"
#include "Game.hpp"
#include <string>
#include <iostream>

extern bool TryParseInt(std::string& source, size_t& output);
static size_t SafeInput();

void GameExecutor::Run()
{
    std::cout << "Enter field size (>= 3): ";
    const auto fieldSize = SafeInput();
    Game game(fieldSize);
    for (size_t i = 0; i < game.MaxStepsCount(); ++i)
    {
        game.Render();
        game.NextStep();
        if (game.IsWinnerExest())
        {
            std::cout << "\n\nPlayer" << (game.IsFirstPlayerWinner() ? 1 : 2) << " is winner!!!";
            return;
        }
    }

    std::cout << "\n\n!!!DRAW!!!!";
}

size_t SafeInput()
{
    std::string input = "";
    size_t result = 0;

    do
    {
        getline(std::cin, input);
    } while (!TryParseInt(input, result));

    return result;
}