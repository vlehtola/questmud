inherit "room/room";

reset(arg) {
  if(arg) return;
 
  add_exit("cs","/world/city/cs");
  add_exit("post","/world/city/post.c");
  short_desc = "Thelon's room";
  long_desc = "This is Thelon's workroom. In the corner of the room \n" +
              "you see a chest made of metal (closed). \n";

  property = allocate(1);
  property[0] = "no_summon";

  items = allocate(2);
  items[0] = "chest";
  items[1] = "The chest is closed";

set_light(3);

}

init() {
  ::init();
  add_action("open", "open");
 }

open(str) {
object ob;
  if(str == "chest") {
    write("As you begin opening the chest you hear a huge BANG!.. OUCH!! \n");
 tell_room("wizards/thelon/workroom",""+this_player()->query_name()+" is trying to open Thelon's chest and suffers!!\n");
this_player()->reduce_hp(50);
}
     return 1;
}
