inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_name("Andariel");
    set_alias("andariel");
    set_short("Andariel the maiden of anguish.");
    set_long("She looks really creepy. She has a demonical \n"+
             "grin on her face.\n");
    set_al(-60);
    set_spell_chance(80, "exs fla strm");
    set_aggressive(0);
    set_block_dir("south");
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Andariel chants unholy prayers\n";
        chat_str[1] =
          "Andariel grins evilly. \n";
        chat_str[2] =
          "Andariel says: go away there's nothing for you here.\n";
          
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Andariel screams: You stupid mortal!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);


    weapon = clone_object("/wizards/grathlek/area2/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
