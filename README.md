# Code analysis by Amit Shinde (006955001)

## Bug 1 :
### Description : Incorrect boundary check in ConnectX::inBounds()
#### Details:

In ConnectX.cpp, the ConnectX::inBounds function will return true even if the width is -ve( and out of bounds).

It should check for both height and width together and then send the result.

This results in the ConnectX::at() function failing to return correct output as well.

## Bug 2 :
### Description : No column value check in ConnectX::placePiece()
#### Details :

In the placePiece() function, the column parameter should be checked if its less than 0 or outofbounds.
