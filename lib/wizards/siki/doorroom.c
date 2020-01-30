inherit "/room/room";
inherit "/room/door";

init() {
   ::init();
   door_init();
}

reset(arg) {
  if (arg) return;
  door_reset();
  set_door_dir("north", "/wizards/siki/doorintoinenpuoliruumi.c", 1);
  set_door_link("/wizards/siki/doorintoinenpuoliruumi.c", 1);
  set_door_label("da'door", 1);
  set_door_code("015", 1);
  set_locked(1, 1);

  add_exit("west", "world/city/wood4");
  add_exit("east", "world/city/wood6");
  short_desc = "On the central part of Wood street";
  long_desc = "hc long desc, dooriroomi for sikipeelo, set_door_code on
lukon koodi, avaimen koodin pitaa matchaa, muuten ei aukee. Tee toinen 
samanlainen huone johon pistat door_link taman huoneen ja door dirriks 
sitte varmaankin south ja tahan huoneeseen. Ykkonen joka funkassa on
etta huoneen eka doori, etta voi olla enemmanki dooreja huoneessa.\n";

  set_light(3);
}


