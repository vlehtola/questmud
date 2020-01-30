inherit "obj/door";

reset(arg) {
  if(arg) { return; }
set_dir("south");
  set_code(191);
  set_type("wood");
  set_door("wizards/bulut/forl/door.c");
  set_closed(1);
  set_locked(1);
  set_can_lock(1);
  set_door_long("A sturdy looking door.\n"
                "You wonder why it is locked.\n");
}
