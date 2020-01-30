inherit "obj/monster";
int a;

reset(arg) {
        object weapon, armour, shield, amu;
        string chat_str, a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(44);
        set_race("orc");
        set_name("gabrash");
        set_alias("orc");
        set_alt_name("commander");
        set_short("Gabrash the orcish commander is planning a battle");
        set_long("Gabrash is a very large and muscular orc. He is wearing\n"+
                "a typical orcish chain mail, but his flail seems to be\n"+
                "rather unusual. He is planning some sort of attack to the\n"+
                "forest. He seems to be furious about something and he is\n"+
                "trying to get the spirits to reveal the future.\n");
        set_al(-60);
        set_aggressive(0);
        set_al_aggr(200);
        set_gender(1);

        set_special(100);
        a = 0;

        set_log();

        weapon = clone_object("/wizards/rag/elf/weapons/flail");
        move_object(weapon,this_object());
        init_command("wield flail");

        shield = clone_object("/wizards/rag/elf/weapons/orc_shield");
        move_object(shield,this_object());
        init_command("wield shield");

        armour = clone_object("/wizards/rag/elf/armours/orc_mail");
        move_object(armour,this_object());
        init_command("wear mail");

        amu = clone_object("/wizards/rag/elf/eq/amulet");
        move_object(amu,this_object());

        if (!chat_str) {
                chat_str = allocate(4);
                chat_str[0] = "Gabrash grunts: 'What do the spirits say?'\n";
                chat_str[1] = "Gabrash grunts: 'We will crush the elves soon!'\n";
                chat_str[2] = "Gabrash walks around the chamber nervously.\n";
                chat_str[3] = "Gabrash swings a golden amulet.\n";
        }
        load_chat(7, chat_str);

        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "Gabrash cackles and yells 'Diiieee!!!'\n";
                a_chat_str[1] = "Gabrash yells a fearsome battlecry and swings his flail fiercely!\n";
        }
        load_a_chat(10, a_chat_str);
}

special_move() {
        object ob;
        ob = present("troll", environment(this_object()));
        if(attacker_ob && ob && !a) {
                tell_room(environment(this_object()), "Troll suddenly charges at "+
                attacker_ob->query_name()+".\n");
                ob->attack_object(attacker_ob);
                a = 1;
                return 1;
        }
}
