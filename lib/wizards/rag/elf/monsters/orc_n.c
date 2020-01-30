inherit "obj/monster";

reset(arg) {
        object weapon, armour, shield;
        string chat_str, a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(18+random(4));
        set_name("orc");
        set_race("orc");
        set_short("An orc is here guarding a room");
        set_long("This orc seems ready for a fight. He's wielding his axe firmly\n"+
                "and he must know how to use it! He has black skin and green eyes\n"+
                "which stare at your every move. He obviously sees better than you\n"+
                "in this dark cave.\n");
        set_al(-40);
        set_aggressive(0);
        set_al_aggr(80);
        set_gender(1);
        set_str(query_str()+30);
        set_max_hp(query_max_hp()+400);
        set_block_dir("north");
        set_block_message("Orc says: 'Mrr! Don't go there!'");

        weapon = clone_object("/wizards/rag/elf/weapons/orc_axe");
        move_object(weapon,this_object());
        init_command("wield axe");

        shield = clone_object("/wizards/rag/elf/weapons/orc_shield");
        move_object(shield,this_object());
        init_command("wield shield");

        armour = clone_object("/wizards/rag/elf/armours/orc_mail");
        move_object(armour,this_object());
        init_command("wear mail");

        if (!chat_str) {
                chat_str = allocate(3);
                chat_str[0] = "Orc grunts: 'Stupid trolls keep all the food'\n";
                chat_str[1] = "Orc screams violently: 'When will the battle begin?'\n";
                chat_str[2] = "Orc gulps: 'Now where did I put that key?'\n";
        }
        load_chat(15, chat_str);

        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "Orc grunts: 'Grreaat! A fight!'\n";
                a_chat_str[1] = "Orc yells a fearsome battlecry and swings his axe in a huge arc!\n";
        }
        load_a_chat(20, a_chat_str);
}
