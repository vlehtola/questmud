inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("out","/wizards/veron/areat/cotd/street2.c");
add_exit("east","/wizards/veron/areat/cotd/inn2.c");
add_exit("stairs","/wizards/veron/areat/cotd/inn3.c");

  short_desc = "The Boulder inn";

  long_desc = "The Boulder inn has been a first place for foreigners to visit in\n"+
              "this town. This is the entrance hall of the inn. A huge desk with\n"+
	      "a small bell on it is in the opposite of the door. There's a large\n"+
              "safe with it's door open is embedded to the wall behind the desk.\n"+
              "Colorful curtains full of holes prevent sunlight coming in. A thick\n"+
              "layer of dust covers all planes in the hall. There's also a skeleton\n"+
	      "of a small mammal in front of the desk. The hall continues to the\n"+
              "east and there's a staircase leading upstairs in the northeastern\n"+
	      "corner.\n";

            


  set_not_out(1);
  items = allocate(10);
  items[0] = "desk";
  items[1] = "A large oaken desk with a small bell on it";
  items[2] = "bell";
  items[3] = "A small bell meant for waking up the receptionist";
  items[4] = "safe";
  items[5] = "A large metallic safe which has been embedded to the wall behind the large desk.\n"+
             "The safe's door is open showing some keys inside it";
  items[6] = "curtains";
  items[7] = "These curtains have been colorful but have faded in the direct sunlight. They're\n"+
             "also full of holes";
  items[8] = "skeleton";
  items[9] = "Remains of a small mammal, a dog or a cat perhaps. It's head has been severed";
 
}
init() {
  ::init();
  add_action("hep", "ring");
  
 }

hep(str) {
    
    if(str == "bell") {
  
    write("You ring the bell and it makes a tinkling sound. Clingg!\n");
          
    say(this_player()->query_name() + " rings the bell and it makes a tinkling sound. Clingg!\n");
 
return 1;

}

 else { 
 write("Ring what?\n");
return 1;
}
}
