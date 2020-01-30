inherit "obj/weapon";

start() {
  set_class(6);
  set_sub_type("dagger");
  set_name("stiletto");
  set_short("Silvered stiletto with red carvings");
  set_long("In a small skin-covered handle, there seems to be a small button from which the\n" + 
           "blade of the stiletto can be revealed. The blade is shiny, thin and very sharp.\n" + 
           "Stilettos are widely used by thieves all around the realm of Deleria. There is\n" + 
           "various kinds of stilettos, but this is definitely one of the finest you have\n" + 
           "ever seen. In the base, or the handle, of the stiletto there is carvings which\n" + 
           "have been later painted in red. They really make a great decoration. After a\n" + 
           "while you notice that those carvings are actually human-made runes.\n");
}

init() {
  ::init();
  add_action("push", "push");
}

push(str) {
  if(str == "button") {
  write("You don't have to push the button because the blade is already revealed.\n");
  return 1;
  }
}
  
