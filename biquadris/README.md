HOW TO PLAY

Biquadris is a non-realtime, 2 player version of tetris.

run ./biquadris to play
This assumes the user knows the basic rules of tetris.

You will be shown 2 "screens" of biquadris, player 1 and player 2
Player 1 goes first. 

Enter "left/right/down" to move your block 1 unit in that direction.
Enter "drop" to drop the block all the way down.
Enter "clockwise/counterclockwise" to rotate your block

Enter "levelup/leveldown" to change the level.
Level 0: blocks generated are determined by files "biquadris_sequence1.txt" for player 1 and "biquadris_sequence2.txt" for player 2

Level 1: blocks generated randomly such that S and Z blocks have a 1/12 probability of spawning as opposed to 1/6 for the other blocks

Level 2: blocks generated randomly at equal probability

Level 3: blocks generated randomly such that S and Z blocks have a 2/9 probability of spawning as opposed to 1/9 for other blocks. Also, every command to move or rotate the block will be followed by a downward movement.

Level 4: Same as 3, but every time you place 5 (and 10, 15, etc) blocks without clearing a row, a 1x1 block is dropped onto your game board in the centre column.

