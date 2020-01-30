inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("down","/wizards/luminarc/wizcastle/upwest2");
  short_desc = "Kitchen";
  long_desc = "This is kitchen of the castle. A huge owen has been built in the\n"+
              "corner of the room. Some sweet aroma is coming from there. The table\n"+ 
              "in the middle of the room contains forks, knives, kettles and other\n"+ 
              "cooking stuff. It is very hot in here.\n";
  property = allocate(1);
  set_light(3);
  items=allocate(3);
  items[0]="owen";
  items[1]="There is something deligious cooking in owen.";
  ob = clone_object("/wizards/luminarc/wizcastle/humans/cook.c");
  move_object(ob, this_object());

}

