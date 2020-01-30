inherit "obj/monster";
int a;

reset(arg) {
        string a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(24+random(4));
        set_name("troll");
        set_race("troll");
        set_alias("guard");
        set_short("A cave troll is here guarding the commander");
        set_long("This troll is big and ugly, just like all the other trolls.\n"+
                "It's not wielding any weapons so it is probably a fierce warrior\n"+
                "with its bare hands. It has huge muscles and tusks that could\n"+
                "impale any armour easily. It is trained to stop all those who\n"+
                "attack the orc commander.\n");
        set_al(-50);
        set_aggressive(0);
        set_al_aggr(200);

        set_special(100);
        a = 0;

        if (!a_chat_str) {
                a_chat_str = allocate(3);
                a_chat_str[0] = "Troll grunts: 'Grreaat! A fight!'\n";
                a_chat_str[1] = "Troll screams: 'Me bash you!'\n";
                a_chat_str[2] = "Troll yells a fearsome battlecry and charges at you!\n";
        }
        load_a_chat(20, a_chat_str);
}

special_move() {
        object ob;
        ob = present("mystic", environment(this_object()));
        if(attacker_ob && ob && !a) {
                tell_room(environment(this_object()), "The mystic mumbles arcane chants and attacks "+
                attacker_ob->query_name()+".\n");
                ob->attack_object(attacker_ob);
                a = 1;
                return 1;
        }
}
