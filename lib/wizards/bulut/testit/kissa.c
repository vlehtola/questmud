inherit "obj/door";

reset(arg) {
  if(arg) { return; }
  set_dir("cs");
  set_code(191);
  set_type("iron");
  set_door("wizards/bulut/testit/kissa");
  set_closed(1);
  set_locked(1);
  set_can_lock(1);
  set_door_long("Son tota.. doori.. blokkailee.\n");
}
