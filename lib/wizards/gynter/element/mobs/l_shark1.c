inherit "obj/monster";

reset(arg) {
  object money, item;
    int i;
  ::reset(arg);
  if(arg) { return; }
  i = random(2);
  set_level(20+i*5);
  set_name("large shark");
  set_alias("shark");
  set_short("A large shark");
  set_long("This is one of the dangerous great whites. It has huge teeth and\n"+
           "and a very big mouth. It could probably eat anything!\n");
  set_al(-150);
  set_aggressive(0);
  set_animal(1);

  item = clone_object("/wizards/gynter/element/eq/icecube");
  move_object(item, this_object());
  set_special(5);  /* Enable special_move() */
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "The shark BITES you over the torso causing EXCRUTIATING pain!\n");
  say("The shark BITES "+ob->query_name()+" causing EXCRUTIATING pain!\n", ob);
  ob->hit_with_spell(700, "physical");
}
