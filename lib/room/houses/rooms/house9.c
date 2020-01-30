inherit "/room/house_d";
inherit "/room/room";
inherit "/room/door";

#define HOUSE_NUMBER 9
#define EXIT_FILE "/world/city/emerald9"
#define EXIT_DIR "west"

reset(arg) {
  if (arg) { return; }
  set_not_out(1);
  set_light(3);

  add_exit("south", "/room/houses/rooms/house9_bedroom");
  add_exit("up", "/room/houses/rooms/house9_floor2");

  short_desc = "A large living room";
  long_desc =
"You are in a large living room. There is a large burning fireplace in the\n"+
"corner of this large comfortable room. There is a wooden stairway leading up.\n";

  door_reset();
  set_door_dir(EXIT_DIR, EXIT_FILE,HOUSE_NUMBER);
  set_door_link(EXIT_FILE,HOUSE_NUMBER);
  set_locked(1, HOUSE_NUMBER);

property = allocate(2);
property[0] = "no_kill";
property[1] = "no_summon";

  call_out("tick", 30);
}

init() {
  ::init();
  set_last_visited();
  door_init();
}

tick() {
  object ob;
  int i, heal;
  heal = call_other("/room/houses/house_descs", "get_fireplace_heal")*5;
  tell_room(this_object(), "The fireplace warms you comfortably.\n");
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]&&living(ob[i])) {
        ob[i]->add_hp(heal);
        ob[i]->add_sp(heal);
        ob[i]->add_ep(heal);
    }
    i += 1;
  }
  call_out("tick", 30);
}
