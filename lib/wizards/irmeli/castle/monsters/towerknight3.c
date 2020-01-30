inherit "obj/monster";

reset(arg) {
object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(60);
    set_name("knight");
    set_alias("guard");
    set_short("Knight of the third order of knighthood");
    set_long("A knight of the third order of knighthood. He has passed his middle-age. He has\n"+
             "completed his knight school times ago. He has been guarding the tower of Asgroth\n"+
             "for ages. He has long and grey hair, sharp-featured face and thin body.\n"+
             "Knights are rumoured to be superb sword handlers.\n");

    set_al(10);
    set_race("human");
    set_block_dir("stairs");
    set_gender(1);
    set_str(400);
    set_max_hp(40000);
    set_hp(40000);
    set_special(25);

    weapon = clone_object("/wizards/irmeli/castle/eq/knightsword2.c");
    move_object(weapon, this_object());
    init_command("wield sword");

}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Knight SLASHES you with his sword!\n");
  say("Knight SLASHES "+ob->query_name()+" with his sword!\n", ob);
  ob->hit_with_spell(150, "physical");
}
