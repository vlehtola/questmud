inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 1")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit4.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum22.c");
  add_exit("south","/wizards/irmeli/area2/ruum20.c");
  set_not_out(1);
  
  short_desc = "Big kitchen";
  long_desc = "This is the kitchen where chefs prepairs the food for miners. A terrible\n"+
                "smell is coming from the big pot. There is a small helpdesk for\n"+
                "the chefs next to the big pot.\n";   
  
  items = allocate(4);
  items[0] = "helpdesk";
  items[1] = "A small helpdesk is made from wood. Chefs use it lay for chopping food"; 
  items[2] = "pot";
  items[3] = "A big pot where chefs cook their foods. It is covered with rust and old food"; }

