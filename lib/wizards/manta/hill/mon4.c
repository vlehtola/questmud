inherit "obj/monster";



reset(arg) {


        ::reset(arg);

        if(arg) { return; }

        call_other(this_object(), "set_level", 21);

        call_other(this_object(), "set_name", "demon");

        call_other(this_object(), "set_short", "A small fire demon");

        call_other(this_object(), "set_long", "Well fed fire demon.\n");

        call_other(this_object(), "set_al", -70);

        call_other(this_object(), "set_aggressive", 0);




}

