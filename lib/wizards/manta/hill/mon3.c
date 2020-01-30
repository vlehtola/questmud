inherit "obj/monster";



reset(arg) {


        ::reset(arg);

        if(arg) { return; }

        call_other(this_object(), "set_level", 19);

        call_other(this_object(), "set_name", "demon");

        call_other(this_object(), "set_short", "A smallish fire demon");

        call_other(this_object(), "set_long", "You are looking at a small fire demon.\n" +

                                       "seems it had his own party with these rotten copses.\n");

        call_other(this_object(), "set_al", -50);

        call_other(this_object(), "set_aggressive", 0);




}

