inherit "room/room";
object monster;

reset(arg) {
  if(!present("iceman")) { 
    move_object(clone_object("/wizards/irmeli/nyx/monsters/iceman"),
    this_object());
 }

 if (arg) { return; }

set_not_out(1);

  add_exit("west", "/wizards/irmeli/nyx/cavern");

  short_desc = "An ice-cavern inside the volcano";
  long_desc = "The east wing of the ancient ice-cavern inside the volcano. Everything is\n"+
              "covered with ice, the ground, the walls and the ceiling. The ground is\n"+
              "slippery and rough. Some icicles are hanging down from the ceiling, just\n"+
              "aboce your head. The biting coldness is intolerable.\n";
}
