inherit "obj/monster";
object weapon;
object armour;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name ("knight");
    set_level (50);
    set_special(33);
    set_al(20);
    set_al_aggr(200);
    set_alias("knight");
    set_race("human");
    set_short("Knight is here guarding the tower.");
    set_long("This knight is protecting scout towers from unauthorized entries\n");
    set_aggressive(0);
    armour = clone_object("wizards/rehti/dormund/obj/helm.c");
    move_object(armour, this_object());
    init_command("wear helm");
    weapon = clone_object("wizards/rehti/dormund/obj/sabre.c");
    move_object(weapon, this_object());
    init_command("wield sword");
    set_block_message("Knight says: You are not allowed to go there");
}

init()
{
 ::init();
 add_action("spessuliike", "west" );
 add_action("spessuliike", "north" );
}

spessuliike(string str)
{
    object ob;
    ob = this_object()->query_attack();
    if( !random(2) )
   {
    tell_object(this_player(), this_object()->query_name() + " hits you in the head and blocks your way!\n");
    ob->hit_with_spell(500, "physical");
    return 1;
   }
}


