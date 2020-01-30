inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 45);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "monster");
    call_other(this_object(), "set_short", "A guard watching the maze");
    call_other(this_object(), "set_long", "The gateguard seems bored of his work.\n" +                                          
                                          "He guards the maze.\n" +
                                          "I wonder why.\n");
    call_other(this_object(), "set_al", 10);
  call_other(this_object(), "set_aggressive", 0);                   
    if (!chat_str) {
        chat_str = allocate(5);
        chat_str[0] =
          "Guard says: I think you better leave now.\n";
        chat_str[1] =
          "Guard says: Don't enter that maze, unless you are ready to face death.\n";
        chat_str[2] =
          "Guard says: Do not enter the maze. There is nothing but trouble in there.. well - that also.\n";
        chat_str[3]=
          "Guard watches you suspiciously.\n";
        chat_str[4]=
         "Guards eyes glow yellow for a while.\n";
          
  }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "DIE!\n";
    }
    load_chat(30, chat_str);
    load_a_chat(15, a_chat_str);
 
    armour = clone_object("/wizards/walla/area/armour/icering");
    move_object(armour, this_object());
    init_command("wear ring");
 
    armour = clone_object("/wizards/walla/area/armour/firering");
    move_object(armour, this_object());
    init_command("wear ring");
 
    weapon = clone_object("/wizards/walla/area/weapons/icemace");
    move_object(weapon, this_object());
    init_command("wield mace");
 
    weapon = clone_object("/wizards/walla/area/weapons/firemace");
    move_object(weapon, this_object());
    init_command("lwield mace 2");
 
}
 
