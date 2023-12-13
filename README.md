
# bingo Game

Bingo Game ReadMe
Introduction
Welcome to the Bingo Game, a classic and engaging console-based gaming experience written in C++. Whether you're a solo player looking for a challenging computer opponent or eager to compete against a friend, this game has you covered. The highlights of this Bingo Game include single-player and two-player modes, saving and resuming game progress, robust Bingo-checking mechanisms, and an appealing user interface.

Getting Started
To embark on your Bingo adventure, compile and run the bingo.cpp file using your preferred C++ compiler. Upon execution, the game menu will appear, offering options to start a new game, resume a game, view game history, or gracefully exit. Follow the on-screen instructions to navigate through the menu.

Single-Player Mode

Overview:

In Single-Player Mode, players face off against a computer opponent. The computer generates a Bingo card for the player, and the goal remains consistent: achieve Bingo by marking rows, columns, or diagonals before the computer does.

Difficulty Levels:

Players can choose from three difficulty levels:

1)Easy:

 The computer opponent makes relatively straightforward moves, providing a gentle introduction to the game.

2)Medium: 

The computer adapts its strategy by intelligently filling one diagonal on its Bingo card.

3)Hard: 

A more challenging mode where the computer strategically marks numbers in two diagonals on its Bingo card.

Game Flow:

The computer generates a Bingo card based on the chosen difficulty level.
The player marks numbers on their card, and the computer responds with strategic moves.
The game continues until either the player or the computer achieves Bingo.

Two-Player Mode

Overview:

Two-Player Mode allows friends to compete against each other in a head-to-head Bingo showdown. Each player has their Bingo card, and the first to achieve Bingo is declared the winner.

Game Flow:

Players take turns marking numbers on their respective Bingo cards.
The competition continues until one player achieves Bingo.
A winner is declared, and a celebratory message is displayed.

Features

Bingo Checking

Under the hood, the game boasts a sophisticated mechanism to check for Bingo in rows, columns, and diagonals. The finding_bingo function meticulously evaluates the marked cells on the Bingo card, determining whether the conditions for a Bingo have been met.

User Interaction

To enhance the overall gaming experience, the console displays information using colored text. Menus, messages, and Bingo cards are presented in a visually appealing and user-friendly manner. The use of colors adds a touch of vibrancy to the interface.

Saving and Resuming

Players have the flexibility to save their game progress and resume it later. This feature utilizes file handling to store critical information such as player names, game options, and the configurations of Bingo cards. It ensures that players can pick up right where they left off, adding a layer of convenience and continuity to the gaming experience.

Game Flow

Toss: 
The game starts with a coin toss to determine the starting player, ensuring a fair and unpredictable beginning.

Single-Player Mode:
 The computer generates a Bingo card based on the chosen difficulty level. The player marks numbers, and the computer adapts its strategy in response to the player's moves.

Two-Player Mode:

Players take turns marking numbers on their respective Bingo cards. The game continues until one player achieves Bingo.

Winning Message:
 Upon achieving Bingo, a celebratory winning message is displayed, showcasing the victorious player's name and the layout of the winning Bingo cards.

Saving and Resuming: 
Players can choose to save their progress at any point, making it easy to pick up the game later. Saved data includes player names, game options, and Bingo card configurations.

Game History:

To keep track of triumphs and outcomes, the game logs winners and game results in the "gamehistory.txt" file. This historical record allows players to revisit their achievements and relive memorable moments from past games.

Error Handling:

To ensure a smooth and frustration-free gaming experience, the game incorporates robust error handling. If a player enters invalid input, the game prompts them to correct it, maintaining the integrity of the gameplay.

Conclusion:

Get ready for an entertaining Bingo experience! Whether you're playing against a computer opponent or challenging a friend, this C++ Bingo Game promises hours of fun and strategic gameplay. Dive into the source code to understand the game mechanics or make modifications to tailor the experience to your liking.
Enjoy the game, and may the numbers align in your favor!



