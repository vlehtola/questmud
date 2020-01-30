short() { return "You are falling down from the bridge."; }

long(str) {
	write("You are falling down from the bridge.\n");
	return;
}

kuolema(delay, ob) {
	call_out("loppu",delay,ob);
}

loppu(ob) {
	if(!ob->query_wiz()) {
	 tell_object(ob,"You hit the ground.\n");
	 ob->death();
	} else {
	 tell_object(ob,"At this point, a mortal would be dead!\n");
	}
	return 1;
}