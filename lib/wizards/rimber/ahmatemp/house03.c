inherit "room/room";
object monster01;
int task;

reset(arg) {
  short_desc = "In a crubby-looking shack";
  long_desc = "This apartment looks horrible and you cannot think how anyone could live\n" + 
              "in this kind of a shack. The ceiling is full of holes, making the living\n" + 
              "in the shack very uncomfortable during the rainy seasons. Some holes can\n" + 
              "also be found in the walls, which are also in very bad condition. Some\n" + 
              "rubbish is lying in the one corner of the shack and a dead animal in other.\n";

  items = allocate(6);
  items[0] = "rubbish";
  items[1] = "A pile of rubbish is lying in the northeastern corner of the shack. The\n" + 
             "rubbish must have been collected from the sides of the streets. You quickly\n" + 
             "glance through the pile but do not find anything suitable for your purposes";
  items[2] = "animal";
  items[3] = "As examining more carefully at the corpse, you end up to a conclusion\n" + 
             "that this corpse once was a lively deer of the forest surrounding this\n" +
             "village. Someone has already started to dine with it, though it is as\n" + 
             "rare as when it was captured and killed. The thought gives you chills";
  items[4] = "corpse";
  items[5] = "As examining more carefully to the corpse, you end up to a conclusion\n" + 
             "that this corpse once was a lively deer of the forest surrounding this\n" +
             "village. Someone has already started to dine with it, though it is as\n" + 
             "rare as when it was captured and killed. The thought gives you chills";
  if(!monster01) {
    move_object(monster01 = clone_object("/wizards/ahma/orc/mob/bum01"), this_object());
    if(task) { present("bum", this_object())->task_complete(); }
  }
}

task_complete() {
  task = 1;
}
