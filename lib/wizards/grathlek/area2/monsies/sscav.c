inherit "obj/monster";
 
reset(arg) {
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(33);
    set_name("Scavenger");
    set_alias("scavenger");
    set_short("A small scavenger");
    set_long("This scavenger is looking for corpses of victims\n"+
             "killed by their larger cousins. It has a sharp\n"+
             "claws and a long tail.\n");
    set_al(-60);
    set_aggressive(0);
    set_move_at_random(2);
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(600));
    move_object(money, this_object());
}
