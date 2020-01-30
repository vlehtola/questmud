inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "ghost");
    call_other(this_object(), "set_alias", "ghost");
    call_other(this_object(), "set_short", "A corrupted ghost ");
    call_other(this_object(), "set_long", "A coppurted ghost is watching you from shadows. The ghost is small but it\n" +
                                          "is dangerous and unexpected. Ghosts eyes are a bit strange. A bright\n" +
                                          "yellow light is coming from torch which the ghost is carrying\n");    
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
}



