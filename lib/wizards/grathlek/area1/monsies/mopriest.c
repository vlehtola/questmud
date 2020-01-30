inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("priest");
    set_alias("apprentice");
    set_short("An apprentice priest of the Eternal light");
    set_long("The apprentice is a young man. He is clearly looking for something.\n");
    set_gender(1);
    set_mage(1);
    set_al(30);
    set_race("human");
    set_init_ob(this_object());
 
    set_move_at_random(0);
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
"Apprentice says: 'It is said that the holy meteor is behind the curtains in the temple, but I have never seen it.'\n";
        chat_str[1] =
"Apprentice says: 'Maybe you should go see if you can find the holy meteor from behind the curtains.'\n";
        chat_str[2] =
"Apprentice says: 'The Priest sent me to find his holy cross that he lost on a walk in the forest.'\n";
        chat_str[3] =
"Apprentice says: 'If you find the holy cross, bring it to me please.'\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Priest shouts: 'Why did you attack me?'\n";
    }
    load_chat(5, chat_str); /* load echos when not in combat with 40%
propability*/
    load_a_chat(20, a_chat_str); /* load echos used when  in fight */

 
    armour = clone_object("wizards/grathlek/area1/eq/ball");
    move_object(armour,this_object());
    init_command("wear boots");
}

monster_init() {
   if (this_player()->query_quests("Return the Holy Cross to the priest")) {    
        return 1;
   }
}

catch_tell(str) {
   string tmp1,tmp2;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
        if (present("cross", this_object()) && this_player()->query_name()
                == tmp1) {
           write("Priest says: Thank you for returning it!\n");
          
           if (!this_player()->query_quests("Return the Holy Cross to the priest")) {
              this_player()->set_quest("Return the Holy Cross to the priest");
              destruct(present("cross", this_object()));
           }
        }
   }
}
 

 

