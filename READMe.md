# filler

<br>
<img align="left" height="250" src="https://github.com/42kmira/ft_filler/blob/master/resources/Untitled.png" />
<br>

This project has us making an program that is able to play a game called filler. The game is played through another program
that manages the actual game, ```filler_vm```. A map is passed onto the game and one or two player programs are passed. The programs play by taking turns reading stdin and writing to stdout. After running make all, you will make my player ```kmira.filler```. More information about the game can be found in the Introduction of [this](https://github.com/42kmira/ft_filler/blob/master/resources/filler.en.pdf) pdf.

The visualization is being printed out to stderr to avoid conflicts, but will only work by passing the -q option to ```filler_vm``` or by piping the output of ```filler_vm``` to somewhere like ```/dev/null```. The vizualization below was built by me for the purposes of showing and debugging how the algorithm priorities moves.

Usage looks like: ```./filler_vm -f < map path > -p1 < executable player1 path > [-p2 < executable player2 path >]```. Although you can just run ```./filler_vm``` to get a help message. I pipe to ```/dev/null``` for the visualization to be printed correctly.

Alternatively do ```make hard``` after having made ```kmira.filler``` for ease of use. Maps are fairly easy to make, they have to be rectangles and examples can be found [here](https://github.com/42kmira/ft_filler/tree/master/resources/maps), additional players are also found [here](https://github.com/42kmira/ft_filler/tree/master/resources/players).

Below is a visualization of the heatmap that my filler algorithm uses to pick the 'best' move. The concept of the heatmap
is simply: pick the move such that the given piece is as close as possible to the enemy.

![alt text](https://github.com/MrColour/filler/blob/master/resources/heatmap.gif)
