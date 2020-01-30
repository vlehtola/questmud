reset(arg) {
        if(arg) return;
}
id(str) { return str == "wagon"; }

init () { add_action("look", "look");
          add_action("pull", "pull"); }
look(str) {
    if(str == "at lever") {
    write("A small rusty lever which is propably used for the wagons brakes.\n");
   return 1; } }
pull(str) {
    if(str == "lever") {
    write("It's jammed.\n");
   return 1; } }
short() {return "A mining wagon"; }
long() {
write("Old and rusty mining wagon which is half full of little\n"+
     "pieces of rocks. A thick layer of dust covers the wagon.\n"+
     "There is a small lever on the right side of the wagon.\n");
}
