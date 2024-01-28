# Combat Game

This C++ program implements a simple combat game where two teams fight each other. Each team consists of players, and each player has attributes such as name, damage (dmg), and health points (hp). Players can also have items that add additional damage.

## Table of Contents
- [Combat Game](#combat-game)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Usage](#usage)
  - [File Structure](#file-structure)
  - [Classes](#classes)
    - [1. `Item`](#1-item)
    - [2. `Playerc`](#2-playerc)
    - [3. `Combat`](#3-combat)
    - [4. `Teams`](#4-teams)
    - [5. `Game`](#5-game)
  - [How to Play](#how-to-play)

## Overview
This C++ program simulates a combat game where two teams, each consisting of players, engage in a battle. Players have attributes like name, damage (dmg), and health points (hp). Players can also carry items that enhance their damage.

## Usage
1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler.
3. Run the executable.

## File Structure
- `main.cpp`: Contains the main code for the combat game.
- `README.md`: Documentation providing an overview of the program, usage instructions, and information about classes.

## Classes

### 1. `Item`
Represents an item that a player can carry.

Attributes:
- `name` (string): Name of the item.
- `dmg` (int): Damage value added by the item.

### 2. `Playerc`
Represents a player in the combat game.

Attributes:
- `name` (string): Name of the player.
- `dmg` (int): Damage value inflicted by the player.
- `hp` (int): Health points of the player.
- `items` (vector<Item>): List of items carried by the player.

Methods:
- `AddItem(const Item& item)`: Adds an item to the player's list of items.

### 3. `Combat`
Manages the combat between two players.

Methods:
- `Fight(Playerc& player1, Playerc& player2)`: Simulates a fight between two players.

### 4. `Teams`
Manages the teams and facilitates team-based interactions.

Attributes:
- `Team1` (vector<Playerc>): List of players in Team 1.
- `Team2` (vector<Playerc>): List of players in Team 2.

Methods:
- `AddToTeam1(string name, int dmg, int hp)`: Adds a player to Team 1.
- `AddToTeam2(string name, int dmg, int hp)`: Adds a player to Team 2.
- `ShowTeam(int teamNumber)`: Displays information about a team.
- `SelectPlayer(int teamNumber)`: Allows the user to select a player from a team.
- `Fight()`: Initiates a fight between selected players from both teams.

### 5. `Game`
Manages the overall game.

Methods:
- `Start()`: Displays the game menu and starts the game.

## How to Play
1. Start the program.
2. Choose the option to start the game from the menu.
3. Teams are automatically populated with players and items.
4. Choose whether to initiate a fight.
5. Select players from each team to fight against each other.
6. Observe the combat simulation with damage dealt and health points.
7. The game ends when one of the players' health points reach zero, or the user chooses to exit.
