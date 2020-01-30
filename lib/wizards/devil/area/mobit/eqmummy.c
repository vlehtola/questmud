inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(45+random(10));
    set_name("mordok");
    set_alias("mummy");
    set_alias("king");
    set_experience(6800234);
    set_max_hp(150000);
    set_hp(150000);
    set_str(390);
    set_con(414);
    set_skill("deceived attack", 100);
    set_skill("stun", 100);
    set_skill("counter spell", 100);
    set_undead(1);
    move_object(clone_object("wizards/devil/area/equ/leggings.c"),this_object());
    move_object(clone_object("wizards/devil/area/equ/helmet.c"),this_object());
    set_log();
    set_mage(1);
    set_race("mummy");
    set_short("Mordok, the ancient King of all mummies");
    set_long("This mummy was King in here long time ago, before its dramatic death.\n"+
                      "Mummy is covered with gauze and looks very delicate, but you are almost\n"+
                      "sure that this mummy can do massive damage to its enemy. When you are\n"+
                      "looking mummy in its eyes, you can notice that this mummy is hollow like old\n"+
                      "wood. You have feeling that this mummy is guarding something here, maybe\n"+
                      "some kind path to somewhere.\n");   
    set_al(-100);
    set_aggressive(0);
    init_command("wear all");
    set_block_dir("north");

        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Mummy roars 'Go away you puny creature!'\n";
        chat_str[1] = "Mummy asks 'Trying to find our emperor?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Mummy roars 'Ok! Now I have to kill you!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(5, a_chat_str);
    
}
