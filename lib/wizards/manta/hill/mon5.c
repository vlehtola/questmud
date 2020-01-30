inherit "obj/monster";



reset(arg) {


        ::reset(arg);

        if(arg) { return; }

        call_other(this_object(), "set_level", 26);

        call_other(this_object(), "set_name", "demon");

        call_other(this_object(), "set_short", "A lesser fire demon");

        call_other(this_object(), "set_long", "A demon having party with rotten corpses\n");

        call_other(this_object(), "set_al", -74);

        call_other(this_object(), "set_aggressive", 0);




}

