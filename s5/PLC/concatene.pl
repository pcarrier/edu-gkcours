concatene([],L,L).
concatene([E|L],G,[E|T]) :- concatene(L,G,T).
