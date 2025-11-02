% Knowledge Base
% career(Career, Interest, Skill).

career(engineering, math, problem_solving).
career(engineering, science, analytical_thinking).
career(data_scientist, computers, data_analysis).
career(data_scientist, math, analytics).
career(doctor, biology, empathy).
career(doctor, science, attention_to_detail).
career(lawyer, social_science, communication).
career(lawyer, social_science, critical_thinking).
career(artist, art, creativity).
career(artist, design, visual_communication).
career(programmer, computers, logic).
career(programmer, computers, coding).
career(teacher, education, communication).
career(teacher, social_science, patience).
career(journalist, social_science, writing).
career(journalist, media, digital_literacy).
career(chef, cooking, creativity).
career(chef, business, leadership).
career(project_manager, business, project_management).
career(project_manager, tech, organization).
career(ui_ux_designer, design, user_experience).
career(ui_ux_designer, art, empathy).
career(cybersecurity_expert, tech, cybersecurity).
career(cybersecurity_expert, computers, attention_to_detail).
career(ai_engineer, computers, ai_skills).
career(ai_engineer, math, programming).
career(digital_marketer, business, digital_marketing).
career(digital_marketer, communication, analytics).

recommend_career(Interest, Skill, Career) :- career(Career, Interest, Skill).
interest(I) :- career(_, I, _). % used to get the list of interests
skill(S) :- career(_, _, S). % used to get the list of skills
all_interests(Interests) :- setof(I, interest(I), Interests).
all_skills(Skills) :- setof(S, skill(S), Skills).
ask_interest(Interest) :-
	all_interests(Interests),
	write("Enter your main interest area "), write(Interests), nl,
	read(Interest).
ask_skill(Skill) :-
	all_skills(Skills),
	write("Enter your top skill "), write(Skills), nl,
	read(Skill).
expert_system :-
	ask_interest(Interest),
	ask_skill(Skill),
	( recommend_career(Interest, Skill, Career) -> format("Recommended Career: ~w. ~n", [Career]);
		write("Sorry, no suitable career found with those interests.")).
