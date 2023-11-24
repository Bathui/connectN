# connectN Game
## Introduction of the game
  - This game is similar to to the tic-tac-toe.
  - Win strategy is same to the tic-tac-toe. The user should connect N chesses (the number is customized by the user) in rows or columns or diagonals to win the game
  - Players can only control the column. Chess is dropped to the each column, which means we cannot freely choose the rows and columns we want to play.

## Algorithms
### Get the basic information
1. Get the number of rows from the user.
2. Get the number of columns from the user.
3. Get the number of consecutive same pieces to win the game.
4. Player 1 will use 'X' and player 2 will use 'O' (character Oh, not zero).
5. Player 1 will begin first, then alternate with each other.
### Play and the win strategy
1. Ask player 1 to pick a certain column to drop the piece first between 0 to the number of columns - 1
2. Check if the user entered an integer between the range, if not keep asking until the user gives a valid number
3. Check if the chosen column has any free space to drop the piece, if not, go back to step 1 to ask again. If yes, then drop it
4. Check if the chessboard now has consecutive same pieces that need to win in any rows, any columns, any diagonals sloping to the right or left. If yes, announce the player dropped the piece to win. If not, switch to another player and go back to step 1 to repeat the same process
### Show the final result
1. If player 1 or player 2 reaches the number of consecutive same pieces to win in any of the four cases mentioned above, we announce player 1 or player 2 won.
2. If the chessboard does not have any empty space to drop pieces and no one won until the end, then we announce tie game.