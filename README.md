# Code analysis by Amit Shinde (006955001)

## Bug 1 :
### Description : Incorrect boundary check in ConnectX::inBounds()
#### Details:

In ConnectX.cpp, the ConnectX::inBounds function will return true even if the width is -ve( and out of bounds).

It should check for both height and width together and then send the result.

This results in the ConnectX::at() function failing to return correct output as well.

Testcases : 
```
checkOutofBounds
checkShowBoard
```

## Bug 2 :
### Description : No column value check in ConnectX::placePiece()
#### Details :

In the placePiece() function, the column parameter should be checked if its less than 0 or outofbounds.

Testcases :
```
checkoutofPlacePiece
```

## Bug 3 :
### Description : Player turn gets toggled even if trying to place in invlaid location
#### Details :

In the placePiece() function, toggleTurn() is called outside the if condition. It should be called within the if condition , just before break.

## Bug 4 :
### Description : Trying to place in outofbounds column crashes the program
#### Details :

In the placePiece() function, at() tries to return a value of a location which doesn't exist. This is not handled correctly in inBounds(), which causes
a coredump when value returned by at() is compared with EMPTY.

Testcases:
```
checkoutofPlacePiece
checkPlayerTurn
```
