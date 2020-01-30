inherit "room/room";

reset(arg) {
  if(arg) return;

  set_not_out(1);
  set_light(3);
  property = allocate(1);
  property[0] = "no_summon";
  short_desc = "Castleshop";
  long_desc = "The Castleshop. Desc coming.\n";
  add_exit("west", "/castle/obj/shop_entrance.c");
  move_object(clone_object("/castle/obj/shopkeeper"), this_object());
  move_object(clone_object("/world/objects/trashcan"), this_object());
}