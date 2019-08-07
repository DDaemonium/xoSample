#pragma once
class GameExecutor final
{
public:
    GameExecutor() = default;
    GameExecutor(const GameExecutor&) = delete;
    GameExecutor(GameExecutor&&) = delete;
    GameExecutor& operator=(GameExecutor&&) = delete;
    GameExecutor& operator=(const GameExecutor&) = delete;
    ~GameExecutor() = default;
    void Run();
};

