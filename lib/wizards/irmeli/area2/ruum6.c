inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit8"),
    this_object());
  }  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum4.c");
  set_not_out(1);
  
  short_desc = "A deep mine shaft leading down to lower levels";
  long_desc = "This mine gallery is bigger than the ones before. The gallery is the furthest\n"+
              "room in the first level. It's bigger because this was the room where the blast\n"+
              "stones pulled up from the lower levels. A deep mine shaft begins from here,\n"+   
              "leading down to the lower levels. There is a rusty winch on the eastern wall.\n";

  items = allocate(2);
  items[0] = "winch";
  items[1] = "Formely this winch was helpful to the miners to lift the goods from the lower levels. It is covered with rust";

  call_other("wizards/irmeli/area2/hissi", "start_elevator", 1);
}

