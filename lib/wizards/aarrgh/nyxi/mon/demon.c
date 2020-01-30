inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 60);
set_spell_chance(80, "exs zzt blt");
set_skill("cast essence", 80);
set_skill("cast electricity", 70);
set_skill("cast bolt", 70);
set_skill("mana control", 50);
    call_other(this_object(), "set_name", "demon");
    call_other(this_object(), "set_alias", "demon");
    call_other(this_object(), "set_short", "A Demon of night");
    call_other(this_object(), "set_long", "A Large demon of night\n"
                                          "with red skin.\n");
    call_other(this_object(), "set_al", 10);
    set_block_message("Demon blocks your attempt.");
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir("north");
}
