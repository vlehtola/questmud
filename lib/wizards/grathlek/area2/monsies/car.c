inherit "obj/monster";
 
reset(arg) {
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(31);
    set_name("Carcass");
    set_alias("carcass");
    set_short("Rotting carcass.");
    set_long("This carcass has been waken from very long\n"+
             "sleep. It is rotting from all over.\n");
    set_al(-60);
    set_undead(1);
    set_aggressive(1);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(100));
    move_object(money, this_object());
}
