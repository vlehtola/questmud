#include "room.h"
#define LOCKER_D "/room/locker_d"
#define COST	(this_player()->query_level()/2)

ONE_EXIT("/world/city/ice4", "south",
	"Locker room",
	"This is the locker room. You can store your eq here.\n" +
        "Available commands are:\n" +
	"     cost\n" +
        "     list\n" +
        "     store [item] to [slot]\n" +
        "     withdraw [slot]\n",3)

void init() {
  ::init();
add_action("put_eq", "store");
add_action("get_eq", "withdraw");
add_action("list_eq", "list");
add_action("show_cost", "cost");
}

show_cost() {
  write("The storage of one item costs "+COST+" bronzes.\n");
  return 1;
}

list_eq() {
 LOCKER_D -> list_locker();
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
 if(this_player()->query_money(3) < COST) {
   write("You need "+COST+" bronze coins.\n");
   return 1;
 }
 if(LOCKER_D -> store_eq(nam,slot) == 2) { /* Elikka store onnistui.. */
   this_player()->reduce_money(COST,3);
 }
 return 1;
}

get_eq(string str) {
  if(!str) {
  write("## Usage : Withdraw [NUMBER]\n");
    return 1;
}
 LOCKER_D -> get_eq(to_int(str));
return 1;
}


