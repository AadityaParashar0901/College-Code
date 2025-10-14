set_elements_in_list([], _).
set_elements_in_list([Head | Tail], List) :-
	member(Head, List),
	set_elements_in_list(Tail, List).