inherit "obj/monster";

reset(arg) {
        string chat_str, a_chat_str;
        object weapon, armour, shield;
        ::reset(arg);
        if(arg) { return; }
        set_level(53);
        set_name("salin");
        set_alias("elf");
        set_alt_name("ranger");
        set_race("wood elf");
        set_dex(query_dex()*3);
        set_short("Salin the ranger is here studying herbs");
        set_long("Salin has long brown hair which is tied back with\n"+
                "colourful ropes. He has crystal blue eyes. He is\n"+
                "wearing rugged clothes under his leather armour.\n"+
                "He is an excellent marksman with the bow, but he\n"+
                "doesn't seem to have his legendary silvery bow\n"+
                "with him now. He seems very calm.\n");
        set_al(40);
        set_aggressive(0);
        set_al_aggr(200);
        set_gender(1);

        weapon = clone_object("/wizards/rag/elf/weapons/elf_sword");
        move_object(weapon,this_object());
        init_command("wield sword");

        shield = clone_object("/wizards/rag/elf/weapons/elf_shield");
        move_object(shield,this_object());
        init_command("wield shield");

        armour = clone_object("/wizards/rag/elf/armours/elf_leather");
        move_object(armour,this_object());
        init_command("wear armour");

        move_object("/wizards/rag/elf/objects/leaf",this_object());
        move_object("/wizards/rag/elf/objects/leaf",this_object());
        move_object("/wizards/rag/elf/objects/leaf",this_object());


        if (!chat_str) {
                chat_str = allocate(3);
                chat_str[0] = "Salin says: 'I wonder what happened to Celebmir's amulet.'\n";
                chat_str[1] = "Salin says: 'It's been too long without the orcs attacking us...'\n";
                chat_str[2] = "Salin says: 'I found these strange leaves, but I don't know yet\n"+
                                "if they're any good.'\n";
        }
        load_chat(5, chat_str);

        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "Salin says: 'You've chosen death!'\n";
                a_chat_str[1] = "Salin moves around very quickly, it's hard to hit him at all!\n";
        }
        load_a_chat(5, a_chat_str);
}
