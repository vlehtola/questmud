int open;

reset(arg) {
 open = 0;
        if(arg) return;
}
id(str) {
        return str == "box";
}
init() {
        add_action("push", "push");
        add_action("take", "take");
        add_action("take", "get");
}
push(str) {
        if(str == "hemisphere") {
  write("The cover swings open with amazing speed as you push the hemisphere.\n");
 open = 1;
        return 1;
        }
return 0;
}
take(str) {
 object paper;
 paper = clone_object("/wizards/rimber/cave/obj/info.c");
        if(open == 1) {
         if(str == "all from box") {
 write("You empty the box and all you find is a stone and a piece of paper.\n");
          move_object(clone_object("/wizards/rimber/cave/obj/stone.c"), this_player());
 move_object(paper, this_player());
 write("The box turns to dust when you take all from the box.\n");
          destruct(this_object());
          return 1;
         }
         return;
        }
        return;
}
get() {
        return 1;
}
short() {
        return "Small metallic box";
}
long() {
 write("The box is made of some light metal. Every corner\n"+
  "on the lid has been decorated with a picture of a tree.\n"+
  "The treetops make a square on the cover. There seems\n"+
  "to be a star in the center of the square.\n"+
  "On one side of the box there seems to be a small red hemisphere.\n");
}
