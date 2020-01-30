inherit "obj/monster";
object armour;
object weapon;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (50);
    set_max_hp(query_max_hp()*2);
    set_str(query_str()*2);
    set_gender(1);
    set_al(20);
    set_alias("knight");
    set_race("human");
    set_short("Knight bearing the mark of bodyguards is standing in guard.");
    set_long("This Knight seems to look that no one goes to dungeon. You should not anger him.\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/chainmail.c");
    move_object(armour, this_object());
    init_command("wear mail");
    weapon = clone_object("wizards/rehti/dormund/obj/broadsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
    set_block_dir("down");
    set_block_message("Knight says: You cannot go there. There is an ferocious beast down there.");
}