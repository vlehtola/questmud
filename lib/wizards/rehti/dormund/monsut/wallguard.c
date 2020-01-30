inherit "obj/monster";
object weapon;
object helm;
object boots;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (45);
    set_gender(1);
    set_al(20);
    set_alias("knight");
    set_race("human");
    set_short("Knight is here protecting the walls.");
    set_long("This knight seems to be ready for any kind of attacks\n");
    set_aggressive(0);
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