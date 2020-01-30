#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

extra_reset() {
  set_not_out(1);
  items = allocate(8);
  items[0] = "pentagram";
  items[1] = "The pentagram is carved into stone. There are some runes next to it";
  items[2] = "runes";
  items[3] = "The runes say:\n"+
	"	The brave can enter the circle,\n"+
	"	but easily will brave be fool.\n"+
	"	Only wise can make the miracle\n"+
	"	and survive the challenge of pool";
  items[4] = "floor";
  items[5] = "As you concentrate more closely on the floor, you discover an old yellow paper";
  items[6] = "paper";
  items[7] = "You don't dare to try to move or take it, it could break so easily.\n"+
	"You read from the paper:\n"+
	"	Sinrad's log 23th day in Dark year\n"+
	"	  I have found the secret of the portal. It took me 2 days to reveal hidden\n"+
	"	runes, which are told to explain the meaning of the pentagram. Now I now\n"+
	"	what is behind the portal: there are two ways.\n"+
	"	  One way will lead to a maze which was made by Chogalm the Archmage.\n"+
	"	It is told that one must survive a huge maze where hot vapours boil\n"+
	"	everything. The maze is huge and magical, the exits change randomly.\n"+
	"	I know that the entrace to Chogalm's keep lies at the same place always.\n"+
	"	The maze has three axes (x,y,z). I still don't know the exact coordinates\n"+
	"	that I could relocate the location. Still I am going in.\n"+
	"	  The second way is h.a,..\n\n"+
	"The rest of the paper is torn apart";
}

init() {
  ::init();
  add_action("enter", "enter");
}

enter(str) {
  if(str != "pentagram") return;
  /*
  if(!this_player()->query_wiz() && !this_player()->query_tester()) {
    write("Area is under construction..have patience.\n");
    return 1;
  }
  */
  tell_room(this_object(), this_player()->query_name()+" enters the pentagram and is gone.\n");
  move_object(this_player(), "/wizards/celtron/maze/necro/1");
  tell_object(this_player(), "You have a feeling that something went wrong..\n");
  return 1;
}

ONE_EXIT(  "/wizards/celtron/maze/spider7", "south",
	   "A large hall",
	   "The tunnel ends to a large hall. Eternal torches light the surrounding area.\n" +
	   "Hall's walls, ceiling and floor are all smooth stone.\n" +
	   "There is some kind of pentagram on the northeast corner's floor.\n"+
	   "The light fades into the darkness of the cave in south.\n", 3)
