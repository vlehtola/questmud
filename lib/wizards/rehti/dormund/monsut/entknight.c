inherit "obj/monster";
object armour;
object weapon;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (50);
    set_max_hp(query_max_hp()*5);
    set_str(query_str()*3);
    set_gender(1);
    set_al(20);
    set_alias("knight");
    set_race("human");
    set_short("Knight bearing the mark of bodyguards is protecting the castle.");
    set_long("This Knight seems to be more ready for attack than you might ever be. You should not anger him.\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/chainmail.c");
    move_object(armour, this_object());
    init_command("wear mail");
    weapon = clone_object("wizards/rehti/dormund/obj/broadsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
    set_follow(80,2);
    set_block_dir("north");
    set_block_message("Knight says: I'm not allowed you to enter to the head knights chambers");
}