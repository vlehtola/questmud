inherit "room/room";
init() {
  ::init();
  add_action("dig", "dig");
}
object ob;
status i;
reset(arg) {
if(arg) return;
 
short_desc = "Inside the tomb";
long_desc =  "The tomb is beautifully decorated with golden statues and\n"+
             "picture of sailors. A large coffin lays on the center of\n"+
             "tomb and the lid is broken, what have been inside the coffin\n"+
             "is now robbed and all the expensive items are gone. Looks like\n"+
             "some one is moving behind the coffin and mumbling something.\n";
        add_exit("out", "room3");
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out();
        set_light(1);
      
}
 


dig(str) {
  if(!i || str == "ground") {
  write("jee jee ton ttu mies!\n");
  say(this_player()->query_name()+ " founds something.\n");
  ob = clone_object("/wizards/walla/jericho/mobs/ng1");
  move_object(ob,this_object());
  this_player()->attack_object(ob);
  i = 1;
  return 1;
    }
  write("You find nothing special.\n");
  say(this_player()->query_name()+ " founds nothing.\n");
  return 1;
}
