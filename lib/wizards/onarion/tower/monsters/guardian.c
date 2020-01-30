inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    set_level(70);
    set_name("guardian");
    set_short("An undead guardian");
    set_long("The guardian is in a form of a human and he is blocking your way up.\n");
    set_al(-20);
    set_aggressive(0);
    set_gender(1);
    set_undead(1);
    set_al_aggr(200);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Guardian hisses: 'Only true mages are allowed to continue.'\n";
        chat_str[1] =
          "Guardian hisses: 'If have not passed the magetest, turn back.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Guardian hisses: 'Even if you made your way in, the mages will kill you.'\n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);
}

init() {
    ::init();
    if(!this_player()->query_guild_level(call_other("world/guilds/guildfun.c",
                "get_guild_number", "Advanced Mages"))) {
         add_action("enter","up");
    }
}

enter() {
    write("Guardian block your way and hisses: 'Thou shall not pass.'\n");
    return 1;
}




