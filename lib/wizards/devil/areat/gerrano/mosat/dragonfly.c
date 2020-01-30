inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("insect");
    call_other(this_object(), "set_level", 18+random(3));
    call_other(this_object(), "set_name", "dragonfly");
    call_other(this_object(), "set_alias", "insect");
    call_other(this_object(), "set_short", "A buzzing dragonfly");
    call_other(this_object(), "set_long", "This is a normal dragonfly which you can meet basically everywhere when\n"+
                                          "moving outside. It has wings and it makes a funny sound when flying. It seems to be a\n"+
                                          "somewhat large one since the swamp has offered this one a nice base for\n"+
                                          "growing with all the alimentation available");
    call_other(this_object(), "set_al", 1);
    call_other(this_object(), "set_aggressive", 0);
 
}
