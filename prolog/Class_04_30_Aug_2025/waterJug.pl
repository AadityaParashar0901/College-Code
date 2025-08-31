fillA(state(A, B), state(MaxA, B), MaxA, _) :-
        A < MaxA.
fillB(state(A, B), state(A, MaxB), _, MaxB) :-
        B < MaxB.
emptyA(state(A, B), state(0, B), MaxA, _) :-
        A > 0, A =< MaxA.
emptyB(state(A, B), state(A, 0), _, MaxB) :- 
        B > 0, B =< MaxB.
pourAtoB(state(A, B), state(NewA, NewB), _, MaxB) :-
        A > 0, B < MaxB, NewB is min(MaxB, A + B), NewA is A - (NewB - B).
pourBtoA(state(A, B), state(NewA, NewB), MaxA, _) :-
        B > 0, A < MaxA, NewA is min(MaxA, A + B), NewB is B - (NewA - A).
bfs([[State, Path] | _], _, _, _, State, Path).
bfs([[CurrentState, CurrentPath] | RemainingOpenQueue], VisitedStates, MaxA, MaxB, GoalState, SolutionPath) :-
        findall([NextState, [NextOp | CurrentPath]], (
                (fillA(CurrentState, NextState, MaxA, MaxB), NextOp = fillA);
                (fillB(CurrentState, NextState, MaxA, MaxB), NextOp = fillB);
                (emptyA(CurrentState, NextState, MaxA, MaxB), NextOp = emptyA);
                (emptyB(CurrentState, NextState, MaxA, MaxB), NextOp = emptyB);
                (pourAtoB(CurrentState, NextState, MaxA, MaxB), NextOp = pourAtoB);
                (pourBtoA(CurrentState, NextState, MaxA, MaxB), NextOp = pourBtoA)),
                Neighbours),
        filter_unvisited(Neighbours, VisitedStates, FilteredNeighbours),
        append(RemainingOpenQueue, FilteredNeighbours, NewQueue),
        bfs(NewQueue, [CurrentState, VisitedStates], MaxA, MaxB, GoalState, SolutionPath).
filter_unvisited([], _, []).
filter_unvisited([[State, _] | Rest], Visited, Filtered) :-
        member(State, Visited), !,
        filter_unvisited(Rest, Visited, Filtered).
filter_unvisited([[State, _] | Rest], Visited, [[State, _] | Filtered]) :- filter_unvisited(Rest, Visited, Filtered).
solve_water_jug(StartA, StartB, MaxA, MaxB, TargetA, TargetB, Path) :-
        InitialState = state(StartA, StartB),
        GoalState = state(TargetA, TargetB),
        bfs([[InitialState, []]], [InitialState], MaxA, MaxB, GoalState, ReversedPath),
        reverse(ReversedPath, Path).