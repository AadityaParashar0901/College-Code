% edge(A, B) defines a unidirectional edge from A to B
edge(a, b).
edge(b, a).
edge(b, c).
edge(c, b).
edge(c, a).
edge(a, c).
edge(c, d).
edge(d, c).
edge(d, e).
edge(e, d).

% a node is defined if an edge exists from it
node(X) :- edge(X, _); edge(_, X).

% get the list of all nodes
all_nodes(Nodes) :- setof(N, node(N), Nodes).

% check if a node is reachable by DFS
reachable(X, X, _).
reachable(X, Y, _) :- edge(X, Y).
reachable(X, Y, Visited) :- edge(X, Z), \+ member(Z, Visited), reachable(Z, Y, [Z | Visited]).

% check if all nodes in the graph are connected
connected :- all_nodes([Start | Rest]), reachable_all(Start, Rest).

% check if all nodes are accesible from a specified node
reachable_all(_, []).
reachable_all(Start, [N | Rest]) :- reachable(Start, N, [Start]), reachable_all(Start, Rest).

% check if all edges are bidirectional
bidirectional :- \+ (edge(X, Y), \+ edge(Y, X)).

% print the graph type
graph_type :- ( connected -> ( bidirectional -> write('Graph is connected and bidirectional.'), nl; write('Graph is connected and unidirectional.'), nl); write('Graph is not connected'), nl).