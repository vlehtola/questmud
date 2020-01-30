inherit "room/room";
object monster;
 
reset(arg) {
   if(!monster) {
    monster = clone_object("/wizards/grathlek/area4/monsies/famu.c");
    move_object(monster, this_object());
   }
  add_exit("southwest","/wizards/grathlek/area4/mroom10.c");
  add_exit("east","/wizards/grathlek/area4/croom8.c");
  set_light(2);
 
  short_desc = "A rocky path leading to southwest.";
  long_desc = "Red light glows everywhere in the\n"+
              "tunnel and it creates creepy shadows\n"+
              "like demons on the walls. Some strange\n"+
              "looking rocks are on the ground.\n";

items = allocate(4);
  items[0] = "rock";
  items[1] = "The rock looks heavy";

}

init() {
  ::init();
  add_action("push", "push");
  add_action("pull", "pull");
}

push(str) {
  object ob;
  if(str == "rock") {
    write("You push the rock aside.\n");
    this_player()->set_quest("pushrock", 1);
    add_exit("hole","/wizards/grathlek/area4/sroom1.c");
    return 1;
    }
  write("Push what?\n");
  return 1;
}

pull(str) {
  if(str == "rock") {
    write("You pull the rock back to cover exit to small hole.");
    remove_exit("hole");
    return 1;
    }
  write("Pull what?");  
  return 1;
}

 
