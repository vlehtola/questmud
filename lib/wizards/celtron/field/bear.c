inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(14+i*2);
  set_name("bear");
  set_short("A brown bear");
  if(i==1) set_short("A black bear");
  set_long("The bear doesn't look very dangerous, but it would be wise not\n"+
	   "to bother it. It seems to be eating some berries that grow on the\n"+
	   "low bushes that cover the ground.\n");
  set_gender(random(2)+1);
  set_animal(1);
}
