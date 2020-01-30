inherit "room/room";

// loc changed by C 25.05.04
#define OUT	"outmap: 185 69"

reset(arg) {


  add_exit("north",OUT);
  add_exit("east",OUT);
  add_exit("south",OUT);
  add_exit("west",OUT);
  add_exit("enter","/wizards/siki/lizard/room1");

  short_desc = "Entrance to a small village";
  long_desc = "A entrance to a small and quiet village. The ground is\n"+
              "tough and a small path has been formed in the past years.\n"+
              "there are no trees or anything else growing anywhere near.\n";

}
