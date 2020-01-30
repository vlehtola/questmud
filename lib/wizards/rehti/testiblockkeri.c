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

special_move() {
  object ob;
  ob = this_object()->query_attacker_ob();
  tell_object(ob, "Knight blocks you\n");
  say("Knight points at "+ob->query_name()+" \n"+
  "and says: 'Gotsa!' \n", ob);
  ob->prevent_move(north);
}
