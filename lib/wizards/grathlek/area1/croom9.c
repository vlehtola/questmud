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
    add_exit("hole","/wizards/grathlek/area4/sroom1.c");
    return 1;
    }
  write("The rock is allready out of your way.\n");
  return 1;
}

pull(str) {
  object ob;
  if(str == "rock) {
    write("You pull the rock back to cover the exit to small hole.\n");
    remove_exit("hole","/wizards/grathlek/area4/sroom1.c");
    return 1;
    }
  write("The rock is allready covering the hole.");  
  return 1;
}

 
