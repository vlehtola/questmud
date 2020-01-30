inherit "obj/monster";

reset(arg) {
    string chat_str;
    object armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(57);
    set_alias("marcus");
    set_name("ranger");
    set_short("Marcus the Forest Ranger");
    set_long("Marcus the forest ranger is an old man. He is grey-bearded and his hair is greying. He is looking you with his keen blue eyes. Although he is an old man, he is strong built.\n");
    set_al(-20);
    set_aggressive(0);
    set_block_dir("northeast");
    set_gender(1);
    set_str(600);
    set_race("human");
    set_max_hp(29000);
    set_hp(29000);
    set_skill("tumble", 90);
    set_log(1);

        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Ranger says: 'This cloak is important. I dare not to let it out of my sight.'\n";
    }
    load_chat(3, chat_str);

    armour = clone_object("/wizards/irmeli/bwp/eq/boots.c");
    move_object(armour, this_object());
    init_command("wear boots");

    armour = clone_object("/wizards/irmeli/bwp/eq/cloak.c");
    move_object(armour, this_object());
    init_command("wear cloak");
}
