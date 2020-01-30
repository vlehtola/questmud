inherit "obj/monster";

reset(arg) {
    object armor;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 46);
    call_other(this_object(), "set_name", "Bishop");
    set_gender(1);
    set_race("human");
    set_log();
    call_other(this_object(), "set_alias", "bishop");
    call_other(this_object(), "set_short", "The bishop");
    call_other(this_object(), "set_long", "The bishop looks like a serious man.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
  
    armor = clone_object("/wizards/nalle/jerusalem/eq/bisring");
    move_object(armor, this_object());
    init_command("wear ring");

    weapon = clone_object("/wizards/nalle/jerusalem/eq/bisstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}
