inherit "obj/monster";

reset(arg) {
        string a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(21+random(4));
        set_name("troll");
        set_race("troll");
        set_short("A cave troll is here looking for intruders");
        set_long("This troll is big and ugly, just like all the other trolls.\n"+
                "It's not wielding any weapons so it is probably a fierce warrior\n"+
                "with its bare hands. It has huge muscles and tusks that could\n"+
                "impale any armour easily. The cave is it's territory and you get\n"+
                "the feeling that it doesn't like those who have entered the cave.\n");
        set_al(-50);
        set_aggressive(1);

        if (!a_chat_str) {
                a_chat_str = allocate(3);
                a_chat_str[0] = "Troll grunts: 'Grreaat! A fight!'\n";
                a_chat_str[1] = "Troll screams: 'Me bash you!'\n";
                a_chat_str[2] = "Troll yells a fearsome battlecry and charges at you!\n";
        }
        load_a_chat(20, a_chat_str);
}
