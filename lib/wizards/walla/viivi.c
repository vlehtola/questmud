inherit "obj/monster";   
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("babe");
    set_gender(2);
    call_other(this_object(), "set_level", 69);
    call_other(this_object(), "set_name", "viivi");
    call_other(this_object(), "set_alias", "hjani");
    call_other(this_object(), "set_short", "Viivi Avellan, wallas hjanibanimisu.");
    call_other(this_object(), "set_long", "viivi taalla chillailee, ja oottelee poopea.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
}
