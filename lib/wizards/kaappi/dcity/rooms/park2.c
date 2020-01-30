inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu18.c");
  add_exit("west", "park1.c");
  add_exit("east", "park3.c");
  add_exit("northwest", "park4.c");
  add_exit("north", "park5.c");
  add_exit("northeast", "park6.c");
short_desc = "A park";
long_desc = "As you step inside the gate, you are amazed by the beauty\n"+
            "of the park. A park inside a cave, this must be made by using\n"+
            "some kind of magic. Trees and bushes are growing out straight\n"+
            "from the rock. A beautiful green grass covers the ground. Some\n"+
            "most commonly used paths can clearly be seen on the ground.\n";
  set_light(3);
}
