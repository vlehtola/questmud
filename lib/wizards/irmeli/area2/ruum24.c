inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit6.c"),
    this_object());
}  

  if(arg) return;

  add_exit("east","/wizards/irmeli/area2/ruum23.c");
  set_not_out(1);
  
  short_desc = "Rest room in bottom level";
  long_desc = "This is a small rest room for miners. Miners have build this room so\n"+
                "quickly that the walls are rough and sharp. There is a few chairs\n"+
                "and small table in the middle of room.\n";   
  
  items = allocate(4);
  items[0] = "table";
  items[1] = "A small table made for 4 persons. It has lost most of it's paint and it is falling apart"; 
  items[2] = "chairs";
  items[3] = "Four chairs around the table. Chairs are made from old wood"; }

