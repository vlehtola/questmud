inherit "/obj/monster";
string who;
object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("crow");
    set_short("A pitch black crow, watching your moves");
    set_long("A pich black crow, never seen crow before?\n");
    set_al(-10);
    set_aggressive(0);
    set_gender(1);
    set_race("animal");
        chat_str = allocate(1);
         chat_str[0] =
          "Crow goes 'Kraaaak'\n";
    load_chat(15, chat_str);

}               

catch_tell(str) {
if(sscanf(str,"%s leaves",who)) {
call_out("helb", 2);
	}
}
helb() {
tell_room(environment(find_player(lower_case(who))),"A crow lands in front of you.\n");
move_object(this_object(),environment(find_player(lower_case(who))));
}                                                               