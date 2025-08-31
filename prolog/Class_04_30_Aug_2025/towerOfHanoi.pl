move(1, Source, Destination, _) :- format('Move from ~w to ~w~n', [Source, Destination]).
move(N, Source, Destination, Auxiliary) :- N > 1, M is N - 1,
	move(M, Source, Auxiliary, Destination),
	move(1, Source, Destination, _),
	move(M, Auxiliary, Destination, Source).
hanoi(N) :- move(N, left, right, center).
