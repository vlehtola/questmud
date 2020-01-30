inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("east","/wizards/veron/areat/cotd/bs1.c");

  short_desc = "Blacksmithy";

  long_desc = "This room is the heart of the blacksmithy where the blacksmith\n"+
              "works. A large forge is located in the corner of the room, with a\n"+
	      "chimney over it. The forge doesn't have any fire in it, but a thick\n"+
              "layer of dust covers it and the whole room. Old bellows lie in the\n"+
              "ground near the forge. A large wooden box full of unfinished armours\n"+
              "and tools is placed in the right side of the forge. There's also an\n"+
	      "anvil near the forge. It's bolted to the floor.\n";
            
                set_not_out(1);

  items = allocate(10);
  items[0] = "forge";
  items[1] = "A large forge is built to the corner of the room. It hasn't been used for a\n"+
	     "while and has a layer of dust on it. There's a chimney over it";
  items[2] = "chimney";
  items[3] = "The chimney made of bricks is made for keeping the smoke out of here";
  items[4] = "bellows";
  items[5] = "The old and fragile-looking bellows are used to help lighting up the forge";
  items[6] = "box";
  items[7] = "A large wooden box full of unfinished, bumpy armours and tools. The blacksmith\n"+
             "hasn't been working on these for a long time";
  items[8] = "anvil";
  items[9] = "A very heavy anvil is placed near the forge. The blacksmith uses anvil to shape\n"+
             "the metal after it's beed softened in the forge.";
 
 	
  }
