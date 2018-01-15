# Duch Hunt - The duck hunt legacy

- **Binary name:** my_hunter
- **Repository name:** my_hunter_2017
- **Repository rigths:** ramassage-tek
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

You must make a small video game based on the rules of [Duck Hunt].
The basic rules for the my_hunter are as follows:
- the player is a hunter who shoots ducks.
- ducks must appear on the screen and move from one side to another.
- the player can click on them to shoot them.

Being able to manage inputs from the user and to display animated sprites are key skills
when you want to develop basic games.

> :bulb: You will reuse your work for other video game projects, so think about it to make it the most scalable way.

Your project should of course fit the requirements below but we are expecting it to be more than just a technical demonstration: we want you to think about it as a real game.

> :bulb: This project is probably your first video game ever. Try to have fun making it! You don’t have to stick to the Duck Hunt theme as long as you respect the set of rules given here.

## Requirements

### Must

- The window **must** be closed using events.
- The program **must** manage the input from the mouse click.
- The program **must** contain animated sprites rendered thanks to sprite sheets.

### Should

- Animations in your program **should** be frame rate independant.
- Animations and movements in your program **should** be timed by clocks.
- Your window **should** stick between 800x600 pixels and 1920x1080 pixels.
- Your window **should** have a limited frame rate such that it can be compute without lagging.
- The program **should** accept the “-h” option, then display usage of the program.
- Possible user interactions **should** be explicitly explained in a usage.

### Could

- The program **could** have several different levels.
- The program **could** display the score of the player.
- The program **could** store the highest score made.
- The program **could** display a small target under the mouse cursor.

### Would

- The program **would** be a real mini-game.

<div align="center"><img src="https://tinkerus.files.wordpress.com/2012/09/duckhunt-dogt.png?w=349&h=451" alt="" /></div> 

## Authorized functions

- From the C library:
  - malloc, free, memset
  - rand, srand, time 
  - (f)open, (f)read, (f)close, (f)write
  - getline
- From the CSFML library:
  - All functions

> :warning: Any unspecified functions are de facto banned.

[Duck Hunt]: https://en.wikipedia.org/wiki/Duck_Hunt