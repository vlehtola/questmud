inherit "obj/monster";
object weapon;

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 70);
    call_other(this_object(), "set_name", "green spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "A green spirit");
    call_other(this_object(), "set_long", "The Spirit is overwhelming. Its precense makes you truly feel puny.\n"+
                 "But it is still looking at you with a great caution, like if it is afraid of you.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_al_aggr", 1);
    call_other(this_object(), "set_aggressive", 1);
    set_mage(1);
    set_log();
    set_spell_chance(100, "exs fla blt");
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast bolt", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_resists("physical", 70);
    set_resists("cold", 70);
    set_resists("fire", 70);

    weapon = clone_object("/wizards/gynter/element/eq/spirit_plates");
    move_object(weapon, this_object());
    init_command("wear plate");
}
