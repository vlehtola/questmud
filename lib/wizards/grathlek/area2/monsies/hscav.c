inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(38);
    set_name("Scavenger");
    set_alias("scavenger");
    set_short("A HUGE scavenger");
    set_long("This scavenger is looking for victims to kill.\n"+
             "It has large claws,long tail and glowing res eyes.\n");
    set_al(-60);
    set_aggressive(1);
    set_move_at_random(3);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(600));
    move_object(money, this_object());
}
