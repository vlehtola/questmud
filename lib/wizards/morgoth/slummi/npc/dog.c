inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 3);
    call_other(this_object(), "set_name", "dog");
    call_other(this_object(), "set_alias", "dog");
    call_other(this_object(), "set_short", "A dirty dog barking at you");
    call_other(this_object(), "set_long",
"The dog is limping its back leg. It's dirty and saliva is dripping from\n"+
"it's mouth. It's barking at you furiously.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_animal", 1);
    call_other(this_object(), "set_aggressive", 0);
 
}
