inherit "obj/monster";
object armour;
object weapon;
object helm;
object boots;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (50);
    set_gender(1);
    set_al(20);
    set_alias("knight");
    set_race("human");
    set_short("Knight here is scouting the areas surrounding the fort.");
    set_long("This knight is in important role in defence of the fort. His work should not be interfered.\n");
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
    boots = clone_object("wizards/rehti/dormund/obj/boots.c");
    move_object(boots, this_object());
    init_command("wear boots");
}    