inherit "obj/monster";

reset(arg) {
    string chat_str;
    object weapon;

    ::reset(arg);
    if(arg) { return; }
    
    
    set_level(22+random(3));
    set_name("lizardman");
    set_alias("male");
    set_alt_name("lizard");
    set_race("lizardman");
    set_short("A lizardman staring at the lake");
    set_long("A huge lizardman standing almost in the water and staring\n"+
             "in the lake. He seems to long for something.\n");

    set_al(20);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

    if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The lizardman sighs deeply.\n";
    chat_str[1] = "The lizardman hisses 'Tshe evil monsshter took my csshild!'\n"+
                  "and curses loudly.\n";
       }
    load_chat(5, chat_str);

    weapon = clone_object("/wizards/siki/lizard/eq/club");
    move_object(weapon,this_object());
    init_command("wield maul");

}


