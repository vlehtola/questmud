inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(40+i*4);
  set_name("troll");
  set_short("A non-cuddly troll");
  set_long("A troll sits hear eating on some stone\nIt looks like it doesn't want to be disturbed.\n");
  set_gender(1);
  if (i==0) {
    set_short("A beauti.. A female troll");
    set_long("A female troll stands hear rubbing her skin with\nstone so it will get even more beautiful.\n");
    set_gender(2);
    set_exp(query_exp()+(query_exp()/100));
  }
}

