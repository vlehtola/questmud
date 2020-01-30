inherit "obj/monster";
 
reset(arg) {
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(59);
    set_name("Gargoyle");
    set_alias("gargoyle");
    set_short("A Gargoyle");
    set_long("This demon is really large and it has a \n"+
             "stone skin.\n");
    set_al(-60);
    set_spell_chance(100, "exs sol strm");
    set_resists(0, 90);
    set_resists(1, 90);
    set_resists(7, 90);
    set_resists(3, 90);
    set_resists(5, 60);
    set_aggressive(0);
    set_move_at_random(16);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(6000));
    move_object(money, this_object());
}
