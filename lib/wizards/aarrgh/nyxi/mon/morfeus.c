inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour;
    object weapon;
        ::reset(arg);
    if(arg) { return; }
    set_undead(1);
set_max_hp(query_max_hp() * 3);
set_hp(query_max_hp());
set_level(random(2)+70);
set_log();
    call_other(this_object(), "set_name", "morfeus");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A dark man with demonically glowing eyes");
    call_other(this_object(), "set_long", "You see a dark man in front of you. He has red, evil looking\n"
                                          "eyes. He is surrounded with a vortex of darkness. He is wielding\n"
                                          "a dagger obviously used in sacrificing rituals.\n");
set_spell_chance(90, "exs fla blt");
    set_spell_chance(90, "exs brr blt");
    set_skill("cast ice", 90);
    set_skill("slash", 100);
    set_skill("critical", 40);
    set_skill("cast bolt", 90);
    set_skill("cast essence", 90);
    set_skill("cast fire", 90);
    set_skill("tumble", 30);
    set_skill("alertness", 50);
    set_skill("mana control", 80);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("pool");
    set_block_message("Morfeus stands in your way.\n");

    if (!a_chat_str) {
         a_chat_str = allocate(3);
         a_chat_str[0] = "Morfeus thunders: I'm the guardian of the portal\n";
         a_chat_str[1] = "Morfeus thunders: Do not try to enter the pool\n";
         a_chat_str[2] = "Morfeus cackles evilly and points you with his dagger!\n";
         }


    load_chat(40, chat_str);
    load_a_chat(35, a_chat_str);

    armour = clone_object("/wizards/aarrgh/nyxi/obj/cloak.c");
    move_object(armour, this_object());
    init_command("wear cloak");
    weapon = clone_object("/wizards/aarrgh/nyxi/obj/dagger.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
