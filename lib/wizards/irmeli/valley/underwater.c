inherit "room/room";
object monster;

reset(arg) {
  if(!present("caveman")) { 
    move_object(clone_object("/wizards/irmeli/valley/monsters/caveman"),
    this_object());
 }

 if (arg) { return; }

 set_not_out(1);

 short_desc = "An underwater chamber";
 long_desc = "An underwater chamber has been drived deep inside the mountain. The water\n"+
             "level is high in the chamber. A small jut of land is above the water level.\n"+
             "The translucid water flows here and there, making billowy move, without any\n"+
             "destination.\n";

    add_exit("west", "/wizards/irmeli/valley/chamber2.c");

  items = allocate(2);
  items[0] = "hole";
  items[1] = "A huge hole, made in the western wall, can be seen under the water level";

  property = allocate(3);
  property[0] = "no_spell";
  property[1] = "no_skill";
  property[2] = "no_kill";
}
