inherit "obj/monster";

int *prime_numbers, the_number;

reset(arg) {
  string chat_str;
  prime_numbers = ({ 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, });
  the_number = 8 + random(5);
  if(environment(this_object()))
    tell_room(environment(this_object()), "Thalos seems to change his mind about something.\n");
  ::reset(arg);
  if (arg) { return; }
    set_level(100);
    set_name("thalos");
    set_short("Thalos, the long bearded mathematician");
    set_long("A truly great beard covers almost a half of Thalos' face.\n"+
		"He is somewhat bald at the top of his head, the huge amount\n"+
		"of thinking must have caused it. His clothes are somewhat\n"+
		"dusty and have seen a better day. The great mathematician\n"+
		"seems sunken in his thoughts.\n");
    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);

        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Thalos mumbles something in his long beard.\n";
        chat_str[1] =
"Thalos says 'Maybe you could help me a little, yes?'\n";
        chat_str[2] =
"Thalos seems to be focused on some problem.\n";

    }
    load_chat(15, chat_str);
}

catch_tell(string arg) {
  string plr_name,tmp;
  object ob;
  int answer;
  if(!the_number) {
     the_number = 8 + random(5);
     prime_numbers = ({ 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, });
  }
  if(!arg) return 0;
  if(sscanf(arg, "%s says '%s'",plr_name,tmp) != 2)
    return 0;
  ob = find_player(lower_case(plr_name));
  if(!ob) return 0;
  if(tmp == "yes") {
    tell_room(environment(this_object()), "Thalos explains: 'I would need you to justify my theory about prime numbers, understood?'\n");
    return 0;
  }
  if(tmp == "understood") {
    tell_room(environment(this_object()), "Thalos explains: 'I say 1 2 3 5 7 11... what is the "+(the_number+1)+"th number?'\n");
    return 0;
  }
  answer = to_int(tmp);
  if(answer) {
    if(!the_number) {
      tell_room(environment(this_object()), "Thalos seems to be still angry since he ignores the answer.\n");
      return 0;
    }
    if(answer != prime_numbers[the_number]) {
      tell_room(environment(this_object()), "Thalos seems a bit upset and yells: 'No no no, that is wrong! On your way now..'\n");
      the_number = 0;
      return 0;
    }
    tell_room(environment(this_object()), "Thalos seems content and says: 'Very good, excellent indeed..'\n");
    ob->set_quest("Prime numbers");
    reset(1);
    return 0;
  }

}







