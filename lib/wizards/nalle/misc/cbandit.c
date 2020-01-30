inherit "obj/monster";

object player;
string player_s="you";
string chat_str, a_chat_str;

reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(15);
    set_experience(121000);
    set_gender(2);
    set_race("elf");
    set_name("bandit");
    set_alias("elf");
    set_short("A cute female bandit");
    set_long("This elven bandit looks at you shyly and smiles a beautiful smile.\n");
    set_al(1);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="The bandit dreams about "+player_s+".\n";
        chat_str[1] ="The bandit winks at you cutely.\n";
        chat_str[2] ="The bandit sighs at "+player_s+" longingly.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The bandit screams: 'You really hurt my feelings!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(10, a_chat_str);

}

set_master(object master) {
player=master;
player_s=master->query_name();

chat_str[0] ="The bandit dreams about "+player_s+".\n";
chat_str[1] ="The bandit winks at you cutely.\n";
chat_str[2] ="The bandit sighs at "+player_s+" longingly.\n";

call_out("move_check",4);
}

move_check() {

// Check that the master is in the game
if(!find_player(lower_case(player_s))) { 
say("The bandit sighs sadly as "+player_s+" is nowhere to be found and leaves.\n"); 
destruct(this_object()); return 1;     }

// Master has moved
if(!present(lower_case(player_s), environment(this_object())))  { 
say("The cute bandit runs after "+player_s+".\n"); 
move_object(this_object(), environment(player));
say("A cute bandit following "+player_s+" arrives.\n", player);
tell_object(player, "The cute elven bandit arrives and smiles at you fondly.\n");
                                                                }
call_out("move_check",4);
}
