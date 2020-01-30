inherit "obj/monster";
reset(arg) {

string chat_str;
::reset(arg);
if (arg) { return; }
    set_level(100);
    set_name("librarian");
    set_alias("mortimer");
    set_short("Mortimer Blackheart, the old librarian of Duranghom");
    set_long("An old man, Mortimer Blackheart was long ago an archeologist. He travelled\n"+
             "around the world collecting information of various things. Since he started\n"+
             "to grow old, too old for travelling, he settled down and opened library in\n"+
             "the city of Duranghom. The books and scrolls from his journeys he stored in\n"+
             "the library. Nowadays those books and scrolls are somewhere in the shelves\n"+
             "of the library.\n");

    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);

        if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
"Librarian asks: 'You going somewhere?'\n";
        chat_str[1] =
"Librarian informs you: 'Just tell me the place where you want to go.'\n";
        chat_str[2] =
"Librarian states: 'There are five sections, where you can go from here. The sections are: channel, essence, abjuration, necromancy and chaos.'\n";
        chat_str[3] =
"Librarian mumbles: 'In these five sections you can get info about spells.'\n";
        chat_str[4] =
"Librarian proudly states: 'Here are so much books, that you must search throughly if you intend to find what you are looking for.'\n";
    }
    load_chat(15, chat_str);
}

catch_tell(string arg) {
  string plr_name,tmp;
  object ob;
  if(!arg) return 0;
  if(sscanf(arg, "%s says '%s'",plr_name,tmp) != 2)
    return 0;
  ob = find_player(lower_case(plr_name));
  if(!ob) return 0;
  tell_room(environment(this_object()), "Librarian mumbles: 'Let's see.. ");
  if(tmp != "essence" && tmp != "channel" && tmp != "abjuration" && tmp != "necromancy" && tmp != "chaos") {
    tell_room(environment(this_object()), "sorry, no such section here.\n");
    return 0;
  }
  tell_room(environment(this_object()), "follow me.\n");
  ob->move_player("between shelves#/guilds/library/"+tmp+"_section");
/*  tell_room(environment(this_object()), ob->query_name()+" disappears in the middle of book shelves.\n"); */

}







