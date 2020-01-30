inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "zombie");
    call_other(this_object(), "set_alias", "zombie");
    call_other(this_object(), "set_short", "A zombie rising from the grave");
    call_other(this_object(), "set_long", "A zombie is rising from the the old grave. Zombie looks like it has been\n" +
                                          "under the surface of the earth about thousands years. Zombie slobbers\n" +
                                          "as it notices you.\n");    
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
}



