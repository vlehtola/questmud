inherit "/obj/monster";
string who;
object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("girl");
    set_short("A little girl, crying in the corner");
    set_long("Little girl, crying in the corner\n");
    set_al(10);
    set_aggressive(0);
    set_gender(2);
    set_undead(1);
    set_race("human");
        chat_str = allocate(3);
         chat_str[0] =
          "Girl sniffs 'We used to play around here..'\n";
         chat_str[1] =
          "Girl sniffs 'We had a treehouse.'\n";
         chat_str[2] =
          "Girl sniffs 'I cant remember where i left it. I dont remember anything else at all!'\n";

    load_chat(15, chat_str);

}               

catch_tell(str) {
if(sscanf(str,"%s gives diary to Girl",who)) {
call_out("helb", 2);
	}
}
helb() {
tell_room(environment(find_player(lower_case(who))),"Girl says 'You found it!'\n");
tell_room(environment(find_player(lower_case(who))),"Girl says 'Here, let me show you secret place of mine!\n");
environment(find_player(lower_case(who)))->add_exit("secret","/wizards/bulut/catacombs/secret");
}                                                               