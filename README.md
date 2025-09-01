# ROBOT CONTROLLER
This simple C++ code is a program for controlling robots that move on a table surface.

## Tasks
### Robots
- Two remote-controlled robots are placed on a rectangular table.
- The robots can be independently controlled to navigate the table surface.
- A robot’s position and orientation are represented by the three values. The X-Axis
and the Y-Axis coordinates, and the Orientation of the robot represented by one of the
four cardinal compass points (N, S, E, W). Ex: “0 0 N”
### Table
- The table is divided into a grid to simplify navigation.
- The lower-left (Southwest) coordinate of the table is (0, 0). Coordinate values increase
by one to the North and to the East.
### Controller
- A robot is controlled via a simple string of characters. The possible letters are ‘L’, ‘R’ and
‘M’. The characters ‘L’ and ‘R’ make the robot spin 90 degrees left or right from its
current orientation without moving from its current location. ‘M’ means move forward
one grid point maintaining the same orientation.
- Each robot will be moved sequentially. This means the second robot won’t start to move
until the first robot has finished moving.
### Data Input
- Data input is ASCII textual data. Each data value is separated by a space.
- Line 1 – Describes the upper-right (Northeast) coordinates of the table (zero-based).
- Line 2 – The starting location and orientation of robot #1.
- Line 3 – The starting location and orientation of robot #2.
- Line 4 – The commands for robot #1.
- Line 5 – The commands for robot #2.
### Data Output
- The final position and orientation for each robot will be displayed after running the
scenario.

## Examples
_Example 1 Input_
```
5 5
1 2 N
3 3 E
L M L M L M L M M
M M R M M R M R R M
```
_Example 1 Output_
```
- Table Status -
Robot 0: (1,2) N
Robot 1: (3,3) E
  __________________
5|  |  |  |  |  |  |
  __________________
4|  |  |  |  |  |  |
  __________________
3|  |  |  |> |  |  |
  __________________
2|  |^ |  |  |  |  |
  __________________
1|  |  |  |  |  |  |
  __________________
0|  |  |  |  |  |  |
  __________________
   0  1  2  3  4  5


- Table Status -
Robot 0: (1,3) N
Robot 1: (5,1) E
  __________________
5|  |  |  |  |  |  |
  __________________
4|  |  |  |  |  |  |
  __________________
3|  |^ |  |  |  |  |
  __________________
2|  |  |  |  |  |  |
  __________________
1|  |  |  |  |  |> |
  __________________
0|  |  |  |  |  |  |
  __________________
   0  1  2  3  4  5
```

_Example 2 Input_
```
3 6
0 2 S
3 3 E
M L M M L M R M
M M L M R M L M
```

_Example 2 Output_
```
- Table Status -
Robot 0: (0,2) S
Robot 1: (3,3) E
  ____________
6|  |  |  |  |
  ____________
5|  |  |  |  |
  ____________
4|  |  |  |  |
  ____________
3|  |  |  |> |
  ____________
2|v |  |  |  |
  ____________
1|  |  |  |  |
  ____________
0|  |  |  |  |
  ____________
   0  1  2  3

Attempted to move robot out of bounds!
Attempted to move robot out of bounds!
Attempted to move robot out of bounds!

- Table Status -
Robot 0: (3,2) E
Robot 1: (3,5) N
  ____________
6|  |  |  |  |
  ____________
5|  |  |  |^ |
  ____________
4|  |  |  |  |
  ____________
3|  |  |  |  |
  ____________
2|  |  |  |> |
  ____________
1|  |  |  |  |
  ____________
0|  |  |  |  |
  ____________
   0  1  2  3
```

