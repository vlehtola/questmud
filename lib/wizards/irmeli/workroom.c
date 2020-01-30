inherit "room/room";



reset(arg) {

  add_exit("inn","/world/city/inn");

  add_exit("cs","/world/city/cs");

  add_exit("forest","/wizards/irmeli/bwp/entrance.c");

  add_exit("mines","/wizards/irmeli/area2/entrance.c");

  add_exit("ent","/wizards/irmeli/ent/entrance.c");

  add_exit("castle","/wizards/irmeli/castle/entrance.c");

  short_desc = "The men's room of h2o";

  long_desc = "The men's room of h2o opens in front your eyes. There are couple sexy men\n"+

                "behind you disquised as a woman. It makes you wonder what kind place this\n"+

                "is. Oh no this is the famous gay place, where everything is possible.\n"; 



  property = allocate(2);

  property[0] = "no_summon";

  property[1] = "no_tele";
}







