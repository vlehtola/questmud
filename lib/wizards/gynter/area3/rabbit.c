inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(15+i*10);
  set_name("rabbit");
  set_short("A small cuddly rabbit");
  set_long("This rabbit is just hopping along, trying not to get\ntoo much dirt on his white furr.\n");
  set_gender(1);
  if(i==0) {
    set_exp(query_exp()*3/2);
  }
}

