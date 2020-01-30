inherit "/room/house_d";
inherit "/room/room";

#define CASTLE "BMC"

#define SAVE_FILE "/castle/save/"+CASTLE+"store_1"

query_save_file() {
  return SAVE_FILE;
}

reset(arg) {
  if (arg) return;
  set_save_file(SAVE_FILE);
  short_desc = "Inside of the HUGE Black Marble Castle at the storeroom";
  long_desc =
"The walls are very interesting as it's marble shines with bright dark\n"+
"light, it surely has some spells on it as it sizzles with magic. The\n"+
"letters are some old runes that only some very high archmage could \n"+
"recognize and even then, it may remain as mystery how it has been done\n"+
"and how it shall go on. The only thing you notice, is that the place seems\n"+
"to be an old building as it's architech view and in general view it looks like\n"+
"it would have appeared in a puff of smoke just few minutes ago.\n"+
"Suddenly words: 'store, withdraw and list' appears on one of the walls,\n"+
"there must be some dark magic inside the castle as the letters start to\n"+
"actually haunt you all over the place giving you no place to run!\n";
  add_exit("south", "/wizards/gheldor/workroom");

  set_not_out(1);
  set_light(3);
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
