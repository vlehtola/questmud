inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 70);
    call_other(this_object(), "set_name", "red spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "A red spirit");
    call_other(this_object(), "set_long", "The Spirit is overwhelming. Its precense makes you truly feel puny.\n" +
                               "But it is still looking at you with a great caution, like if it is afraid of you.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_al_aggr", 1);
    call_other(this_object(), "set_aggressive", 1);
    set_log();
    set_mage(1);
    set_spell_chance(100, "exs brr blt");
    set_skill("cast essence", 100);
    set_skill("cast ice", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
set_resists("physical", 70);
set_resists("fire", 70);

    armour = clone_object("/wizards/gynter/element/eq/spirit_rings");
    move_object(armour, this_object());
    init_command("wear ring");
}
