inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", random(10)+20);
        call_other(this_object(), "set_name", "demon");
        call_other(this_object(), "set_short", "A small fire demon");
        call_other(this_object(), "set_long", "You are looking at small fire demon looking nasty\n" +
                                                          "maybe he don't like you.\n");
        call_other(this_object(), "set_al", -60);
        call_other(this_object(), "set_aggressive", 0);
        set_resists(100,1);

}
