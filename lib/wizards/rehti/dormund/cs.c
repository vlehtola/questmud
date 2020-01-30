inherit "room/room";
object monster;

reset(arg) {
  add_exit("east","/wizards/rehti/dormund/e");
  add_exit("north","/wizards/rehti/dormund/castleent");
  add_exit("west","/wizards/rehti/dormund/w");  
  add_exit("south","/wizards/rehti/dormund/city");
  short_desc = "Central square of inner city";
  long_desc = "This is the central square. There is a large fountain in the middle of\n" +
              "the square. There are flowers growing in flowerbeds and they smell good.\n" + 
              "This is certainly best place of the city since there are no walls and it\n" +
              "is nice and calm here. Castle entrance is to the north from here.\n";
  items = allocate(4);
  items[0] = "fountain";
  items[1] = "It is big ordinary fountain and water is pure and glitters nicely.";
  if(!present("man")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/man1"), this_object());
  if(arg) { return; }
}
  if(!present("woman")) {
  move_object(clone_object("/wizards/rehti/dormund/monsut/woman1"), this_object());
  if(arg) { return; }
}
}