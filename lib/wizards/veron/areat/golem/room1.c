inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("mansion","/wizards/veron/areat/golem/room2.c");
add_exit("plains","outmap: 24 113");

  short_desc = "A big mansion";

  long_desc = "A huge mansion towers in front of you. It's walls are decorated\n"+
              "with small statues and carvings. The mansions windows are also\n"+
		  "colorful and decorated with pictures of flowers and such.\n"+
              "There's a small garden with plenty of flowers in front of the\n"+
		  "building. The mansion is surrounded by a three-feet high\n"+
	        "stone wall. There's an iron gate in the wall, but it is left\n"+
              "open. A single milk jug is in front of the gate.\n"; 	

  items = allocate(8);
  items[0] = "gate";
  items[1] = "The gate is made of iron and looks durable";
  items[2] = "statues";
  items[3] = "Small gargoyle statues. There statues are an excellent piece of handi-\n"+
 		 "craft"; 
  items[4] = "carvings";
  items[5] = "Some decorative carvings";
  items[6] = "jug";
  items[7] = "A jug full of fresh milk. The milkman's been here recently";
		
  }
