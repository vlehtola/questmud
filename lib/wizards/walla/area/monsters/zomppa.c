inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "zombie");
    call_other(this_object(), "set_alias", "zombie");
    call_other(this_object(), "set_short", "A zombie, risen from the grave");
    call_other(this_object(), "set_long", "The zombie rules this place.\n");
    call_other(this_object(), "set_al", 10);
    set_aggressive(1);
set_undead(1);
    set_dead_ob(this_object());

    weapon  = clone_object("/wizards/walla/area/weapons/hom");
    move_object(armour, this_object());
    init_command("wield hammer");


}
