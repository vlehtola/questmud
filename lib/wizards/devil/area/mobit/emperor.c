inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(60+random(5));
    set_name("havoc");
    set_alias("emperor");
    set_experience(18800234);
    set_max_hp(250000);
    set_hp(250000);
    set_str(546);
    set_con(519);
    set_skill("deceived attack", 100);
    set_skill("stun", 100);
    set_skill("counter spell", 100);
    set_skill("tumble", 50);
    set_undead(1);
    move_object(clone_object("wizards/devil/area/equ/bracers.c"),this_object());
    move_object(clone_object("wizards/devil/area/equ/gloves.c"),this_object());
    move_object(clone_object("wizards/devil/area/equ/stone.c"),this_object());
    set_log();
    set_mage(1);
    set_race("zombie");
    set_short("Havoc, the evil emperor of zombies");
    set_long("This large zombie was one day a fine emperor, but now it's dead. Even after\n"+
                          "it's death it has stayed here to guard something from unwanted visitors. Pieces\n"+
                          "of rotten skin and meat hang from its bones. Some of its yellowed teeth are\n"+
                          "missing, leaving black holes to its mouth. Through its eyeholes, you can see\n"+
                          "white worms having a lunch in his brain. You are quite sure that this zombie\n"+
                          "can kill you anytime it wants.\n");
    set_al(-100);

    set_aggressive(1);
    init_command("wear all");

        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Havoc stares at you evilly.\n";
        chat_str[1] = "Havoc says 'You just should leave this place before I crush your head on the floor'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Havoc screams 'Dieeeeee, you stupid creature!!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(5, a_chat_str);
}
