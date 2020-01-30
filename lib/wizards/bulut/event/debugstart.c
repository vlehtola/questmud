object ob1;
object ob2;
object ob3;
object ob4;
init() {
write("Type 'start' to begin the event.\n");
add_action("start", "start");
}

start() {
write("Ok, moving objects to their locations.\n");
ob1 = clone_object("/wizards/bulut/event/sign");
ob2 = clone_object("/wizards/bulut/event/pkmaster");
 if (!find_object("/wizards/bulut/event/pkobj")) {
ob3 = clone_object("/wizards/bulut/event/pkobj"); }
ob4 = clone_object("/wizards/bulut/event/pkevent");


move_object(ob1, "/wizards/bulut/workroom");
move_object(ob2, "/wizards/bulut/workroom");
move_object(ob4, "/wizards/bulut/event/entrance");
destruct(this_object());
return 1;
}                                           
