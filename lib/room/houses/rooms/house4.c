inherit "/room/house_d";
inherit "/room/room";
inherit "/room/door";

#define HOUSE_NUMBER 4
#define EXIT_FILE "/world/city/silver6"
#define EXIT_DIR "east"

#define SAVE_FILE "/room/houses/data/house"+HOUSE_NUMBER

query_save_file() {
  return SAVE_FILE;
}

reset(arg) {
  if (arg) return;
  set_save_file(SAVE_FILE);
  short_desc =
call_other("/room/houses/house_descs", "get_short", HOUSE_NUMBER);
  long_desc =
call_other("/room/houses/house_descs", "get_long", HOUSE_NUMBER);
  set_light(3);
  door_reset();
  set_door_dir(EXIT_DIR, EXIT_FILE,HOUSE_NUMBER);
  set_door_link(EXIT_FILE,HOUSE_NUMBER);
  set_locked(1, HOUSE_NUMBER);

property = allocate(2);
property[0] = "no_kill";
property[1] = "no_summon";

}

init() {
  ::init();
  add_action("put_eq", "store");
  add_action("withdraw_eq", "withdraw");
  add_action("list_eq", "list");
  door_init();
  set_last_visited();
}

list_eq() {
  list_locker();
  return 1;
}

put_eq(string str) {
  int slot;
  string nam;
  if(!str) {
    write("## Usage : Store [EQ] to [NUMBER]\n");
    return 1;
  }
  if(sscanf(str, "%s to %d", nam, slot) != 2) {
    write("## Usage : Store [EQ] to [NUMBER]\n");
    return 1;
  }
  store_eq(nam,slot);
  return 1;
}

withdraw_eq(string str) {
  if(!str) {
  write("## Usage : Withdraw [NUMBER]\n");
    return 1;
  }
  get_eq(to_int(str));
  return 1;
}


