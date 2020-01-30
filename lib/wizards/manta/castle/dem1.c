inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", random(10)+10);
        call_other(this_object(), "set_name", "demon");
        call_other(this_object(), "set_short", "A little fire demon");
        call_other(this_object(), "set_long", "You are looking at tiny fire demon looking alerted\n" +
                                                          "maybe your arrival upset it.\n");
        call_other(this_object(), "set_al", -50);
        call_other(this_object(), "set_aggressive", 0);
        set_resists(100,1);
        set_exp(query_exp() * 5 / 4);
}