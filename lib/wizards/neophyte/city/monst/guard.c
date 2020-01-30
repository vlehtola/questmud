inherit "obj/monster";
reset(arg) {
        string chat_str, a_chat_str;
        object mace,shield;
                ::reset(arg);
                if(arg) {return; }
    set_level(75);
    set_name("guard");
    set_alias("guard");
    set_short("Sturdy looking gate guard");
    set_long("The guard is wearing a full battle armour, which looks very strong\n"+
             "and sturdy. He is constantly looking for gates and is stopping people\n"+
             "that don't have proper authority to go inside the city.\n");
    set_gender(1);
    set_race("human");
    set_str(query_str()+400);
    set_max_hp(query_hp()*4);
    set_hp(query_max_hp());
    set_aggressive(0);
    mace = clone_object("/wizards/neophyte/city/eq/mace.c");
        move_object(mace, this_object());
    init_command("wield mace");
        shield = clone_object("/wizards/neophyte/city/eq/armour");
                move_object(shield, this_object());
            init_command("wear all");
                   if (!chat_str) {
                               chat_str = allocate(2);
                               chat_str[0] =
                       "Guard says: 'I am guarding the city from wolf's'\n";
                               chat_str[1] =
                       "Guard says: 'I think they have cave somewhere on this island.'\n";
                           }
                           if (!a_chat_str) {
                               a_chat_str = allocate(1);
                               a_chat_str[0] = "Guard shouts: 'Intruders!'\n";
                           }
                           load_chat(3, chat_str);
           load_a_chat(3, a_chat_str);
 }
init() {
  add_action("quest_tmp", "north");
  add_action("block", "south");
}

quest_tmp() {
  if(!this_player()->query_npc()) {
	  if(!this_player()->query_quests("Find wolfrider den")) {
    write("Guard blocks your way and says: 'Stop!, you have to perform little task for me until, i can let you go inside the city'\n");
    say("Guard blocks "+this_player()->query_name()+" for going in the city.\n", this_player());
    return 1;
  }
}
  		  say("Guard says: 'Move alone citizen.'\n");
}

block() {
          if(this_player()->query_npc()) {
                  say("Guard says: 'I have to block your way to the outworld, because that place is too dangerous.\n");
                  return 1;
          }
}
ask_question(str) {
        if(str == "task") {
                say("Guard says: 'Find the wolfrider den and i will let you go inside.'\n");
                return 1;
        }
        write("Guard says: 'I don't know anything about that'.\n");
        return 1;
}
