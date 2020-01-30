inherit "obj/monster";
object weapon;
object helm;
object armour;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (50);
    set_al(20);
    set_alias("knight");
    set_race("human");
    set_short("Knight is here guarding the tower.");
    set_long("This knight is protecting scout towers from unauthorized entries\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/chainmail.c");
    move_object(armour, this_object());
    init_command("wear mail");
    weapon = clone_object("wizards/rehti/dormund/obj/broadsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
    helm = clone_object("wizards/rehti/dormund/obj/helm.c");
    move_object(helm, this_object());
    init_command("wear helm");
    set_block_dir("up");
    set_block_message("Knight says: You are not allowed to go there");
}