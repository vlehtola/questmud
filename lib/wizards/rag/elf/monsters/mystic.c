inherit "obj/monster";
int a;

reset(arg) {
        string chat_str, a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(24+random(4));
        set_name("mystic");
        set_alias("orc");
        set_race("orc");
        set_short("An orcish mystic is here trying to reach the spiritworld");
        set_long("This orc learned the magical secrets of the spirits. She is\n"+
                "wearing dirty black robes. She has long, messy and black hair.\n"+
                "She is concentrating on contacting the spirits for help and power.\n"+
                "She is also offering her guidance to the orcish commander Gabrash.\n");
        set_al(-35);
        set_aggressive(0);
        set_al_aggr(200);
        set_gender(2);
        set_mage(1);
        set_wis(query_wis()*2);
        set_int(query_int()*2);

        set_special(100);
        a = 0;

        if (!chat_str) {
                chat_str = allocate(4);
                chat_str[0] = "Mystic grunts: 'Just a minute, master!'\n";
                chat_str[1] = "Mystic grunts: 'I'm almost there, master!'\n";
                chat_str[2] = "Mystic grunts: 'The spirits are not satisfied!'\n";
                chat_str[3] = "Mystic grunts: 'The amulet that you found is a sign!'\n";
        }
        load_chat(5, chat_str);

        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "Mystic grunts: 'Master, save us!'\n";
                a_chat_str[1] = "Mystic yells: 'Come to my aid, ancient spirits!\n";
        }
        load_a_chat(10, a_chat_str);
}

special_move() {
        object ob;
        ob = present("gabrash", environment(this_object()));
        if(attacker_ob && ob && !a) {
                tell_room(environment(this_object()), "Gabrash suddenly charges at "+
                attacker_ob->query_name()+".\n");
                ob->attack_object(attacker_ob);
                a = 1;
                return 1;
        }
}
