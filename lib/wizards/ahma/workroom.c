inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/ahma/test/ahmud");
    move_object(monster, this_object());
  }
  if(!present("sculpture")) move_object(clone_object("/wizards/ahma/misc/sculpture.c"), this_object());


  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("post", "/world/city/post");
  add_exit("demon", PATH() + "castle/rooms/area01");
  add_exit("orc", PATH() + "orc/forest/for01");
  add_exit("ice", PATH() + "ice/rooms/101");
  add_exit("east", "/wizards/ahma/misc/newroom.c");
  short_desc = "Ahma's corner";
  long_desc = "This is Ahma's very own workroom with some nasty-looking toys\nlying in the corners of the room.\n"; 

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";

}
