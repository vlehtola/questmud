inherit "obj/monster";
 
reset(arg) {
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(35);
    set_name("Fiend");
    set_alias("fiend");
    set_short("Winged fiend.");
    set_long("This fiend is flying around this dark labyrhint.\n"+
             "This fiend is quite small but really quick.\n");
    set_al(-60);
    set_aggressive(0);
    set_block_dir("east");
        
    money = clone_object("obj/money");
    call_other(money, "set_money", random(600));
    move_object(money, this_object());
}
