Code analysis by Amit Shinde (006955001)

Bug 1 -
Description : Incorrect boundary check in ConnectX constructor
Details :

In ConnectX.cpp, the constructor checks for height,width and to win values less than 0.
It should also check for values greater than `DEFAULT_WIDTH`, `DEFAULT_HEIGHT` & `DEFAULT_TO_WIN`.

The following code snippet should be modified :
```
    if( wide <= 0 || high <= 0 || x <= 0)
    {
        wide=DEFAULT_WIDTH;
        high=DEFAULT_HEIGHT;
        x=DEFAULT_TO_WIN;
    }

```

to :

```
    if( wide <= 0 || high <= 0 || x <= 0 || wide > DEAFULT_WIDTH || high > DEFAULT_HEIGHT || x > DEAFULT_TO_WIN)
    {
        wide=DEFAULT_WIDTH;
        high=DEFAULT_HEIGHT;
        x=DEFAULT_TO_WIN;
    }
```
