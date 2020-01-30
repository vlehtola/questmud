inherit "obj/monster";

reset(arg) {
    object armor;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "Beggar");
    call_other(this_object(), "set_alias", "beggar");
    call_other(this_object(), "set_short", "An old beggar");
    call_other(this_object(), "set_long", "An old, sad looking man with poor hygiene.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_al_aggr(20); 
  
    armor = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armor, this_object());
    init_command("wear rags");

}

