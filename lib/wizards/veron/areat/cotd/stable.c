inherit "room/room";



object monster,monster2;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/horse");
    move_object(monster, this_object());
  }
  if(!monster2) {
    monster2 = clone_object("/wizards/veron/areat/cotd/mobs/horse");
    move_object(monster2, this_object());
}

add_exit("out","/wizards/veron/areat/cotd/street3.c");


  short_desc = "Stables";

  long_desc = "The stables is a large wooden building, perhaps an old warehouse.\n"+
              "The strong twirly wind has brought in lots of sand from the plains.\n"+
	      "Four stalls are built on the western part of the building. There's\n"+
	      "dried manure all over the stalls. The walls and the doors of the stalls\n"+
	      "are all bitten and have deep bumps in them. The horses' names are written\n"+
              "in the stall doors. The stench of rotting hay floats in the hall.\n"+
	      "Miscellaneous riding equipment is scattered around the hall. Dusty-\n"+
	      "looking saddles and helmets hang from hooks in the eastern wall.\n";
	   
	     
       set_not_out(1);         

  items = allocate(14);
  items[0] = "stall";
  items[1] = "Four wooden stalls with lots of manure in them. The walls and doors are badly bitten";
  items[2] = "manure";
  items[3] = "The manure is splattered all over the stalls";
  items[4] = "bumps";
  items[5] = "Some deep bumps in the stall doors. The horses have probably kicked the doors";
  items[6] = "names";
  items[7] = "Only two of the stalls have names in them: 'Robin Good' and 'Hero'";
  items[8] = "equipment";
  items[9] = "Some miscellaneous riding equipment: saddles, helmets, lashes, headstalls etc";
  items[10] = "saddles";
  items[11] = "Dusty and worn saddles hanging from the hooks in the eastern wall";
  items[12] = "helmets";
  items[13] = "Dusty helmets hang from the hooks in the eastern wall";

 	
  }
