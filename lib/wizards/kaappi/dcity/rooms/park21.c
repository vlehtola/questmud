inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu20.c");
  add_exit("east", "park22.c");
  add_exit("west", "park20.c");
  add_exit("north", "park18.c");
  add_exit("northeast", "park19.c");
  add_exit("northwest", "park17.c");
short_desc = "A park";
long_desc = "As you step inside from the gate, you are amazed\n"+
            "from the beauty of the park. A park inside a cave?\n"+
            "This must be made by using some kind of magic. The trees\n"+
            "and bushes are growing straight from the rock. A beautiful\n"+
            "green grass covers the ground. Some most commonly used paths\n"+
            "can clearly be seen on the ground.\n";
  set_light(3);
}
