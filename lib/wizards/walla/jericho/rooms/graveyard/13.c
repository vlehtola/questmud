inherit "room/room";
init() {
  ::init();
  add_action("dig", "dig");
}
object ob;
status i;
reset(arg) {
if(arg) return;
 
short_desc = "A foggy cemetary";
long_desc =  "You are standing in a cemetary. The ground is covered with daffodils.\n" +
             "It seems that many people have been buried here recently, since the \n" +
             "ground has been recently turned.\n";
        add_exit("west", "12");
        add_exit("north", "23");
        add_exit("east", "14");
        add_exit("northeast", "24");
        add_exit("northwest", "22");
        property = allocate(1);
        property[0] = "no_summon";
        set_light(1);
}
 
dig(str) {
  if(!i && str == "ground") {
  write("You dig the ground, and find a corpse!\n");
  say(this_player()->query_name()+ " digs the ground and finds a corpse.\n");
  ob = clone_object("/wizards/walla/jericho/mobs/ghost");
  move_object(ob,this_object());
  this_player()->attack_object(ob);
  i = 1;
  return 1;
    }
  write("You find nothing special.\n");
  say(this_player()->query_name()+ " finds nothing.\n");
  return 1;
}
 

