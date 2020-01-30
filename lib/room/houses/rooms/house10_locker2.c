inherit "/room/house_d";
inherit "/room/room";

#define HOUSE_NUMBER 10

#define SAVE_FILE "/room/houses/data/house"+HOUSE_NUMBER+"_2"

query_save_file() {
  return SAVE_FILE;
}

reset(arg) {
  if (arg) return;
  set_save_file(SAVE_FILE);
  short_desc =
"Southern store room";
  long_desc =
"You are in the southern store room. There are drawers to store equipment.\n"+
call_other("/room/houses/house_descs.c","get_long", HOUSE_NUMBER);

  add_exit("north", "/room/houses/rooms/house10_floor2");

  set_not_out(1);
  set_light(3);

property = allocate(2);
property[0] = "no_kill";
property[1] = "no_summon";
}

init() {
  ::init();
  add_action("put_eq", "store");
  add_action("withdraw_eq", "withdraw");
  add_action("list_eq", "list");
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


