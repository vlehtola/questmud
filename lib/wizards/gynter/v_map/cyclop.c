inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(30+i*5);
  set_name("cyclop");
  set_short("A muscular cyclop");
  set_long("The cyclop seems to be a very strong creature. He looks busy throwing stones.\n");
  set_gender(1);
  if(i==0) {
    set_gender(2);
    set_short("A muscular female cyclop");
    set_long("The cyclop seems to be a very strong creature. She looks busy throwing stones.\n");
    set_special(25);
    set_exp(query_exp()*4/3);
  }
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  if(ob->query_gender() != 1) return 0;
  tell_object(ob, "Cyclop kicks you in the balls!\n");
  say("Cyclop kicks "+ob->query_name()+" between his legs!\n", ob);
  ob->hit_with_spell(200);
}
