object ob1;
object ob2;
object ob3;

init() {
ob3 = find_object("/wizards/bulut/event/pkobj");
destruct(ob3);
destruct(this_object());
}
