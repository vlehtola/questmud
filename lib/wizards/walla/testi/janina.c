



inherit "obj/monster";

reset(arg) {
reset(arg);
if(arg) { return; }
call_other(this_object(), "set_level", 69);
call_other(this_object(), "set_name", "janina");
call_other(this_object(), "set_alias", "hani");
call_other(this_object(), "set_short", "Hjanina Frostell the cat");
call_other(this_object(), "set_long", "Hjanina is (one of) Wallas hani(s).\n");
call_other(this_object(), "set_al", 200);
call_other(this_object(), "set_aggressive", 0);
}
