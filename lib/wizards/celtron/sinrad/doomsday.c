inherit "obj/weapon";

start() {
  set_class(12);
  set_stats("hit",10);
  set_desc("polished");
  set_sub_type("long sword");
}
/*
hit() {
  if(random(8) != 0) return;
  tell_room(environment(wielded_by), "Doomsday seems to warm up a bit.\n");
  if(query_wc() < 120) {
    set_wc(query_wc()+2);
  }
}
*/
