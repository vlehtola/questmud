inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(35+random(10));
    set_name("mah'lak");
    set_alias("spirit");
    set_experience(4800234);
    set_max_hp(150000);
    set_hp(150000);
    set_str(331);
    set_con(341);
    set_skill("deceived attack", 100);
    set_skill("critical", 100);
    set_skill("reflect spell", 100);
    set_skill("tumble", 100);
    set_skill("stun", 100);
    set_skill("counter spell", 100);
    set_undead(1);
    move_object(clone_object("wizards/devil/area/equ/plate.c"),this_object());
    move_object(clone_object("wizards/devil/area/equ/ring.c"),this_object());
    set_log();
    set_race("spirit");
    set_mage(1);
    set_short("Mah'lak, the Spirit of Darkness");
    set_long("This spirit seems to been here very long time, like it is guarding\n"+
                      "something here. Spirit is large sized and almost invisible, as you\n" +
                      "think what thatorrible creature can do cold shivers is going down your\n" +
                      "spine. You almost can see through it and notice something behind it,\n"+
                      "maybe some kind path.\n");    
    set_al(-100);

    set_aggressive(0);
    init_command("wear all");
    set_block_dir("north");

    
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Mah'lak flows around.\n";
        chat_str[1] = "Mah'lak roars 'What are you doing in here?!?'.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mah'lak roars 'Bruahahhaa! Finally someone brave have entered in this place!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(5, a_chat_str);
}
