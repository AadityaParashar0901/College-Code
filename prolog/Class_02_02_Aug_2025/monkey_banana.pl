% state(position of monkey, position of box, { ground | box }, { empty | banana })
% define goal state
goal(state(center, center, box, banana)).

% define places
place(window).
place(center).
place(door).

% define moves
%  grasping
grasp(state(center, center, box, empty), state(center, center, box, banana)).
%  climbing
climb(state(center, center, ground, empty), state(center, center, box, empty)).
%  pushing
push(state(X, X, ground, empty), state(Y, Y, ground, empty)) :- place(X), place(Y), X \= Y.
%  walking
walk(state(X, Y, ground, empty), state(Z, Y, ground, empty)) :- place(X), place(Y), place(Z), X \= Z.

% solve
solve(S) :- goal(S). % termination
solve(S) :- grasp(S, F), solve(F). % priority 1: grasp
solve(S) :- climb(S, F), solve(F). % priority 2: climb
solve(S) :- push(S, F), solve(F). % priority 3: push
solve(S) :- walk(S, F), solve(F). % priority 4: walk
