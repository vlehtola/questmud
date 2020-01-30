inherit "obj/monster";
 
reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(1);
    set_name("rodent");
    set_alias("rotta");
    set_short("taa on rodentti");
    set_long("joojoo, jotain sinnepain.. ei ehka nayta rotalta mut se on\n"+
             "It doesn't seem to be of any opinion to your entering.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(6);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());
}
 
