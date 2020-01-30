inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 24);
    call_other(this_object(), "set_name", "spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "A restless spirit");
    call_other(this_object(), "set_long", "A restless spirit looks like it has lost something or somebody. If you\n" +
                                          "look spirits face against the moonlight you notice that it's crying.\n" +
                                          "Acid-tears are burning on spirits face.\n");    
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
}



