inherit "room/room";

reset(arg) {
  if(arg) return;
  set_not_out(1);
  set_light(3);
  property = allocate(1);
  property[0] = "no_summon";
  short_desc = "temporary guardroom";
  long_desc = "This is temporary guardroom for castleshop. There is nothing to see yet, come back later.\n -- Archsin\n";
  add_exit("west", "/world/city/gold2.c");
  add_exit("east", "/castle/obj/castle_shop");
  move_object(clone_object("/wizards/archsin/pet/chaos"), this_object());
}
