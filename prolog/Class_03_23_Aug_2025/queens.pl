solve(N, [N]) :- goal(N). % terminate
solve(N, [N | Sol1]) :- pred(N, N1), solve(N1, Sol1). % solve predecessor

goal([_, _, _, _, _, _, _, _]). % the goal

pred(Queens, [Queen | Queens]) :- % generate predecessor
	member(Queen, [1, 2, 3, 4, 5, 6, 7, 8]), % choose a row for queen from 1 to 8
	noattack(Queen, Queens, 1). % check if the queen is not being attacked

noattack(_, [], _).
noattack(Y, [Y1 | Others], ColDistance) :- 
	Y =\= Y1, % not on the same row
	Diff is Y - Y1,
	abs(Diff) =\= ColDistance, % not on the same diagonal
	NextColDistance is ColDistance + 1, % to check for the next queen
	noattack(Y, Others, NextColDistance).

member(Item, [Item | _]). % list function
member(Item, [_ | Rest]) :- member(Item, Rest).
