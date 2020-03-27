# ConnectFour
This is for a project from my Data Structures class. I added a terminal ConnectFour game with basic AI in Java I did in high school.

# C++
# run different searches:
- in the main.cpp we have commented parts of our function calls:
- for example //bfsnode.BFS(user)
- simply uncomment and you will be able to run

# creating different boards:
- declare a board and treeNode pointer
- then add pieces to board using addPiece(turn, column_number); 
- then set the Board of the treeNode by using treeNodeName->setBoard(board);
- the bfs and iterative deepening algorithms are MEMBER functions
- DFS and Minimax are NON MEMBER functions

# NOTES:
- minimax doesn't work, it can make scores for the children, but cant evaluate them
- bfs and IT work, but it only makes one type of move (only user or only comp)
- DFS works !!!!!!
- IF IT DOESNT RUN, comment the #include <file>.cpp  at the bottom of each header file
  (it works without #include <file.cpp> at the bottom for gene's compiler but works only with it for meriselle's compiler)

# PLEASE refer to presentation to see demos of the code:
- we were able to compile and run, and so we inserted screenshots of the searches working in our presentation
