object ob, ob1;
void start_event() {
ob = clone_object("/wizards/neophyte/blink/eventmaster");
shout("A shepherd arrives to central square looking for his dog.\n");
shout("Maybe you should come too.\n");
move_object(ob, "/world/city/cs");
ob->start_count();
destruct(this_object());
}

start_blink() {
	ob1 = clone_object("/wizards/neophyte/blink/blinkdog");
	ob1->blink();
return 1;
}

void end_event() {
	write("You ended the event.\n");
	shout("The adventurer leaves the city leaving you empty handed.\n");
	find_object("wizards/neophyte/blink/eventmaster")->self_destruct();
}
