solve(N, [N]) :- goal(N).
solve(N, [N | Sol1]) :- pred(N, N1), solve(N1, Sol1).

goal([_, _, _, _, _, _, _, _]).

pred(Queens, [Queen | Queens]) :- member(Queen, [1, 2, 3, 4, 5, 6, 7, 8]), noattack(Queen, Queens, 1).

noattack(_, [], _).
noattack(Y, [Y1 | Others], ColDistance) :- Y =\= Y1, Diff is Y - Y1, abs(Diff) =\= ColDistance, NextColDistance is ColDistance + 1, noattack(Y, Others, NextColDistance).

member(Item, [Item | _]).
member(Item, [_ | Rest]) :- member(Item, Rest).
