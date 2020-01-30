inherit "obj/monster"; 
 
reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(11);
    set_name("dwarf");
    set_alias("gully");
    set_short("Draconian potguard");
    set_long("The gully dwarf is surely the ugliest thing you've ever seen.\n"+
             "It doesn't seem to be of any opinion to your entering.\n");
    set_al(10);
    set_aggressive(0);
    
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));                    
    move_object(money, this_object());
}

