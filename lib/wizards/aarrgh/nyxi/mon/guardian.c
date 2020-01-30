inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
set_level(random(2)+40);
set_max_hp(query_max_hp() * 2);
    set_hp(query_max_hp());
    call_other(this_object(), "set_name", "demon");
    call_other(this_object(), "set_alias", "guardian");
    call_other(this_object(), "set_short", "A black guardian demon protecting the entrance");
    call_other(this_object(), "set_long", "You see a huge black guardian demon in front of you. It is wielding\n"
                              "enormous warhammer. The demon itself is very muscular and their strength\n"
                                                          "is something unbelievable.\n");

set_skill("stun", 90);
set_skill("critical", 40);
set_skill("pound", 100);
set_skill("dodge", 40);
set_skill("tumble", 20);
set_skill("attack", 90);
set_skill("alertness", 50);






    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("north");
    set_block_message("Guardian demon grunts: I'm here to protect the Nyx. You may not enter.");

}
