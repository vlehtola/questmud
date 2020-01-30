inherit "obj/monster";

reset(arg) {

     object weapon;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(35+random(6));
    set_name("guard");
    set_alias("lizardman");
    set_alt_name("lizard");
    set_special(100);
    set_race("lizardman");
    set_short("A huge lizardman guard picking his nose");
    set_long("A tall and huge lizardman guarding the door with great\n"+
             "pride. It seems that he fears nothing.\n");
             

    set_al(40);
    set_aggressive(0);
    set_al_aggr(161);
    set_gender(1);
    set_block_dir("enter");
    set_block_message("The guard pushes you away from the door as you try to enter.");

    weapon = clone_object("/wizards/siki/lizard/eq/club");
    move_object(weapon,this_object());
    init_command("wield maul");
}


special_move() {
  object ob;
  ob = present("guard", environment(this_object()));
  if(attacker_ob && ob) {
    ob->attack_object(attacker_ob);
    return 1;
  

  }

}

