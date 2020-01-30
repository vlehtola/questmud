inherit "obj/monster";

reset(arg) {
    int i,q;
    string chat_str, a_chat_str;
    object crown,belt,neck,boots;
    ::reset(arg);
    if(arg) { return; }

    set_level(70+random(20));
    set_name("razindukhta");
    set_alias("king");
    set_race("dwarf");
    set_str(query_str()*2);
    set_short("Razindukhta, the old King ");
    set_long("The dwarf you see before you is the old king, Razindukhta.\n" +
              "He is armoured from head to toe, and his arsenal of weapons is not to be taken\n" +
             "lightly. It seems that nothing could penetrate his defences. His goal is clear,\n" +
             "to kill all invading forces.\n");
    set_al(-35);
    set_gender(1);
    set_log();


    crown = clone_object("/wizards/walla/northern/stuph/razi_crown");
    move_object(crown,this_object());
    init_command("wear crown");

    belt = clone_object("/wizards/walla/northern/stuph/razi_belt");
    move_object(belt,this_object());
    init_command("wear belt");

    neck = clone_object("/wizards/walla/northern/stuph/razi_neck");
    move_object(neck,this_object());
    init_command("wear chain");

    boots = clone_object("/wizards/walla/northern/stuph/razi_boots");
    move_object(boots,this_object());
    init_command("wear boots");

    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Razindukhta says: 'I'm not the real threat, the thing in the basement is'.\n";
        chat_str[1] =
          "Razindukhta says: 'That Khilarbhunaz locked me up in the tower. Kill HIM'.\n";
        chat_str[2] =
          "Razindukhta says: 'In the basement lives pure evil'.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Razindukhta screams: 'Now for ruin, now for wrath. And a red dawn!'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
    set_dead_ob(this_object());
}

monster_died() {
    tell_object(this_object()->query_attack(),
    "Thane draws his final breath of air in this world.\n");
    shout("A crack of thunder can be heard as "+this_player()->query_name()+" delivers a killing blow!\n");
    return 0;
}
