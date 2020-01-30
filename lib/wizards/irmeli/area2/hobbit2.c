inherit "obj/monster";



reset(arg) {

    string chat_str, a_chat_str;

    object money, weapon; 

    ::reset(arg);

    if (arg) { return; }

    set_level(5);

    set_name("hobbit");

    set_alias("miner");

    set_short("A small hobbit miner");

    set_long("A small hobbit miner is working here. The sweat flows along his face. He has been working here longer than you have lived.\n");

    set_race("hobbit");

    set_gender(1);

    set_al(10);

    set_aggressive(0);

        if (!chat_str) {

        chat_str = allocate(2);

        chat_str[0] =

          "Mining pick crushes into rock splattering small rocks all around the place.\n";

        chat_str[1] =

          "Hobbit miner says: 'This work kills me.'\n";

    }

    if (!a_chat_str) {

        a_chat_str = allocate(1);

        a_chat_str[0] = "Hobbit miner says: 'Leave me alone.'\n";

    }

    load_chat(1, chat_str);

    load_a_chat(1, a_chat_str);




    

    weapon = clone_object("/wizards/irmeli/area2/equ/pick.c");

    move_object(weapon, this_object());

    init_command("wield pick");    

}



