inherit "obj/monster";   
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("babe");
    set_gender(2);
    call_other(this_object(), "set_level", 69);
    call_other(this_object(), "set_name", "linda");
    call_other(this_object(), "set_alias", "brava");
    call_other(this_object(), "set_short", "Linda plays here her violin here");
    call_other(this_object(), "set_long", "Linda shure knows how to play with her violin.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
}

 
