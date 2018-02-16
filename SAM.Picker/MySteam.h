#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <csignal>
#include "../common/c_processes.h"
#include "Game.h"
#include "../steam/steam_api.h"


class MySteam {
public:
    static MySteam* get_instance();

    // Below are the most useful methods
    bool launch_game(std::string appId);
    bool quit_game();
    std::string get_user_steamId3();
    void print_all_owned_games() const;

    MySteam(MySteam const&)                 = delete;
    void operator=(MySteam const&)          = delete;

private:
    MySteam();
    ~MySteam();
    
    void get_all_owned_games();

    pid_t m_child_pid;
    std::vector<Game_t> m_all_subscribed_apps;
};