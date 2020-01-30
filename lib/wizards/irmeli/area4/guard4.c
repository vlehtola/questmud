inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "gremlin guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A gremlin guarding tower");
    call_other(this_object(), "set_long", "A gremlin is guarding the tower from intruders. It looks a quite similar\n" +
                                          "like the earlier gremlins, but you never know.\n"); 
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("down");
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(6)+8);
    move_object(money, this_object());
}



