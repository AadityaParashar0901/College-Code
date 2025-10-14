% check the winner
win(Board, Player) :- rowwin(Board, Player).
win(Board, Player) :- colwin(Board, Player).
win(Board, Player) :- diagwin(Board, Player).

rowwin(Board, Player) :- Board = [Player, Player, Player, _, _, _, _, _, _].
rowwin(Board, Player) :- Board = [_, _, _, Player, Player, Player, _, _, _].
rowwin(Board, Player) :- Board = [_, _, _, _, _, _, Player, Player, Player].

colwin(Board, Player) :- Board = [Player, _, _, Player, _, _, Player, _, _].
colwin(Board, Player) :- Board = [_, Player, _, _, Player, _, _, Player, _].
colwin(Board, Player) :- Board = [_, _, Player, _, _, Player, _, _, Player].

diagwin(Board, Player) :- Board = [Player, _, _, _, Player, _, _, _, Player].
diagwin(Board, Player) :- Board = [_, _, Player, _, Player, _, Player, _, _].

% the display function
display([A,B,C,D,E,F,G,H,I]) :- write([A,B,C]),nl,write([D,E,F]),nl,write([G,H,I]),nl,nl.

% define the moves for player x
xmove([b,B,C,D,E,F,G,H,I], 1, [x,B,C,D,E,F,G,H,I]).
xmove([A,b,C,D,E,F,G,H,I], 2, [A,x,C,D,E,F,G,H,I]).
xmove([A,B,b,D,E,F,G,H,I], 3, [A,B,x,D,E,F,G,H,I]).
xmove([A,B,C,b,E,F,G,H,I], 4, [A,B,C,x,E,F,G,H,I]).
xmove([A,B,C,D,b,F,G,H,I], 5, [A,B,C,D,x,F,G,H,I]).
xmove([A,B,C,D,E,b,G,H,I], 6, [A,B,C,D,E,x,G,H,I]).
xmove([A,B,C,D,E,F,b,H,I], 7, [A,B,C,D,E,F,x,H,I]).
xmove([A,B,C,D,E,F,G,b,I], 8, [A,B,C,D,E,F,G,x,I]).
xmove([A,B,C,D,E,F,G,H,b], 9, [A,B,C,D,E,F,G,H,x]).
% illegal move
xmove(Board, _, Board) :- write('Illegal move.'), nl, fail.

% define the moves for player o
omove([b,B,C,D,E,F,G,H,I], 1, [o,B,C,D,E,F,G,H,I]).
omove([A,b,C,D,E,F,G,H,I], 2, [A,o,C,D,E,F,G,H,I]).
omove([A,B,b,D,E,F,G,H,I], 3, [A,B,o,D,E,F,G,H,I]).
omove([A,B,C,b,E,F,G,H,I], 4, [A,B,C,o,E,F,G,H,I]).
omove([A,B,C,D,b,F,G,H,I], 5, [A,B,C,D,o,F,G,H,I]).
omove([A,B,C,D,E,b,G,H,I], 6, [A,B,C,D,E,o,G,H,I]).
omove([A,B,C,D,E,F,b,H,I], 7, [A,B,C,D,E,F,o,H,I]).
omove([A,B,C,D,E,F,G,b,I], 8, [A,B,C,D,E,F,G,o,I]).
omove([A,B,C,D,E,F,G,H,b], 9, [A,B,C,D,E,F,G,H,o]).
omove(Board, _, Board) :- write('Illegal move.'), nl, fail.

tictactoe :- explain, playfrom([b,b,b,b,b,b,b,b,b], x).
explain :- write('Player 1 plays X by entering integer positions followed by a period.'), nl,
        write('Player 2 plays O by entering integer positions followed by a period.'), nl,
        display([1,2,3,4,5,6,7,8,9]).
playfrom(Board, _) :-
        win(Board, x), !, display(Board), write('Player 1 Wins'), nl.
playfrom(Board, _) :-
        win(Board, o), !, display(Board), write('Player 2 Wins'), nl.
playfrom(Board, _) :-
        \+ member(b, Board), !, display(Board), write('Game Over'), nl.
playfrom(Board, x) :- player1(Board).
playfrom(Board, o) :- player2(Board).

player1(Board) :-
        write('Player 1: '), nl,
        read(N),
        ( xmove(Board, N, NewBoard) ->
                display(NewBoard),
                playfrom(NewBoard, o);
                player1(Board)).
player2(Board) :-
        write('Player 2: '), nl,
        read(N),
        ( omove(Board, N, NewBoard) ->
                display(NewBoard),
                playfrom(NewBoard, x);
                player2(Board)).
