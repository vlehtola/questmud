inherit "obj/monster";
 
reset(arg) {

object money;    
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "gull");
    call_other(this_object(), "set_alias", "bird");
    call_other(this_object(), "set_short", "A seagull, sitting on the pier.");
    call_other(this_object(), "set_long", "Another one of those damn seagulls that have irritated \n" +
                                          "fishermen since long ago. It looks wierdly at you.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
 
     money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
}
