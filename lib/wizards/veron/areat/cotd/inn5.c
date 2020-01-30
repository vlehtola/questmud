inherit "room/room";


object monster;



reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }
set_not_out(1);

if(arg) return;

add_exit("west","/wizards/veron/areat/cotd/inn3.c");


  short_desc = "Guestroom";

  long_desc = "A luxurios guestroom of the inn. There's a huge fluffy bed in\n"+
              "the middle of the room with a mosquito net over it. A rotting\n"+
	      "corpse clad in colorful clothes lies in the bed. A huge window\n"+
              "in the east has fallen off to the backyard of the inn. In the\n"+
              "north, hanging on the wall, is a large and colorful picture of\n"+
              "a grumpy-looking old woman.\n";
 
             set_not_out(1); 
              

  items = allocate(8);
  items[0] = "bed";
  items[1] = "A huge luxurious bed with a mosquito net hung over it. There's a corpse in the bed";
  items[2] = "net";
  items[3] = "A mosquito net hung over the bed";
  items[4] = "corpse";
  items[5] = "A corpse of and old-looking woman clad in colorful clothes";
  items[6] = "picture";
  items[7] = "A picture of a grumpy-looking old woman looks just like the woman lying in the bed";

  }





