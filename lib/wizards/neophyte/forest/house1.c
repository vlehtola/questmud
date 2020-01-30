inherit "room/room";
inherit "room/door";
object man;

reset(arg) {
  if (arg) { return; }
        short_desc = "In the house";
        long_desc = "You have arrived in somekind of fishing house.\n"+
                    "There's a little fireplace on the center of the room, and there\n"+
                    "is nice fire in it. Lots of different fishing equipments \n"+
                    "nets, poles and such things are hanging on the wall. Strong smell\n"+
                    "of fishes is floating here.\n";
     set_not_out(3);
             items = allocate(4);
                items[0] = "fireplace";
                items[1] = "It has little fire in it which lights the whole room";
                items[2] = "nets";
                items[3] = "They look like typical fishing nets but are full of different trashes";

  door_reset();

  set_door_label("wooden door", 1);
  set_door_dir("north", "/wizards/neophyte/forest/room13", 1);
  set_door_link("/wizards/neophyte/forest/room13", 1);
  set_door_code(700, 1);
  set_locked(0, 1);
      man = clone_object("/wizards/neophyte/forest/monst/man");
        move_object(man, this_object());

}

init() {
  ::init();
  door_init();
}
