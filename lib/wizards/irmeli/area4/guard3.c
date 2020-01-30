inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "gremlin guard");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A gremlin guarding tower");
    call_other(this_object(), "set_long", "A gremlin is guarding the tower from intruders. It's the most powerful\n" +
                                          "and muscular guard in here. Although gremlins are usually small, this\n" + 
                                          "guard is big and strong, making you tiny beside it.\n");
    call_other(this_object(), "set_al", -15);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("up");
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(9)+11);
    move_object(money, this_object());
}



