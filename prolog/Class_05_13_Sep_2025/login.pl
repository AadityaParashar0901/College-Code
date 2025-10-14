password(somethingy).
login :- attempt(1).
attempt(Attempt) :- Attempt =< 3,
	write('Enter Password: '), nl,
	read(Input),
	password(CorrectPassword),
	(
		Input == CorrectPassword, !, write('Login Successful'), nl;
		write('Incorrect Password'), nl,
		write('Failed Attempt '), write(Attempt), nl,
		NextAttempt is Attempt + 1,
		attempt(NextAttempt);
		write('Login Unsuccessful'), nl).