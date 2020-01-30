inherit "obj/monster";

reset(arg) {
	  int i;
  ::reset(arg);
  if(arg) { return; }

  i = random(2);
  set_level(35+i*5);
  set_name("granite giant");
  set_alias("giant");
  set_short("A granite giant");
  set_long("This is the biggest and most feared warrion in the earth realm.\n"+
           "It is almost 25ft tall and it's arm's is like a big tree each.\n"+
           "It has one diamond at each knuckle and they are sharpened to perfection.\n");
  set_al(0);
  set_aggressive(0);

}
