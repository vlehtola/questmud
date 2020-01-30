inherit "obj/monster";

reset(arg) {
  object armour,weapon;
    int i;
  ::reset(arg);
  if(arg) { return; }
set_race("demon");
  i = random(2);
  set_level(20+i*5);
  set_name("demon");
  set_alias("demon");
  set_short("A large fire demon");
  set_long("This is one of the leaders of the vast armies that the fire lords control.\n"+
           "It is made out of fire, it's legs and arms are as wide as the huge trees\n"+
           "of the mirrhanda forrest. It's head is burning so hot that it is glowing white.\n");
  set_al(10);
  set_aggressive(0);
  set_skill("shield block", 40);
  set_block_dir("east");

  weapon = clone_object("/wizards/gynter/element/eq/f_blade");
  move_object(weapon, this_object());
  init_command("wield blade");

  weapon = clone_object("/wizards/gynter/element/eq/f_shield");
  move_object(weapon, this_object());
  init_command("wield shield");
  set_special(35);  /* Enable special_move() */
}

special_move() {
  object ob;
  int i;
  i = random(10);
  if(i<8) {
	  ob = this_object()->query_attack();
  	tell_object(ob, "The demon grab you and throw you across the room!\n");
  	say("The demon throws "+ob->query_name()+" across the room!\n", ob);
  	ob->hit_with_spell(100, "physical");
	} else {
	  ob = this_object()->query_attack();
  	tell_object(ob, "Fire demon drenches you in molten lava!\n");
  	say("The Fire demon completely drences "+ob->query_name()+" in molten lava!\n", ob);
  	ob->hit_with_spell(500, "fire");
  }
}
