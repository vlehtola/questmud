
inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour,armour2;
    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(2);
    set_level(60);
    set_name("monk");
    set_alias("outcast");
    set_short("3e");
    set_long("You see nothing special.\n");
    set_race("human");
    set_gender(1);
    set_log();
    set_al(-75);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "You hear a quiet shuffling.\n";
        chat_str[1] =
          "You feel like someone is watching you\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Monk shouts: 'You must DIE!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
 
    if(i==0) { armour = clone_object("/wizards/walla/area2/stuph/cloak");
    move_object(armour, this_object());
    init_command("wear cloak");
}
    if(i==1) { armour2 = clone_object("/wizards/walla/area2/stuph/knuckles");
    move_object(armour2, this_object());
    init_command("wear knuckles");
  }
}


