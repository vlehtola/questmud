inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum6.c");
  add_exit("south","/wizards/irmeli/area2/ruum3.c");
  add_exit("west","/wizards/irmeli/area2/ruum5.c"); 
  set_not_out(1);
  
  short_desc = "A mine gallery leading deeper into the ground";
  long_desc = "The mine gallery is turning deeper into the ground. The ground is full of\n"+
                "small, sharp stones from the inner parts of the mine. There are old trails\n"+
                "leading forward into the mine. The blast stones were transported from the mine\n"+
                "with wagon trails. There is a wagon on the trails.\n";

  items = allocate(2);
  items[0] = "wagon";
  items[1] = "Rusty mine wagon has been here a long time. Earlier it was helpful to the miners. Nowadays it's so old that it would break, if you try to get on it"; }


