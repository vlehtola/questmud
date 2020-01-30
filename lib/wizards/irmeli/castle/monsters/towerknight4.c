inherit "obj/monster";

reset(arg) {
object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(65);
    set_name("knight");
    set_alias("guard");
    set_short("Knight of the fourth order of knighthood");
    set_long("A knight of the fourth order of knighthood. He is very old but still strong. He has\n"+
             "completed his knight school times ago. He has been guarding the tower of Asgroth for\n"+
             "ages. He has long and grey hair, yellowed face and very thin body. Despite that he\n"+
             "is old he is flexible and he moves fast. Knights are rumoured to be superb sword\n"+
             "handlers.\n");

    set_al(10);
    set_race("human");
    set_block_dir("stairs");
    set_gender(1);
    set_str(400);
    set_max_hp(40000);
    set_hp(40000);
    set_special(25);

    weapon = clone_object("/wizards/irmeli/castle/eq/knightsword3.c");
    move_object(weapon, this_object());
    init_command("wield sword");

}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Knight SLASHES you with his sword!\n");
  say("Knight SLASHES "+ob->query_name()+" with his sword!\n", ob);
  ob->hit_with_spell(200, "physical");
}
