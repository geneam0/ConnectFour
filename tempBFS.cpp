#ifndef __TEMPBFS_CPP__
#define __TEMPBFS_CPP__

#include "main.cpp"
#include "priorityQueue.cpp"

PriorityQueue<Item> choices;
PriorityQueue<Item> children;


size_t BFS(init) {
  /*pseudocode:
  generate children and add to siblings queue.
  read top queue and increase depth count by 1, 
  calculate priority and cost
  cost being priority + 5 - count
  then add to priority queue
  then shift over 
  and gradually fill priority queue, after four levels, top of priority queue is the column returned. 

var breadthFirstIteration = function() {
    if (queue.length > 0) {
        var node = queue.shift();
        if (node.parent != node) {
            if (!node.parent.children) {
                node.parent.children = [];
            }
            node.parent.children.push(node);
        }
        var moves = node.game.moves();
        for (var i = 0; i < moves.length; i++) {
            queue.push({
                game: node.game.copy().move(i),
                parent: node,
                id: counter++
            });
        }
        return node;
    }
};


  */

  
  

   
   


#endif  
